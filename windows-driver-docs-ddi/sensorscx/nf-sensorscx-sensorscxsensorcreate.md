# SensorsCxSensorCreate function

## Description

This function creates an instance of a sensor in the class extension.

## Parameters

### `FxDevice` [in]

A WDFDEVICE handle to the framework device object that represents the sensor.

### `pSensorAttributes` [in]

A reference to [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes).

### `pSensor` [out]

A reference to a sensor object that is used within the class extension.

## Return value

This function returns NTSTATUS with different values. Some values that may be returned are the following:

* STATUS_SUCCESS is returned when the function completes successfully.
* STATUS_INVALID_PARAMETER is returned if any of the _In_ parameters are NULL.
* STATUS_INSUFFICIENT_RESOURCES is returned if there were insufficient resources to allocate memory for this function.

## Remarks

SensorsCxSensorCreate is implemented by the class extension and must be called by the driver.

**Note** If pSensorAttributes->ParentObject is not set to NULL or FxDevice, then SensorsCxSensorCreate will fail. If pSensorAttributes->ParentObject is NULL, then the class extension (CX) will set it to FxDevice.

The sensors class extension writes a set of properties for each sensor when SensorsCxSensorCreate. For information about these properties, see Enumeration properties.

## See also

[Enumeration properties](https://learn.microsoft.com/windows-hardware/drivers/sensors/enumeration-properties)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)