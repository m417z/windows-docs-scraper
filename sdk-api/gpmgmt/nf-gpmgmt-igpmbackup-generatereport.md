# IGPMBackup::GenerateReport

## Description

Gets the report for the backup Group Policy object (GPO).

## Parameters

### `gpmReportType` [in]

Specifies whether the report is in XML or HTML.

### `pvarGPMProgress` [in, optional]

Pointer to an [IGPMAsyncProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasyncprogress) interface. If *pvarGPMProgress* is **NULL**, the call to **GenerateReport** is handled synchronously. If not **NULL**, the call to **GenerateReport** is handled asynchronously, and *pvarGPMCancel* returns a pointer to [IGPMAsyncCancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasynccancel) .

### `pvarGPMCancel` [out, optional]

Pointer to an [IGPMAsyncCancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasynccancel) interface. A value for this parameter is returned only when *pvarGPMProgress* is specified and is not **NULL**.

### `ppIGPMResult` [out]

Pointer to an [IGPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) interface. The **Result** property contains a string of XML or HTML. The **Status** property contains a reference to an [IGPMStatusMsgCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstatusmsgcollection) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a [GPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) object.

### VB

Returns a reference to a [GPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) object.

## See also

[IGPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup)

[IGPMBackupCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackupcollection)

[IGPMBackupDir](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackupdir)