# IFileOperation::NewItem

## Description

Declares a new item that is to be created in a specified location.

## Parameters

### `psiDestinationFolder` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

Pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that specifies the destination folder that will contain the new item.

### `dwFileAttributes` [in]

Type: **DWORD**

A bitwise value that specifies the file system attributes for the file or folder. See [GetFileAttributes](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileattributesa) for possible values.

### `pszName` [in]

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

### `pfopsItem` [in]

Type: **[IFileOperationProgressSink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperationprogresssink)***

Pointer to an [IFileOperationProgressSink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperationprogresssink) object to be used for status and failure notifications. If you call [IFileOperation::Advise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-advise) for the overall operation, progress status and error notifications for the creation operation are included there, so set this parameter to **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method does not create the new item, it merely declares the item to be created. To create a new item, you must make at least the sequence of calls detailed here:

1. Call **IFileOperation::NewItem** to declare the specifics of the new file or folder.
2. Call [IFileOperation::PerformOperations](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-performoperations) to create the new item.

## See also

[IFileOperation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperation)

[PostNewItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperationprogresssink-postnewitem)

[PreNewItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperationprogresssink-prenewitem)