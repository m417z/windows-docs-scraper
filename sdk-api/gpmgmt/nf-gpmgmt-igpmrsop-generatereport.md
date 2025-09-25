# IGPMRSOP::GenerateReport

## Description

The [GenerateReport](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpmbackup-generatereport) method generates a report on the RSoP data.

## Parameters

### `gpmReportType` [in]

Specifies whether the report is in XML or HTML.

### `pvarGPMProgress` [in, optional]

Pointer to an [IGPMAsyncProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasyncprogress) interface that allows the client to receive status notifications about the progress of report generation. If this parameter is not **NULL**, the call to **GenerateReport** is handled asynchronously. If this parameter is **NULL** the call to **GenerateReport** is handled synchronously and a pointer to a [IGPMAsyncCancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasynccancel) interface is returned in *pvarGPMCancel*. This parameter must be **NULL** if the client should not receive asynchronous notifications.

### `pvarGPMCancel` [out, optional]

Receives a pointer to an [IGPMAsyncCancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasynccancel) interface that the client can use to cancel the report generation. This parameter is not returned when *pvarGPMProgress* is **NULL**.

### `ppIGPMResult` [out]

Pointer to an [IGPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult). The **Result** property contains a binary string of XML or HTML. The [Status](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstatusmessage) property contains a reference to an [IGPMStatusMsgCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstatusmsgcollection).

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a [GPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) object.

### VB

Returns a reference to a [GPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) object.

## See also

[IGPMRSOP](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmrsop)