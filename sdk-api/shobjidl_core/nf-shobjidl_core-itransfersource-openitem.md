# ITransferSource::OpenItem

## Description

Opens the item for copying. Returns an object that can be enumerated for resources ([IShellItemResources](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemresources)).

## Parameters

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) to be opened.

### `flags` [in]

Type: **[TRANSFER_SOURCE_FLAGS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_transfer_source_flags)**

The flags that control the file operation. One or more of the [TRANSFER_SOURCE_FLAGS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_transfer_source_flags) constants.

### `riid` [out]

Type: **REFIID**

A reference to the IID (the interface ID or GUID) of the interface to return in *ppv*. This should be an [IShellItemResources](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemresources) or an interface derived from **IShellItemResources**.

### `ppv` [out]

Type: **void****

When this method returns, contains the address of a pointer to the interface specified by *riid*.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or one of the following specific Shell codes, or a system error code.

| Return code | Description |
| --- | --- |
| **COPYENGINE_S_YES** | User responded "Yes" to the dialog. |
| **COPYENGINE_S_USER_RETRY** | User responded to retry the current action. |
| **COPYENGINE_S_USER_IGNORED** | User responded "No" to the dialog. |
| **COPYENGINE_S_MERGE** | User responded to merge folders. |
| **COPYENGINE_S_USER_RETRY_WITH_NEW_NAME** | User responded to retry the file with new name. |
| **COPYENGINE_S_DONT_PROCESS_CHILDREN** | Child items should not be processed. |
| **COPYENGINE_S_PENDING** | Error has been queued and will display later. |
| **COPYENGINE_E_USER_CANCELLED** | User canceled the current action. |
| **COPYENGINE_E_REQUIRES_ELEVATION** | Operation requires elevated privileges. |