WITH Data AS
(
SELECT
    Stream.body.messageid AS messageid,
    Stream.body.temperature AS temperature,
    Stream.body.humidity AS humidity
FROM IoTStream Stream
JOIN DeviceRulesBlob Ref ON Ref.DeviceType = 'Thermostat'
WHERE
     Ref.Temperature IS NOT null AND Stream.body.temperature > Ref.Temperature
)
SELECT
    Data.messageid,
    Data.temperature,
    Data.humidity
INTO AlertsQueue
FROM Data data