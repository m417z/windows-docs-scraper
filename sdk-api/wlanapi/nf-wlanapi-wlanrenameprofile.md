# WlanRenameProfile function

## Description

The **WlanRenameProfile** function renames the specified profile.

## Parameters

### `hClientHandle` [in]

The client's session handle, obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `pInterfaceGuid` [in]

The GUID of the interface.

### `strOldProfileName` [in]

The profile name to be changed.

### `strNewProfileName` [in]

The new name of the profile.

### `pReserved`

Reserved for future use. Must be set to **NULL**.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID PARAMETER** | *hClientHandle* is **NULL** or not valid, *pInterfaceGuid* is **NULL**, *strOldProfileName* is **NULL**, *strNewProfileName* is **NULL**, or *pReserved* is not **NULL**. |
| **ERROR_INVALID_HANDLE** | The handle *hClientHandle* was not found in the handle table. |
| **ERROR_NOT_FOUND** | The profile specified by *strOldProfileName* was not found in the profile store. |
| **ERROR_ACCESS_DENIED** | The caller does not have sufficient permissions to rename the profile. |
| **ERROR_NOT_SUPPORTED** | This function was called from an unsupported platform. This value will be returned if this function was called from a Windows XP with SP3 or Wireless LAN API for Windows XP with SP2 client. |
| **RPC_STATUS** | Various error codes. |

## See also

[WlanDeleteProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlandeleteprofile)

[WlanGetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofile)

[WlanSetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofile)