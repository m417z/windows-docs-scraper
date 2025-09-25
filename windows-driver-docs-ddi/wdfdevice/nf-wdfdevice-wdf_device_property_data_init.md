# WDF_DEVICE_PROPERTY_DATA_INIT function

## Description

[Applies to KMDF and UMDF]

The **WDF_DEVICE_PROPERTY_DATA_INIT** function initializes a driver's [WDF_DEVICE_PROPERTY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_property_data) structure.

## Parameters

### `PropertyData` [in]

A pointer to [WDF_DEVICE_PROPERTY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_property_data) structure.

### `PropertyKey` [in]

A pointer to a **DEVPROPKEY** structure that specifies the device property key.

## Remarks

Before calling the following methods, a driver must call **WDF_DEVICE_PROPERTY_DATA_INIT** to initialize a [WDF_DEVICE_PROPERTY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_property_data) structure.

* [WdfDeviceAllocAndQueryPropertyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceallocandquerypropertyex)
* [WdfDeviceAssignProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassignproperty)
* [WdfDeviceQueryPropertyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicequerypropertyex)
* [WdfFdoInitAllocAndQueryPropertyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitallocandquerypropertyex)
* [WdfFdoInitQueryPropertyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitquerypropertyex)

The **WDF_DEVICE_PROPERTY_DATA_INIT** function zeros the specified [WDF_DEVICE_PROPERTY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_property_data) structure and sets the structure's **Size** member. It also sets the structure's **PropertyKey** member to the specified value.

## See also

[WDF_DEVICE_PROPERTY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_property_data)

[WdfDeviceAllocAndQueryPropertyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceallocandquerypropertyex)

[WdfDeviceAssignProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassignproperty)

[WdfDeviceQueryPropertyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicequerypropertyex)

[WdfFdoInitAllocAndQueryPropertyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitallocandquerypropertyex)

[WdfFdoInitQueryPropertyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitquerypropertyex)