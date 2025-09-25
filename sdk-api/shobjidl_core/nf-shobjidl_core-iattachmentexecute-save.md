# IAttachmentExecute::Save

## Description

Saves the attachment.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Before calling **IAttachmentExecute::Save**, you must call [IAttachmentExecute::SetLocalPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-setlocalpath) with a valid path. The file should be copied to that local path before **IAttachmentExecute::Save** is called.

**IAttachmentExecute::Save** should always be called if the local path declared in [IAttachmentExecute::SetLocalPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-setlocalpath) is not the path of a temporary directory.

**IAttachmentExecute::Save** may run virus scanners or other trust services to validate the file before saving it. Note that these services can delete or alter the file.

**IAttachmentExecute::Save** may attach [evidence](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-checkpolicy) to the local path in its NTFS alternate data stream (ADS).

## See also

[IAttachmentExecute](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iattachmentexecute)

[IAttachmentExecute::SaveWithUI](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-savewithui)