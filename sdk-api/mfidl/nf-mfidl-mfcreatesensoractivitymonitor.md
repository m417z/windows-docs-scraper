# MFCreateSensorActivityMonitor function

## Description

Initializes a new instance of the [IMFSensorActivityMonitor](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensoractivitymonitor) interface.

## Parameters

### `pCallback` [in]

An implementation of the [IMFSensorActivitiesReportCallback](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensoractivitiesreportcallback) interface through which the system delivers [IMFSensorActivitiesReport](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensoractivitiesreport) objects.

### `ppActivityMonitor` [out]

A pointer to the new [IMFSensorActivityMonitor](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensoractivitymonitor).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *ppActivityMonitor* parameter is null. |