# ISharingConfigurationManager::DeleteShare

## Description

Removes sharing from either the **Users** or **Public** folder.

## Parameters

### `dsid` [in]

Type: **[DEF_SHARE_ID](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-def_share_id)**

One of the [DEF_SHARE_ID](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-def_share_id) values that specifies the folder to no longer share.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Running this method requires an Administrator privilege level.