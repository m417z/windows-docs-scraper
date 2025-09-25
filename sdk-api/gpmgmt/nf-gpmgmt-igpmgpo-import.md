## Description

Imports the policy settings from the specified
[GPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup) object. An import operation transfers the policy settings from a backed-up GPO in the file system to a GPO in the Active Directory. The operation erases any previous policy settings in the destination GPO. The source GPO can be any backed-up GPO in the file system and the destination GPO must be an existing GPO in the Active Directory.

## Parameters

### `lFlags` [in]

Specifies the options to use for security principal and path mapping. The following options are defined. For more information, see
[Copying and Importing GPOs Across Domains](https://learn.microsoft.com/previous-versions/windows/desktop/gpmc/copying-and-importing-gpos-across-domains).

#### 0

Map the Security principal and UNC path from the migration table if specified. If there is no entry corresponding to Security principal or UNCPath, keep the setting containing that Security principal or UNC Path as it is. Do not copy security on the GPO and Software Installation Package objects. This is the default value for this parameter.

#### GPM_MIGRATIONTABLE_ONLY

Map the security principals and UNC paths using the information specified in the migration table only. If a setting is found that cannot be mapped through the migration table, the method fails and returns an error code.

### `pIGPMBackup` [in]

Pointer to the [GPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup) object from which settings should be imported.

### `pvarMigrationTable` [in, optional]

Pointer to a [IGPMMigrationTable](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmmigrationtable) to use for mapping. This parameter can be **NULL**.

### `pvarGPMProgress` [in, optional]

Specifies a pointer to an
[IGPMAsyncProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasyncprogress) interface that allows the client to receive status notifications about the progress of the import operation. This parameter must be **NULL** if the client should not receive asynchronous notifications.

### `pvarGPMCancel` [out, optional]

Receives a pointer to an
[IGPMAsyncCancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasynccancel) interface that the client can use to cancel the import operation. This parameter is not returned if *pvarGPMProgress* is **NULL**.

### `ppIGPMResult` [out]

Address of a pointer to the
[IGPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) interface representing the result of the import operation. That interface contains a pointer to an
[IGPMStatusMsgCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstatusmsgcollection) interface and an
[IGPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a [GPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) object.

### VB

Returns a reference to a [GPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) object.

## Remarks

An import operation only transfers policy settings. It erases any existing settings in the GPO. An import does not modify the GPO ID or the [ACLs](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-lists) on the destination GPO, nor does it modify any links that point to the destination GPO or to an associated WMI filter.

**Note** An import operation is similar but different than a copy operation. For an import operation, the source GPO must be in the file system and the destination must be an existing GPO in Active Directory. For a copy operation, the source GPO must be in the Active Directory and the copy creates a new destination GPO. For more information about copying GPOs, see
[IGPMGPO::CopyTo](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpmgpo-copyto).

Note that you must check the code returned by the
[IGPMResult::OverallStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpmresult-overallstatus) method as well as the one returned by this method to determine whether or not the operation succeeded.
**OverallStatus** returns an overall status code for the operation. If no error occurred during the operation, it returns a success code; otherwise it returns a failure code.

For more information about security groups, see
[How Security Groups are Used in Access Control](https://learn.microsoft.com/windows/desktop/AD/how-security-groups-are-used-in-access-control) in the Active Directory Programmer's Guide.

## See also

[IGPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup)

[IGPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo)

[IGPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult)

[IGPMStatusMsgCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstatusmsgcollection)