## Description

Copies the current Group Policy object (GPO) to the specified domain and then returns a pointer to the copy of
the GPO. This method copies the policy settings from the current GPO to the new GPO. The new GPO has a new GPO ID.
The new GPO gets either the default GPO
[access control lists](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-lists) (ACLs) or the ACLs from the
source GPO. The ACL that the new GPO gets depends on the value of the *lFlags* parameter.
This method does not link any scopes of management (SOMs) to the new GPO.

## Parameters

### `lFlags` [in]

Specifies the options to use for security principal and path mapping. For more information, see
[Copying and Importing GPOs Across Domains](https://learn.microsoft.com/previous-versions/windows/desktop/gpmc/copying-and-importing-gpos-across-domains).
The following options are defined.

#### 0

Map the security principal and the Universal Naming Convention (UNC) path from the migration table if
specified. If there is no entry corresponding to Security principal or UNCPath, keep the setting that contains the Security principal or UNC Path as it is. Do not copy security on the GPO and Software Installation Package objects. This is the default value of this parameter.

#### GPM_MIGRATIONTABLE_ONLY

Map the security principals and the UNC paths by using the information specified in the migration table
only. If a setting is found that cannot be mapped through the migration table, the method fails and returns an
error code.

#### GPM_PROCESS_SECURITY

Copy the specified permissions (DACLs) on the GPO.

### `pIGPMDomain` [in]

Domain to which the GPO is copied.

### `pvarNewDisplayName` [in, optional]

Display name for the copied GPO. A display name is assigned if the **VARIANT** structure does not contain a **BSTR** or if the *pvarNewDisplayName* parameter is **NULL**.

### `pvarMigrationTable` [in, optional]

Pointer to the [IGPMMigrationTable](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmmigrationtable) interface to use for mapping. This parameter can be **NULL**.

### `pvarGPMProgress` [in, optional]

Specifies a pointer to an
[IGPMAsyncProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasyncprogress) interface. This interface allows the client to receive status notifications about the progress of the copy operation. This parameter must be **NULL** if the client does not receive asynchronous notifications.

### `pvarGPMCancel` [out, optional]

Receives a pointer to an
[IGPMAsyncCancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasynccancel) interface that the client can use to cancel the copy operation. This parameter is not returned if *pvarGPMProgress* is **NULL**.

### `ppIGPMResult` [out]

Address of a pointer to the
[IGPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) interface that represents the result of the copy operation. That interface contains pointers to an
[IGPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo) interface and to an
[IGPMStatusMsgCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstatusmsgcollection) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a [GPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) object.

### VB

Returns a reference to a [GPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) object.

## Remarks

The new GPO that is created by using this method is unlinked because a copy operation does not transfer links.

You must check the code that is returned by the
[IGPMResult::OverallStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpmresult-overallstatus) method as well as the one returned by this method to determine whether the operation succeeded.
**OverallStatus** returns an overall status code for the operation. If no error occurred during the operation, it returns a success code. Otherwise, it returns a failure code.

An import operation is similar to a copy operation, except that in an import operation, the source GPO must be in the file system and the destination must be an existing GPO in Active Directory. In contrast, for a copy operation, the source GPO must be in Active Directory. A copy operation creates a new destination GPO. An import operation transfers only policy settings. An import operation does not modify the GPO ID or the
[ACLs](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-lists) on the destination GPO. And, an import operation does not modify any links that point to the destination GPO or to an associated Windows Management Instrumentation (WMI) filter. For more information about importing GPOs, see
[IGPMGPO::Import](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpmgpo-import).

For more information about security groups, see
[How Security Groups are Used in Access Control](https://learn.microsoft.com/windows/desktop/AD/how-security-groups-are-used-in-access-control) in the Active Directory Programmer's Guide.

## See also

[IGPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup)

[IGPMDomain](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmdomain)

[IGPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo)

[IGPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult)

[IGPMStatusMsgCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstatusmsgcollection)