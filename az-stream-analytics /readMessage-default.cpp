bool readMessage(int messageId, char *payload)
{
    JSON_Value *root_value = json_value_init_object();
    JSON_Object *root_object = json_value_get_object(root_value);
    char *serialized_string = NULL;

    json_object_set_number(root_object, "messageId", messageId);

    float t = readTemperature();
    float h = readHumidity();
    bool temperatureAlert = false;
    if(t != temperature)
    {
        temperature = t;
        json_object_set_number(root_object, "temperature", temperature);
    }
    if(temperature > TEMPERATURE_ALERT)
    {
        temperatureAlert = true;
    }

    if(h != humidity)
    {
        humidity = h;
        json_object_set_number(root_object, "humidity", humidity);
    }

    serialized_string = json_serialize_to_string_pretty(root_value);

    snprintf(payload, MESSAGE_MAX_LEN, "%s", serialized_string);
    json_free_serialized_string(serialized_string);
    json_value_free(root_value);
    return temperatureAlert;
}