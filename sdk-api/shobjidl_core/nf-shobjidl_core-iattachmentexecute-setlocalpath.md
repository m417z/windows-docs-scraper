# IAttachmentExecute::SetLocalPath

## Description

Sets and stores the path to the file.

## Parameters

### `pszLocalPath` [in]

Type: **LPCWSTR**

A pointer to a string that contains the local path where the attachment file is to be stored.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Calling **IAttachmentExecute::SetLocalPath** is required.

When the attachment is approved for execution by the user (either through policy or prompt), the path specified by this method is used. If only [IAttachmentExecute::SetFileName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-setfilename) was called before calling [IAttachmentExecute::CheckPolicy](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-checkpolicy) and [IAttachmentExecute::Prompt](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-prompt), that trust could be revoked if the assumed local path was different from that set by **IAttachmentExecute::SetLocalPath**. Trust can be granted by various Zone APIs, antivirus services, file type information, policies as well as other system trust providers.

**IAttachmentExecute::SetLocalPath** must be called before calling [IAttachmentExecute::Execute](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-execute).

## See also

[IAttachmentExecute](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iattachmentexecute)

[IAttachmentExecute::SetFileName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-setfilename)