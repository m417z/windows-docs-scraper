## Description

Restores the Starter Group Policy object (GPO) from a
[GPMStarterGPOBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstartergpobackup) object. You can restore a Starter GPO only to the domain in which the Starter GPO was originally created. This is because the operation restores the Starter GPO with its original Starter GPO ID and policy settings.

## Parameters

### `pIGPMTmplBackup` [in]

Pointer to the [GPMStarterGPOBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstartergpobackup) object to restore.

### `pvarGPMProgress` [in, optional]

Specifies a pointer to an
[IGPMAsyncProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasyncprogress) interface that allows the client to receive status notifications about the progress of the restore operation. The caller must create this interface and then pass the interface pointer in this parameter to receive asynchronous notifications. This parameter must be **NULL** if the client should not receive asynchronous notifications. The method runs asynchronously if this parameter is not **NULL**, and the method runs synchronously if **NULL**.

### `pvarGPMCancel` [out, optional]

Receives a pointer to an
[IGPMAsyncCancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasynccancel) interface that the client can use to cancel the restore operation. This parameter is not returned if *pvarGPMProgress* is **NULL**.

### `ppIGPMResult` [out]

Address of a pointer to the
[IGPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) interface that represents the result of the restore operation. That interface contains pointers to an
[IGPMstarterGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstartergpo) interface and to an
[IGPMStatusMsgCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstatusmsgcollection) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a [GPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) object.

### VB

Returns a reference to a [GPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) object.

## Remarks

A restore operation returns the contents of a specific GPO to the status it had when the backup was performed.

You must check the code that is returned by the
[IGPMResult::OverallStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpmresult-overallstatus) method as well as the one returned by this method to determine whether or not the operation succeeded.
**OverallStatus** returns an overall status code for the operation. If no error occurred during the operation, it returns a success code. Otherwise, it returns a failure code.

## See also

[IGPMDomain2](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmdomain2)