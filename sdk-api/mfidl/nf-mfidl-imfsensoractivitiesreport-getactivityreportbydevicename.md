# IMFSensorActivitiesReport::GetActivityReportByDeviceName

## Description

Retrieves an [IMFSensorActivityReport](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensoractivityreport) based on the specified device name.

## Parameters

### `SymbolicName`

The symbolic name of the sensor for which the [IMFSensorActivityReport](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensoractivityreport) is retrieved.

### `sensorActivityReport` [out]

A pointer to the [IMFSensorActivityReport](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensoractivityreport) associated with the sensor with the specified symbolic name.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *symbolicName* parameter is null. |
| **E_POINTER** | The *sensorActivityReport* parameter is null. |
| **E_OUTOFMEMORY** | The system is out of memory. |
| **MF_E_INVALIDINDEX** | The *Index* parameter is not less than value returned by [GetCount](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsensoractivitiesreport-getcount). |
| **MF_E_NOT_FOUND** | No sensor with the specified symbolic name was found. |

## See also

[IMFSensorActivitiesReport](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensoractivitiesreport)

[IMFSensorActivityReport](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensoractivityreport)