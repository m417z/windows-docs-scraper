# _WDF_DEVICE_INTERFACE_PROPERTY_DATA structure

## Description

[Applies to UMDF only]

The **WDF_DEVICE_INTERFACE_PROPERTY_DATA** structure describes a device interface property.

## Members

### `Size`

The size, in bytes, of this structure.

### `InterfaceClassGUID`

A pointer to a GUID that identifies the device interface class.

### `ReferenceString`

A pointer to a **UNICODE_STRING** structure that describes a reference
string for the device interface. This parameter is optional and can
be NULL.

### `PropertyKey`

A pointer to a **DEVPROPKEY** structure that specifies the device
property key.

### `Lcid`

Specifies a locale identifier. Set this parameter either to a language-specific LCID value or to **LOCALE_NEUTRAL**. The **LOCALE_NEUTRAL** LCID specifies that the property is language-neutral (that is, not specific to any language). Do not set this parameter to **LOCALE_SYSTEM_DEFAULT** or **LOCALE_USER_DEFAULT**. For more information about language-specific LCID values, see [LCID Structure](https://learn.microsoft.com/openspecs/windows_protocols/ms-lcid/63d3d639-7fd2-4afb-abbe-0d5b5551eef8).

### `Flags`

Not currently used. Set this member to zero.

## Remarks

The **WDF_DEVICE_INTERFACE_PROPERTY_DATA** structure is used as input to the following methods:

* [WdfDeviceAllocAndQueryInterfaceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceallocandqueryinterfaceproperty)
* [WdfDeviceAssignInterfaceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassigninterfaceproperty)
* [WdfDeviceQueryInterfaceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicequeryinterfaceproperty)

Drivers should initialize this structure by calling [WDF_DEVICE_INTERFACE_PROPERTY_DATA_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_device_interface_property_data_init).

#### Examples

For an example of how to use **WDF_DEVICE_INTERFACE_PROPERTY_DATA**, see [WdfDeviceAssignInterfaceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassigninterfaceproperty).

## See also

[WDF_DEVICE_INTERFACE_PROPERTY_DATA_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_device_interface_property_data_init)

[WdfDeviceAllocAndQueryInterfaceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceallocandqueryinterfaceproperty)

[WdfDeviceAssignInterfaceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassigninterfaceproperty)

[WdfDeviceQueryInterfaceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicequeryinterfaceproperty)