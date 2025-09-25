# ISharingConfigurationManager::GetSharePermissions

## Description

Gets the access permissions currently associated with the **User** or **Public** folder for the *Everyone* access control entry (ACE).

## Parameters

### `dsid` [in]

Type: **[DEF_SHARE_ID](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-def_share_id)**

One of the [DEF_SHARE_ID](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-def_share_id) values that specifies the folder.

### `pRole` [out]

Type: **[SHARE_ROLE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-share_role)***

A pointer to a value that, when this method returns successfully, receives one of the [SHARE_ROLE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-share_role) values that indicate the sharing permissions set for the folder specified in the *dsid* parameter.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.