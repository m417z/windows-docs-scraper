## Description

Restores a Group Policy object (GPO) from a
[GPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup) object. You can only restore a GPO to the domain in which the GPO was originally created because the operation restores the GPO with its original GPO ID, policy settings, [access control lists](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-lists) (ACLs), and links to Windows Management Instrumentation (WMI) filters.

## Parameters

### `pIGPMBackup` [in]

Pointer to the [GPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup) object to restore.

### `lDCFlags` [in]

Flags to use for validation. If this parameter is set to zero, the method validates the domain controller to determine whether the restore operation can be performed. If you specify **GPM_DONOT_VALIDATEDC**, the method does not validate the DC. This parameter is ignored for GPOs that do not include software policy settings. For more information about validation, see the "Remarks" section.

### `pvarGPMProgress` [in, optional]

Specifies a pointer to an
[IGPMAsyncProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasyncprogress) interface that allows the client to receive status notifications about the progress of the restore operation. To receive asynchronous notifications, the caller must create this interface and then pass the interface pointer in this parameter. This parameter must be **NULL** if the client should not receive asynchronous notifications. The method will run asynchronously if this parameter is not **NULL** and will run synchronously if **NULL**.

### `pvarGPMCancel` [out, optional]

Receives a pointer to an
[IGPMAsyncCancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasynccancel) interface that the client can use to cancel the restore operation. This parameter is not returned if *pvarGPMProgress* is **NULL**.

### `ppIGPMResult` [out]

Address of a pointer to the
[IGPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) interface that represents the result of the restore operation. That interface contains pointers to an
[IGPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo) interface and an
[IGPMStatusMsgCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstatusmsgcollection) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs. Returns **E_OPERATION_NOT_SUPPORTED_ONDC** if the current domain controller is running an old Windows Server version and the backed-up GPO contains software policy settings.

### JScript

Returns a reference to a [GPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) object.

### VB

Returns a reference to a [GPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) object.

## Remarks

A restore operation returns the contents of a specific GPO to the status it had when the backup was performed. A restore operation does not modify links to the GPO because they are attributes of a scope of management (SOM). A restore operation also does not modify WMI filters. However, because the link to a WMI filter is an attribute of the GPO, the restore operation restores the link to the WMI filter.

You must check the code that is returned by the
[IGPMResult::OverallStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpmresult-overallstatus) method as well as the one returned by this method to determine whether the operation succeeded.
**OverallStatus** returns an overall status code for the operation. If no error occurred during the operation, it returns a success code. Otherwise, it returns a failure code.

As a best practice, we recommend that you validate the DC in a restore operation.

## See also

[IGPMAsyncCancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasynccancel)

[IGPMAsyncProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasyncprogress)

[IGPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup)

[IGPMDomain](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmdomain)

[IGPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo)

[IGPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult)

[IGPMStatusMsgCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstatusmsgcollection)