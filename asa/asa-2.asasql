WITH Data AS
(
SELECT
    Stream.body.messageid AS messageid,
    Stream.body.temperature AS temperature,
    Stream.body.humidity AS humidity
    FROM IoTStream Stream
)
SELECT
    Data.messageid,
    Data.temperature,
    Data.humidity
INTO AlertsQueue
FROM Data data