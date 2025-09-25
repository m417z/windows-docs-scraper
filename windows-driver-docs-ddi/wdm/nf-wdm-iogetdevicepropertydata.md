# IoGetDevicePropertyData function

## Description

The **IoGetDevicePropertyData** routine retrieves the current setting for a device property.

## Parameters

### `Pdo` [in]

A pointer to the physical device object (PDO) for the device that is being queried.

### `PropertyKey` [in]

A pointer to a [DEVPROPKEY](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn315031(v=vs.85)) structure that specifies the device property key.

### `Lcid` [in]

A locale identifier. Set this parameter either to a language-specific LCID value or to **LOCALE_NEUTRAL**. The **LOCALE_NEUTRAL** LCID specifies that the property is language-neutral (that is, not specific to any language). Do not set this parameter to **LOCALE_SYSTEM_DEFAULT** or **LOCALE_USER_DEFAULT**. For more information about language-specific LCID values, see [LCID Structure](https://learn.microsoft.com/openspecs/windows_protocols/ms-lcid/63d3d639-7fd2-4afb-abbe-0d5b5551eef8).

### `Flags`

Reserved for system use. Drivers should set this value to 0.

### `Size` [in]

The size, in bytes, of the buffer that *Data* points to.

### `Data` [out]

A pointer to the device property data.

### `RequiredSize` [out]

A pointer to a ULONG to receive the size of the property information that is returned at *Data*. If **IoGetDevicePropertyData** returns STATUS_BUFFER_TOO_SMALL, the caller can use this value to allocate a buffer of the correct size.

### `Type` [out]

A pointer to a [DEVPROPTYPE](https://learn.microsoft.com/previous-versions/ff543546(v=vs.85)) value. If **IoGetDevicePropertyData** completes successfully, the routine uses *Type* to supply the type of data that is returned in the *Data* buffer.

## Return value

**IoGetDevicePropertyData** returns an NTSTATUS value. This routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation succeeded. The *Data* buffer contains the retrieved data. **Type* contains the type of the retrieved data. |
| **STATUS_BUFFER_TOO_SMALL** | The *Data* buffer is too small. **RequiredSize* contains the required buffer length. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | The specified device property was not found. |

## Remarks

Kernel-mode drivers use the **IoGetDevicePropertyData** routine to retrieve device properties that are defined as part of the unified device property model.

To see property types available for use by this routine, see [DEVPROP_TYPE_BYTE](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-byte) and adjacent pages for `DEVPROP_TYPE_*`.

Drivers can use the [IoSetDevicePropertyData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetdevicepropertydata) routine to modify a device property.

Callers of **IoGetDevicePropertyData** must be running at IRQL <= APC_LEVEL in the context of a system thread.

## See also

[DEVPROPKEY](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn315031(v=vs.85))

[DEVPROPTYPE](https://learn.microsoft.com/previous-versions/ff543546(v=vs.85))

[IoSetDevicePropertyData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetdevicepropertydata)