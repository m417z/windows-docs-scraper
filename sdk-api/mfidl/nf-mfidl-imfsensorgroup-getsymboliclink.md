# IMFSensorGroup::GetSymbolicLink

## Description

Gets the symbolic link name of the sensor group.

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
| **MF_E_NOT_INITIALIZED** | The sensor group has not been initialized. |

## See also

[IMFSensorGroup](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorgroup)