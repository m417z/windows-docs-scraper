# IoSetDeviceInterfacePropertyData function

## Description

The **IoSetDeviceInterfacePropertyData** routine modifies the current value of a [device interface property](https://learn.microsoft.com/windows-hardware/drivers/install/accessing-device-interface-properties).

## Parameters

### `SymbolicLinkName` [in]

A pointer to a string that identifies the device interface instance. This string was obtained from a previous call to the [IoGetDeviceInterfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceinterfaces), [IoGetDeviceInterfaceAlias](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceinterfacealias), or [IoRegisterDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdeviceinterface) routine.

### `PropertyKey` [in]

A pointer to a [DEVPROPKEY](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn315031(v=vs.85)) structure that contains the device interface property key.

### `Lcid` [in]

Specifies a locale identifier. Set this parameter either to a language-specific LCID value or to **LOCALE_NEUTRAL**. The **LOCALE_NEUTRAL** LCID specifies that the property is language-neutral (that is, not specific to any language). Do not set this parameter to **LOCALE_SYSTEM_DEFAULT** or **LOCALE_USER_DEFAULT**. For more information about language-specific LCID values, see [LCID Structure](https://learn.microsoft.com/openspecs/windows_protocols/ms-lcid/63d3d639-7fd2-4afb-abbe-0d5b5551eef8).

### `Flags` [in]

Set this parameter to **PLUGPLAY_PROPERTY_PERSISTENT** if the property value set by this routine should persist across computer restarts. Otherwise, set *Flags* to zero.

### `Type` [in]

Set this parameter to the [DEVPROPTYPE](https://learn.microsoft.com/previous-versions/ff543546(v=vs.85)) value that specifies the type of the data that is supplied in the *Data* buffer.

### `Size` [in]

Specifies the size, in bytes, of the buffer that *Data* points to.

### `Data` [in, optional]

A pointer to the device interface property data. Set this parameter to **NULL** to delete the specified property. If *Data* is non-**NULL**, the routine stores an internal copy of the property value. The buffer pointed to by *Data* does not need to remain valid after the call returns.

## Return value

**IoSetDeviceInterfacePropertyData** returns STATUS_SUCCESS if the call was successful. Possible error return values include the following status codes.

| Return code | Description |
|--|--|
| **STATUS_UNSUCCESSFUL** | The specified LCID value is not valid. |
| **STATUS_NOT_IMPLEMENTED** | The specified property is not supported. |

## Remarks

Kernel-mode drivers use the **IoSetDeviceInterfacePropertyData** routine to modify device interface properties that are defined as part of the [unified device property model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-). For more information about device interface properties, see [Device Properties](https://learn.microsoft.com/windows-hardware/drivers/image/device-properties).

Drivers can use the [IoGetDeviceInterfacePropertyData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceinterfacepropertydata) routine to obtain the current value for a device interface property.

Callers of **IoSetDeviceInterfacePropertyData** must be running at IRQL <= APC_LEVEL in the context of a system thread.

## See also

[DEVPROPKEY](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn315031(v=vs.85))

[DEVPROPTYPE](https://learn.microsoft.com/previous-versions/ff543546(v=vs.85))

[IoGetDeviceInterfacePropertyData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceinterfacepropertydata)