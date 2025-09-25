# ITransferSource::LeaveFolder

## Description

Sends notification that a folder is no longer the destination of a file operation.

## Parameters

### `psiChildFolderDest` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) destination folder.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is called at the end of recursive file operations on a destination folder.

## See also

[ITransferSource](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itransfersource)

[ITransferSource::Advise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itransfersource-advise)

[ITransferSource::EnterFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itransfersource-enterfolder)

[ITransferSource::Unadvise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itransfersource-unadvise)