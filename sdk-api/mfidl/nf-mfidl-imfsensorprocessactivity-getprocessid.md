# IMFSensorProcessActivity::GetProcessId

## Description

Gets the ID of the process with which the activity is associated.

## Parameters

### `pPID` [out]

Receives the process ID.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *pPID* parameter is null. |

## See also

[IMFSensorProcessActivity](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorprocessactivity)