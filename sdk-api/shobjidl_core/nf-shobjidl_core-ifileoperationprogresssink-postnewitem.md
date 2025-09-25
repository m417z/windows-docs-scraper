# IFileOperationProgressSink::PostNewItem

## Description

Performs caller-implemented actions after the new item is created.

## Parameters

### `dwFlags` [in]

Type: **DWORD**

bitwise value that contains flags that were used during the creation operation. Some values can be set or changed during the creation operation. See [TRANSFER_SOURCE_FLAGS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_transfer_source_flags) for flag descriptions.

### `psiDestinationFolder` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

Pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that specifies the destination folder to which the new item was added.

### `pszNewName` [in]

Type: **LPCWSTR**

Pointer to the file name of the new item, for instance **Newfile.txt**. This is a null-terminated, Unicode string.

### `pszTemplateName` [in]

Type: **LPCWSTR**

Pointer to the name of the template file (for example **Excel9.xls**) that the new item is based on, stored in one of the following locations:

* CSIDL_COMMON_TEMPLATES. The default path for this folder is %ALLUSERSPROFILE%\Templates.
* CSIDL_TEMPLATES. The default path for this folder is %USERPROFILE%\Templates.
* %SystemRoot%\shellnew

This is a null-terminated, Unicode string used to specify an existing file of the same type as the new file, containing the minimal content that an application wants to include in any new file.

This parameter is normally **NULL** to specify a new, blank file.

### `dwFileAttributes` [in]

Type: **DWORD**

The file attributes applied to the new item. One or more of the values found at [GetFileAttributes](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileattributesa).

### `hrNew` [in]

Type: **HRESULT**

The return value of the creation operation. Note that this is not the HRESULT returned by [NewItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-newitem), which simply queues the creation operation. Instead, this is the result of the actual creation.

### `psiNewItem` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

Pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that represents the new item.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise. In the case of an error value, all subsequent operations pending from the call to [IFileOperation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperation) are canceled.