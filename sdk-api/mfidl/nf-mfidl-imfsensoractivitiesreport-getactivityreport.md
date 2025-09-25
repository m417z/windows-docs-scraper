# IMFSensorActivitiesReport::GetActivityReport

## Description

Retrieves an [IMFSensorActivityReport](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensoractivityreport) based on the specified index.

## Parameters

### `Index` [in]

The index of the [IMFSensorActivityReport](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensoractivityreport) to retrieve. This value must be less than the value returned by [GetCount](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsensoractivitiesreport-getcount).

### `sensorActivityReport` [out]

A pointer to the [IMFSensorActivityReport](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensoractivityreport) associated with the specified index.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *sensorActivityReport* parameter is null. |
| **MF_E_INVALIDINDEX** | The *Index* parameter is not less than value returned by [GetCount](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsensoractivitiesreport-getcount). |

## See also

[IMFSensorActivitiesReport](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensoractivitiesreport)

[IMFSensorActivityReport](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensoractivityreport)