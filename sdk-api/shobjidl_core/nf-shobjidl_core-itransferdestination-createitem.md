# ITransferDestination::CreateItem

## Description

Creates the specified file.

## Parameters

### `pszName` [in]

Type: **LPCWSTR**

A pointer to a null-terminated buffer that contains the name of the file relative to the current directory.

### `dwAttributes` [in]

Type: **DWORD**

One or more of the FILE_ATTRIBUTE flags defined in the [BY_HANDLE_FILE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/fileapi/ns-fileapi-by_handle_file_information) structure. The most significant value is FILE_ATTRIBUTE_DIRECTORY, which indicates that a folder should be created.

### `ullSize` [in]

Type: **ULONGLONG**

The size, in bytes, of the file to create. This value can be 0 if the size is unknown.

### `flags` [in]

Type: **[TRANSFER_SOURCE_FLAGS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_transfer_source_flags)**

Flags that control the file operation. One or more of the [TRANSFER_SOURCE_FLAGS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_transfer_source_flags) flags.

### `riidItem` [out]

Type: **REFIID**

A reference to the IID of the interface to retrieve through *ppvItem*, typically IID_IShellItem or another interface that derives from it.

### `ppvItem` [out]

Type: **void****

When this method returns, contains the interface pointer requested in *riidItem*. This is typically [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) or a derived interface.

### `riidResources` [in]

Type: **REFIID**

A reference to the IID of the interface to retrieve through *ppvResources*, typically IID_IShellItemResources or another interface that derives from it.

### `ppvResources` [out]

Type: **void****

When this method returns, contains the interface pointer requested in *riidResources*. This is typically [IShellItemResources](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemresources) or a derived interface.

## Return value

Type: **HRESULT**

Returns a success code if successful, or an error value otherwise. Success codes include:

* **S_OK**: The move succeeded and *ppvItem* and *ppvResources* both point to valid objects.
* **COPYENGINE_S_USER_IGNORED**: The destination item already exists and has not been overwritten. The values pointed to by *ppvItem* and *ppvResources* are **NULL**. If the caller is implementing a move as a copy and delete operation, the caller should complete the move by deleting the source item.

## Remarks

This method may be used to create a Shell item object representing the destination folder for a copy or move operation. The [ITransferSource](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itransfersource) interface provides methods to actually move objects of [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) to the destination.

Call [ITransferDestination::Advise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itransferdestination-advise) before calling any other [ITransferDestination](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itransferdestination) methods so the handler can callback on any errors that might occur. If not set, the handler should consider it an indication that no feedback is available and to do the "default" operation.

It is recommended that you use the **IID_PPV_ARGS** macro, defined in Objbase.h, to package the *riidResources* and *ppvResources* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppvResources*, which eliminates the possibility of a coding error.