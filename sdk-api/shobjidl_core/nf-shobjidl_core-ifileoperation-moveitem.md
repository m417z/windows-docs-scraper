# IFileOperation::MoveItem

## Description

Declares a single item that is to be moved to a specified destination.

## Parameters

### `psiItem` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

Pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that specifies the source item.

### `psiDestinationFolder` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

Pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that specifies the destination folder to contain the moved item.

### `pszNewName` [in]

Type: **LPCWSTR**

Pointer to a new name for the item in its new location. This is a null-terminated Unicode string and can be **NULL**. If **NULL**, the name of the destination item is the same as the source.

### `pfopsItem` [in]

Type: **[IFileOperationProgressSink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperationprogresssink)***

Pointer to an [IFileOperationProgressSink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperationprogresssink) object to be used for progress status and error notifications for this specific move operation. If you call [IFileOperation::Advise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-advise) for the overall operation, progress status and error notifications for the move operation are included there, so set this parameter to **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method does not move the item, it merely declares the item to be moved. To move an object, you must make at least the sequence of calls detailed here:

1. Call **IFileOperation::MoveItem** to declare the source item, destination folder, and destination name.
2. Call [IFileOperation::PerformOperations](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-performoperations) to begin the move operation.

## See also

[IFileOperation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperation)

[IFileOperation::MoveItems](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-moveitems)

[PostMoveItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperationprogresssink-postmoveitem)

[PreMoveItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperationprogresssink-premoveitem)