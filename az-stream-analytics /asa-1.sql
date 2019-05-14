SELECT
    Stream.DeviceID,
    Stream.SensorName
INTO AlertsQueue
FROM IoTStream Stream