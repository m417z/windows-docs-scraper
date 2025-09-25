# ISharingConfigurationManager::CreateShare

## Description

Shares the **Users** or **Public** folder. If the folder is already shared, this method updates its sharing status.

## Parameters

### `dsid` [in]

Type: **[DEF_SHARE_ID](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-def_share_id)**

One of the [DEF_SHARE_ID](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-def_share_id) values that indicates the folder to share or update.

### `role` [in]

Type: **[SHARE_ROLE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-share_role)**

One of the following [SHARE_ROLE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-share_role) values that sets the access permissions of the share for the *Everyone* ACE. **CreateShare** accepts only these values.

#### SHARE_ROLE_READER (0)

Read-only. The contents of the folder can be read, but not altered or added to.

#### SHARE_ROLE_CO_OWNER (2)

Read/Write. The contents of the folder can be read, changed, or added to.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *role* parameter specifies a value other than SHARE_ROLE_READER or SHARE_ROLE_CO_OWNER. |

## Remarks

Running this method requires an Administrator privilege level.

If the folder named in *dsid* is not shared, this method shares the folder using the permission level provided in the *role* parameter.

If the folder named in *dsid* is already shared, this method updates the permissions on the share with the value provided in the *role* parameter.

Because as of Windows 7 the **Public** folder is shared through **Users** rather than directly, creating a share on **Public** causes an Server Message Block (SMB) share to be created on **Users**.