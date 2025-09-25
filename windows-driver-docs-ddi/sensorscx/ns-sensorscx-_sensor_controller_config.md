# _SENSOR_CONTROLLER_CONFIG structure

## Description

This structure contains pointers to callback functions that must be implemented by the driver, and passed on to the class extension to call.

## Members

### `Size`

The allocated size of this structure (in bytes).

### `DriverIsPowerPolicyOwner`

Indicates whether or not driver owns the power policy. This value must be either WdfFalse, WdfUseDefault, or WdfTrue. For partners to take advantage of pep-based power management, they must set this flag to WdfFalse or WdfUseDefault and remove any _PSx method in their ACPI tables.

### `EvtSensorStart`

This callback function starts the sensor based on the default properties specified by the driver, or properties set by the class extension.

### `EvtSensorStop`

This callback function stops the sensor.

### `EvtSensorGetSupportedDataFields`

This callback function returns a list of data fields supported by the specified sensor.

### `EvtSensorGetDataFieldProperties`

This callback function returns the properties of a given data field associated with a sensor.

### `EvtSensorGetDataInterval`

This callback function returns the data interval for a specified sensor.

### `EvtSensorSetDataInterval`

This callback function sets the data interval for a specified sensor.

### `EvtSensorGetDataThresholds`

This callback function returns the thresholds that are associated with a sensor.

### `EvtSensorSetDataThresholds`

This callback function stops the sensor.

### `EvtSensorGetProperties`

This callback function returns the properties for a given sensor.

### `EvtSensorDeviceIoControl`

This callback function handles IOCTLs outside of the class extension.

**Note** If the driver needs to queue the IRP, it must copy the IRP to an IoQueue that the driver owns. This will prevent all IRPs for the driver to be stalled until completion.

### `EvtSensorStartHistory`

### `EvtSensorStopHistory`

### `EvtSensorClearHistory`

### `EvtSensorStartHistoryRetrieval`

### `EvtSensorCancelHistoryRetrieval`

### `EvtSensorSetBatchLatency`

This callback function sets the batch latency for a specified sensor.

### `EvtSensorStartStateChangeNotification`

### `EvtSensorStopStateChangeNotification`

### `EvtSensorEnableWake`

### `EvtSensorDisableWake`

## Remarks

This structure is given to the class extension using the [SensorsCxDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorscx/nf-sensorscx-sensorscxdeviceinitialize) function. If any of the following function pointers are not set, the driver will fail to load:

* EvtSensorStart
* EvtSensorStop
* EvtSensorGetSupportedDataFields
* EvtSensorGetDataFieldProperties
* EvtSensorGetDataInterval
* EvtSensorSetDataInterval
* EvtSensorGetDataThresholds
* EvtSensorSetDataThresholds
* EvtSensorGetProperties

Each function returns STATUS_SUCCESS when completed successfully.

**Note** The class extension (CX) only uses the NT_SUCCESS macro to determine if the call to the driver’s Evt function was successful, but does not take any action if the function failed or does not return STATUS_SUCCESS.