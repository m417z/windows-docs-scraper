# IMFSensorActivitiesReportCallback::OnActivitiesReport

## Description

Raised by the media pipeline when a new [IMFSensorActivitiesReport](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensoractivitiesreport) is available.

## Parameters

### `sensorActivitiesReport` [in]

Receives a pointer to the new [IMFSensorActivitiesReport](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensoractivitiesreport).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFSensorActivitiesReportCallback](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensoractivitiesreportcallback)