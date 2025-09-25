# IoGetDeviceInterfacePropertyData function

## Description

The **IoGetDeviceInterfacePropertyData** routine retrieves the current value of a [device interface property](https://learn.microsoft.com/windows-hardware/drivers/install/accessing-device-interface-properties).

## Parameters

### `SymbolicLinkName` [in]

A pointer to a string that identifies the device interface instance. This string was obtained from a previous call to the [IoGetDeviceInterfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceinterfaces), [IoGetDeviceInterfaceAlias](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceinterfacealias), or [IoRegisterDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdeviceinterface) routine.

### `PropertyKey` [in]

A pointer to a [DEVPROPKEY](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn315031(v=vs.85)) structure that contains the device interface property key.

### `Lcid` [in]

Specifies a locale identifier. Set this parameter either to a language-specific LCID value or to **LOCALE_NEUTRAL**. The **LOCALE_NEUTRAL** LCID specifies that the property is language-neutral (that is, not specific to any language). Do not set this parameter to **LOCALE_SYSTEM_DEFAULT** or **LOCALE_USER_DEFAULT**. For more information about language-specific LCID values, see [LCID Structure](https://learn.microsoft.com/openspecs/windows_protocols/ms-lcid/63d3d639-7fd2-4afb-abbe-0d5b5551eef8).

### `Flags`

Reserved for system use. Drivers should set this value to zero.

### `Size` [in]

Specifies the size, in bytes, of the buffer that *Data* points to.

### `Data` [out]

A pointer to a caller-allocated buffer into which the routine writes the device interface property data.

### `RequiredSize` [out]

A pointer to a ULONG variable into which **IoGetDeviceInterfacePropertyData** writes the required size of the property data. If the routine succeeds, the required size value is the number of bytes that the routine writes to the output buffer that *Data* points to. If the routine returns STATUS_BUFFER_TOO_SMALL, the required size value is the size of the buffer that the caller should allocate for this property value.

### `Type` [out]

A pointer to a [DEVPROPTYPE](https://learn.microsoft.com/previous-versions/ff543546(v=vs.85)) variable. If **IoGetDeviceInterfacePropertyData** successfully retrieves the property data, the routine writes the property type value to this variable. This value indicates the type of property data that is in the *Data* buffer.

## Return value

**IoGetDeviceInterfacePropertyData** returns STATUS_SUCCESS if it is successful. Possible error return values include the following status codes.

| Return code | Description |
|--|--|
| **STATUS_BUFFER_TOO_SMALL** | The buffer that *Data* points to is too small to contain the property data. \**RequiredSize* contains the required buffer length. |
| **STATUS_UNSUCCESSFUL** | The specified LCID value is not valid. |
| **STATUS_NOT_IMPLEMENTED** | The specified property is not supported. |

## Remarks

Kernel-mode drivers use the **IoGetDeviceInterfacePropertyData** routine to retrieve device interface properties that are defined as part of the [unified device property model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-). For more information about device interface properties, see [Device Properties](https://learn.microsoft.com/windows-hardware/drivers/image/device-properties).

Drivers can use the [IoSetDeviceInterfacePropertyData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetdeviceinterfacepropertydata) routine to modify a device interface property.

Callers of **IoGetDeviceInterfacePropertyData** must be running at IRQL = PASSIVE_LEVEL in the context of a system thread.

## See also

[DEVPROPKEY](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn315031(v=vs.85))

[DEVPROPTYPE](https://learn.microsoft.com/previous-versions/ff543546(v=vs.85))

[IoSetDeviceInterfacePropertyData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetdeviceinterfacepropertydata)