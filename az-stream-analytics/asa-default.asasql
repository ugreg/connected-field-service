WITH AlertData AS
(
SELECT
     Stream.DeviceID,
     'Temperature' AS ReadingType,
     Stream.Temperature AS Reading,
     Stream.EventToken AS EventToken,
     Ref.Temperature AS Threshold,
     Ref.TemperatureRuleOutput AS RuleOutput,
     Stream.EventEnqueuedUtcTime AS [Time]
FROM IoTStream Stream
JOIN DeviceRulesBlob Ref ON Ref.DeviceType = 'Thermostat'
WHERE
     Ref.Temperature IS NOT null AND Stream.Temperature > Ref.Temperature
)

SELECT data.DeviceId,
    data.ReadingType,
    data.Reading,
    data.EventToken,
    data.Threshold,
    data.RuleOutput,
    data.Time
INTO AlertsQueue
FROM AlertData data
WHERE LAG(data.DeviceID) OVER (PARTITION BY data.DeviceId, data.Reading, data.ReadingType LIMIT DURATION(minute, 1)) IS NULL