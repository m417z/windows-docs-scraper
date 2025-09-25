# IMFSensorActivityReport::GetSymbolicLink

## Description

Gets the symbolic link for the sensor associated with the report.

## Parameters

### `SymbolicLink` [out]

The string into which the sensor symbolic link is written.

### `cchSymbolicLink` [in]

The character count of the *SymbolicLink* string.

### `pcchWritten` [in, out]

Receives the number of characters that were written into the *SymbolicLink* string.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *pcchWritten* parameter is null. |

## See also

[IMFSensorActivityReport](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensoractivityreport)