# IGPMGPO::GenerateReport

## Description

Gets the report for a GPO.

## Parameters

### `gpmReportType` [in]

Specifies whether the report is in XML or HTML.

### `pvarGPMProgress` [in, optional]

Pointer to an [IGPMAsyncProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasyncprogress) interface that allows the client to receive status notifications about the progress of the copy operation. If not **NULL**, the call to [GenerateReport](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpmbackup-generatereport) is handled asynchronously and *pvarGPMCancel* receives a pointer to an [IGPMAsyncCancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasynccancel) interface. If this parameter is **NULL** the call to **GenerateReport** is handled synchronously. The *pvarGPMProgress* parameter must be **NULL** if the client should not receive asynchronous notifications.

### `pvarGPMCancel` [out, optional]

Receives a pointer to an [IGPMAsyncCancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasynccancel) interface that the client can use to cancel the copy operation. This parameter is not returned if *pvarGPMProgress* is **NULL**.

### `ppIGPMResult` [out]

Pointer to an [IGPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) interface. The **Result** property contains a binary string of XML or HTML. The **Status** property contains a reference to an [IGPMStatusMsgCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstatusmsgcollection) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a [GPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) object.

### VB

Returns a reference to a [GPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) object.

## See also

[IGPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo)