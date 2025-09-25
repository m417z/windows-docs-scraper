# ITransferSource::RenameItem

## Description

Changes the name of an item, returning the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) with the new name.

## Parameters

### `psiSource` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) object to be renamed.

### `pszNewName` [in]

Type: **LPCWSTR**

A pointer to a null-terminated, Unicode string containing the new name.

### `flags` [in]

Type: **[TRANSFER_SOURCE_FLAGS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_transfer_source_flags)**

Flags that control the file operation. One or more of the [TRANSFER_SOURCE_FLAGS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_transfer_source_flags) constants.

### `ppsiNewDest` [out]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)****

When this method returns, contains the address of a pointer to the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) object.

## Return value

Type: **HRESULT**

Returns one of the following, or an error code.

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