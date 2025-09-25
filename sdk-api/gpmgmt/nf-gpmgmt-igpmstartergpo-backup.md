# IGPMStarterGPO::Backup

## Description

Creates a backup of the current Starter GPO.

## Parameters

### `bstrBackupDir` [in]

Name of the file system directory in which the **GPMStarterGPOBackup** object should be stored. The directory must already exist. Use a null-terminated string.

### `bstrComment` [in]

Comment to associate with the **GPMStarterGPOBackup** object.

### `pvarGPMProgress` [in, optional]

Specifies a pointer to an
[IGPMAsyncProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasyncprogress) interface that allows the client to receive status notifications about the progress of the backup operation. The method runs synchronously if this parameter is **NULL**. The method runs asynchronously if this parameter is not **NULL**. This parameter must be **NULL** if the client should not receive asynchronous notifications.

### `pvarGPMCancel` [out, optional]

Receives a pointer to an
[IGPMAsyncCancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasynccancel) interface that the client can use to cancel the backup operation. This parameter is not returned if *pvarGPMProgress* is **NULL**.

### `ppIGPMResult` [out]

Address of a pointer to the
[IGPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) interface representing the result of the backup operation. That interface contains pointers to an
[IGPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup) interface and an
[IGPMStatusMsgCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstatusmsgcollection) interface.

## Return value

Returns **S_OK** if successful. Returns a failure code if an error occurs.

For more information, see the following Remarks section.

## Remarks

Note that you must check the code returned by the
[IGPMResult::OverallStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpmresult-overallstatus) method as well as the one returned by this method to determine whether or not the operation succeeded.
**OverallStatus** returns an overall status code for the operation. If no error occurred during the operation, it returns a success code; otherwise it returns a failure code.

## See also

[IGPMStarterGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstartergpo)