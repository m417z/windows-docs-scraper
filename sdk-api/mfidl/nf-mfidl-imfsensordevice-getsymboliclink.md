# IMFSensorDevice::GetSymbolicLink

## Description

Gets the symbolic link name of the sensor device.

## Parameters

### `SymbolicLink` [out]

Buffer of *cchSymbolicLink* characters where the symbolic link name will be written. The buffer must be large enough to account for the null terminator.

### `cchSymbolicLink` [in]

Number of characters available in *SymbolicLink* buffer.

### `pcchWritten` [out]

Output parameter containing the number of characters written to *SymbolicLink*. This includes the null terminator. If *SymbolicLink* is null and *cchSymbolicLink* is 0, *pcchWritten* will contain the number of characters needed (including the null terminator) to store the symbolic link name.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer provided in the *SymbolicLink* parameter is not large enough to contain the symbolic link name, including the null terminator. |
| **MF_E_NOT_INITIALIZED** | The sensor device has not been initialized. |

## Remarks

Depending on the type of device, which is defined by a member of the [MFSensorDeviceType](https://learn.microsoft.com/windows/win32/api/mfidl/ne-mfidl-mfsensordevicetype) enumeration and can be obtained by calling [GetDeviceType](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsensordevice-getdevicetype), the resulting symbolic name may be a valid device symbolic name or a provider URL. The caller should not attempt to parse the name and should treat it as opaque data.

## See also

[IMFSensorDevice](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensordevice)