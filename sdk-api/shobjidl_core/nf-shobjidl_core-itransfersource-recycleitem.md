# ITransferSource::RecycleItem

## Description

Recycle the item into the provided recycle location and return the item in its new location.

## Parameters

### `psiSource` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) to be recycled.

### `psiParentDest` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) of the recycle location (the new parent of the item).

### `flags` [in]

Type: **[TRANSFER_SOURCE_FLAGS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_transfer_source_flags)**

The flags that control the file operation. One or more of the [TRANSFER_SOURCE_FLAGS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_transfer_source_flags) constants.

### `ppsiNewDest` [out]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)****

When the method returns, contains the address of a pointer to the recycled [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem).

## Return value

Type: **HRESULT**

Returns one of the following, or an error code.

| Return code | Description |
| --- | --- |
| **COPYENGINE_S_YES** | User responded "Yes" to the dialog. |
| **COPYENGINE_S_USER_RETRY** | User responded to retry the current action. |
| **COPYENGINE_S_USER_IGNORED** | User responded "No" to the dialog. |
| **COPYENGINE_S_DONT_PROCESS_CHILDREN** | Children items should not be processed. |
| **COPYENGINE_S_PENDING** | Error has been queued and will display later. |
| **COPYENGINE_E_USER_CANCELLED** | User canceled the current action. |
| **COPYENGINE_E_REQUIRES_ELEVATION** | Operation requires elevated privileges. |