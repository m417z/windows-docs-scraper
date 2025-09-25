# IAttachmentExecute::SaveWithUI

## Description

Presents the user with explanatory error UI if the save action fails.

## Parameters

### `hwnd` [in]

Type: **HWND**

The handle of the parent window.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**IAttachmentExecute::SaveWithUI** does not call [IAttachmentExecute::Prompt](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-prompt).

Before calling **IAttachmentExecute::SaveWithUI**, you must call [IAttachmentExecute::SetLocalPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-setlocalpath) with a valid path. The file is copied to that local path before **IAttachmentExecute::SaveWithUI** is called.

**IAttachmentExecute::SaveWithUI** may run virus scanners or other trust services to validate the file before saving it. Note that these services can delete or alter the file.

**IAttachmentExecute::SaveWithUI** may attach [evidence](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-checkpolicy) to the local path in its NTFS alternate data stream (ADS).

## See also

[IAttachmentExecute](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iattachmentexecute)

[IAttachmentExecute::Save](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-save)