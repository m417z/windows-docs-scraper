# ITransferSource::EnterFolder

## Description

Notifies that a folder is the destination of a file operation.

## Parameters

### `psiChildFolderDest` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) destination folder.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 This method is called when beginning to process a folder or subfolder in a recursive operation. For instance, when a source folder is copied to a destination folder, method **ITransferSource::EnterFolder** should be called with *psiChildFolderDest* set to the destination folder.

## See also

[ITransferSource](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itransfersource)

[ITransferSource::Advise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itransfersource-advise)

[ITransferSource::LeaveFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itransfersource-leavefolder)

[ITransferSource::Unadvise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itransfersource-unadvise)