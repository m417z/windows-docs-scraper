# IGPMGPO::Backup

## Description

Backs up a Group Policy object (GPO) to the specified directory. A backup operation transfers the contents of a GPO from the Active Directory directory service to the file system. The backup includes the policy settings, the GPO ID, and any
[access control lists](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-lists) (ACLs) that are associated with the GPO. This method is also used for exporting GPOs to the file system.

## Parameters

### `bstrBackupDir` [in]

Name of the file system directory in which the [GPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup) object should be stored. The directory must already exist.

### `bstrComment` [in]

Comment to associate with the [GPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup) object.

### `pvarGPMProgress` [in, optional]

Specifies a pointer to an
[IGPMAsyncProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasyncprogress) interface that allows the client to receive status notifications about the progress of the backup operation. The method runs synchronously if this parameter is **NULL**. The method runs asynchronously if this parameter is not **NULL**. This parameter must be **NULL** if the client should not receive asynchronous notifications.

### `pvarGPMCancel` [out, optional]

Receives a pointer to an
[IGPMAsyncCancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasynccancel) interface that the client can use to cancel the backup operation. This parameter is not returned if *pvarGPMProgress* is **NULL**.

### `ppIGPMResult` [out]

Address of a pointer to the
[IGPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) interface that represents the result of the backup operation. That interface contains pointers to an
[IGPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup) interface and to an
[IGPMStatusMsgCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstatusmsgcollection) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a [GPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) object.

### VB

Returns a reference to a [GPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) object.

## Remarks

A GPO that has been backed-up (also called exported) can be restored to the Active Directory by calling the
[IGPMDomain::RestoreGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpmdomain-restoregpo) method or imported into another existing GPO using the
[IGPMGPO::Import](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpmgpo-import) method, depending on the required result.

You must check the code that is returned by the
[IGPMResult::OverallStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpmresult-overallstatus) method as well as the one that is returned by this method to determine whether the operation succeeded.
**OverallStatus** returns an overall status code for the operation. If no error occurred during the operation, it returns a success code. Otherwise, it returns a failure code.

## See also

[IGPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup)

[IGPMDomain](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmdomain)

[IGPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo)

[IGPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult)

[IGPMStatusMsgCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstatusmsgcollection)