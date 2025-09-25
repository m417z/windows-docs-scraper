# _WDF_DEVICE_PROPERTY_DATA structure

## Description

[Applies to KMDF and UMDF]

The **WDF_DEVICE_PROPERTY_DATA** structure describes a device property.

## Members

### `Size`

The size, in bytes, of this structure.

### `PropertyKey`

A pointer to a [DEVPROPKEY](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn315031(v=vs.85)) structure that specifies the device
property key.

### `Lcid`

Specifies a locale identifier. Set this parameter either to a language-specific LCID value or to **LOCALE_NEUTRAL**. The **LOCALE_NEUTRAL** LCID specifies that the property is language-neutral (that is, not specific to any language). Do not set this parameter to **LOCALE_SYSTEM_DEFAULT** or **LOCALE_USER_DEFAULT**. For more information about language-specific LCID values, see [LCID Structure](https://learn.microsoft.com/openspecs/windows_protocols/ms-lcid/63d3d639-7fd2-4afb-abbe-0d5b5551eef8).

### `Flags`

Set to **PLUGPLAY_PROPERTY_PERSISTENT** if this property value is being set by [WdfDeviceAssignProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassignproperty). Otherwise, set this member to zero.

## Remarks

The **WDF_DEVICE_PROPERTY_DATA** structure is used as input to the following methods:

* [WdfDeviceAllocAndQueryPropertyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceallocandquerypropertyex)
* [WdfDeviceAssignProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassignproperty)
* [WdfDeviceQueryPropertyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicequerypropertyex)
* [WdfFdoInitAllocAndQueryPropertyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitallocandquerypropertyex)
* [WdfFdoInitQueryPropertyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitquerypropertyex)

Drivers should initialize this structure by calling [WDF_DEVICE_PROPERTY_DATA_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_device_property_data_init).

## See also

[WDF_DEVICE_PROPERTY_DATA_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_device_property_data_init)

[WdfDeviceAllocAndQueryPropertyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceallocandquerypropertyex)

[WdfDeviceAssignProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassignproperty)

[WdfDeviceQueryPropertyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicequerypropertyex)

[WdfFdoInitAllocAndQueryPropertyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitallocandquerypropertyex)

[WdfFdoInitQueryPropertyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitquerypropertyex)