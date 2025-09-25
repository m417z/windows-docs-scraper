# IMFSensorActivitiesReport::GetCount

## Description

Gets the count of [IMFSensorActivityReport](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensoractivityreport) objects that are available to be retrieved.

## Parameters

### `pcCount` [out]

The count of [IMFSensorActivityReport](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensoractivityreport) objects that are available to be retrieved.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *pcCount* parameter is null. |

## See also

[IMFSensorActivitiesReport](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensoractivitiesreport)

[IMFSensorActivityReport](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensoractivityreport)