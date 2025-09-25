# ITransferSource::MoveItem

## Description

Moves the item within the volume/namespace, returning the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) in its new location.

## Parameters

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) to be moved.

### `psiParentDst` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that represents the new parent item at the destination.

### `pszNameDst` [in]

Type: **LPCWSTR**

Pointer to a null-terminated buffer that contains the destination path.

### `flags`

Type: **[TRANSFER_SOURCE_FLAGS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_transfer_source_flags)**

Flags that control the file operation. One or more of the [TRANSFER_SOURCE_FLAGS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_transfer_source_flags) constants.

### `ppsiNew` [out]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)****

When this method returns successfully, contains an address of a pointer to the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) in its new location.

## Return value

Type: **HRESULT**

Returns **S_OK** if the move succeeded. In that case, *ppsiNew* points to the address of the new item. Other possible return values, both success and failure codes, include the following:

| Return code | Description |
| --- | --- |
| **COPYENGINE_S_USER_IGNORED** | The destination item already exists and has not been overwritten. In this case, *ppsiNew* is **NULL** and the caller should delete the source item. |
| **COPYENGINE_S_MERGE** | The destination item already exists and the user has chosen to merge the source and destination folders. In this case, *ppsiNew* points to a **NULL** value and the caller should delete the source item. |
| **E_NOINTERFACE** | When the item being moved is a folder, the caller should convert a move operation into a copy and delete operation. |
| **ERROR_NOT_SAME_DEVICE** | The caller should convert a move operation into a copy and delete operation. This error is seen as `HRESULT_FROM_WIN32(ERROR_NOT_SAME_DEVICE)`. |
| **ERROR_FILE_EXISTS** | When moving a folder, the caller should convert the move operation into a copy and delete operation. The destination item must support [ITransferDestination](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itransferdestination). This error is seen as `HRESULT_FROM_WIN32(ERROR_FILE_EXISTS)`. |
| **ERROR_ALREADY_EXISTS** | When moving a folder, the caller should convert the move operation into a copy and delete operation. The destination item must support [ITransferDestination](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itransferdestination). This error is seen as `HRESULT_FROM_WIN32(ERROR_ALREADY_EXISTS)`. |