# CfReportSyncStatus function

## Description

Allows a sync provider to notify the platform of its status on a specified sync root without having to connect with a call to [CfConnectSyncRoot](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfconnectsyncroot) first.

## Parameters

### `SyncRootPath` [in, out]

Path to the sync root.

### `SyncStatus` [in]

The sync status to report; if `NULL`, clears the previously-saved sync status. For more information, see the [Remarks](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfreportsyncstatus#-remarks) section, below.

## Return value

If this function succeeds, it returns `S_OK`. Otherwise, it returns an **HRESULT** error code.

## Remarks

When a non-null [CF_SYNC_STATUS](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_sync_status) is provided in the *SyncStatus* parameter, the information will be remembered on the sync root until it is cleared explicitly by the sync provider or when the machine reboots. The platform will query this information upon any failed operations on a cloud file placeholder, using the following process:

1. The platform will first search for sync status at the file level.
2. If no sync status is found, the platform will then search for sync status registered at the sync root level, which is done through this function.
3. Once a sync status is located, the platform will use the information provided to construct a more meaningful and actionable message to the user.

**CfReportSyncStatus** clears the previously-saved sync status when being called with a `NULL` sync status. No change will be made to the existing sync status if the function call fails.

## See also

[CfConnectSyncRoot](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfconnectsyncroot)

[CF_SYNC_STATUS](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_sync_status)