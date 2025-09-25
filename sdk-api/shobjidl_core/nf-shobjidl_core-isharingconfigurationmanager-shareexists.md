# ISharingConfigurationManager::ShareExists

## Description

Queries whether the **Users** or **Public** folder is shared.

## Parameters

### `dsid` [in]

Type: **[DEF_SHARE_ID](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-def_share_id)**

One of the [DEF_SHARE_ID](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-def_share_id) values that indicates the folder whose sharing state is being checked.

## Return value

Type: **HRESULT**

S_OK if the folder is shared; otherwise, S_FALSE.

## Remarks

Because as of Windows 7 **Public** is shared in-place through **Users**, callers should always check for the Users share first. If a share is found to exist on **Users**, then it follows that a share exists on **Public** as well.