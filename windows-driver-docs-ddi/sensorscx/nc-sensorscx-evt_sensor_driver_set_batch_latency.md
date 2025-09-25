# EVT_SENSOR_DRIVER_SET_BATCH_LATENCY callback function

## Description

This callback function sets the batch latency for a specified sensor.

## Parameters

### `Sensor` [in]

A reference to a sensor object.

### `BatchLatencyMs` [in]

The batch latency, expressed in milliseconds.

## Return value

This function returns STATUS_SUCCESS when completed successfully.

**Note** The class extension (CX) only uses the NT_SUCCESS macro to determine if the call to the driver’s Evt function was successful, but does not take any action if the function failed or does not return STATUS_SUCCESS.

## Remarks

The driver can set the batch latency to a value that is less than or equal to *BatchLatencyMs*, depending on buffer availability. For information about the sensor properties that a data batching sensor driver must report, see [Common sensor properties](https://learn.microsoft.com/windows-hardware/drivers/sensors/common-sensor-properties).

It is important to note that there is no change implied to sensor data delivery methods and events, due to data batching. When data batching latency expires, the driver will call [SensorsCxSensorDataReady](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorscx/nf-sensorscx-sensorscxsensordataready) repeatedly to deliver all the buffered data samples, one at a time. The data samples are sent, along with the timestamp information in their **PKEY_SensorData_Timestamp** data fields. The timestamp information (of data type VT_FILETIME) shows the time at which a sample was taken.

For more information about the VT_FILETIME data type, see [MSDN PROPVARIANT structure](https://learn.microsoft.com/windows/win32/api/propidlbase/ns-propidlbase-propvariant).

## See also

[MSDN PROPVARIANT structure](https://learn.microsoft.com/windows/win32/api/propidlbase/ns-propidlbase-propvariant)

[SensorsCxSensorDataReady](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorscx/nf-sensorscx-sensorscxsensordataready)