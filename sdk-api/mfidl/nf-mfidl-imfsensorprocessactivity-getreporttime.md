# IMFSensorProcessActivity::GetReportTime

## Description

Gets the time associated with the sensor activity report.

## Parameters

### `pft` [out]

Receives the time associated with the sensor activity report.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *pft* parameter is null. |

## See also

[IMFSensorProcessActivity](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorprocessactivity)