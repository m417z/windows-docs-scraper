# SensorsCxSensorDataReady function

## Description

This function notifies the class extension that the driver has retrieved data.

## Parameters

### `Sensor` [in]

A reference to a sensor object.

### `pSensorData` [in]

A list of [sensor properties](https://learn.microsoft.com/windows-hardware/drivers/sensors/sensor-properties2). For more information, see [SENSOR_COLLECTION_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsdef/ns-sensorsdef-sensor_collection_list).

## Remarks

This function is implemented by the class extension and the driver must call it. When batch latency expires for sensor drivers that support data batching, **SensorsCxSensorDataReady** is called repeatedly until all the batched data samples are delivered to the client. For more information about the callback function related to batch latency, see [EvtSensorSetBatchLatency](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorscx/ns-sensorscx-_sensor_controller_config).

## See also

- [EvtSensorSetBatchLatency](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorscx/ns-sensorscx-_sensor_controller_config)
- [SENSOR_COLLECTION_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsdef/ns-sensorsdef-sensor_collection_list)
- [Sensor properties](https://learn.microsoft.com/windows-hardware/drivers/sensors/sensor-properties2)