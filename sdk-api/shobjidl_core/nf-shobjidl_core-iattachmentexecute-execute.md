# IAttachmentExecute::Execute

## Description

Executes an action on an attachment.

## Parameters

### `hwnd` [in]

Type: **HWND**

The handle of the parent window.

### `pszVerb` [in, optional]

Type: **LPCWSTR**

A pointer to a null-terminated string that contains a verb specifying the action to be performed on the file. See the *lpOperation* parameter in [ShellExecute](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecutea) for valid strings. This value can be **NULL**.

### `phProcess` [out, optional]

Type: **HANDLE***

A pointer to a handle to the source process, used for synchronous operation. This value can be **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Before calling **IAttachmentExecute::Execute**, [IAttachmentExecute::SetLocalPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-setlocalpath) must be called with a valid local path and the file must be copied to that location.

If a prompt is indicated, **IAttachmentExecute::Execute** calls [IAttachmentExecute::Prompt](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-prompt) using the [ATTACHMENT_ACTION_EXEC](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-attachment_action) value.

**IAttachmentExecute::Execute** may run virus scanners or other trust services to validate the file before executing it. Note that these services can delete or alter the file.

**IAttachmentExecute::Execute** may attach [evidence](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-checkpolicy) to the local path in its NTFS alternate data stream (ADS).

If *phProcess* is not **NULL**, **IAttachmentExecute::Execute** operates as a synchronous process and returns an **HPROCESS**, if available. If *phProcess* is **NULL**, **IAttachmentExecute::Execute** operates as an asynchronous process. This implies that the calling application has a message pump and a long-lived window.

If the handle pointed to by *phProcess* is non-**NULL** when the method returns, the calling application is responsible for calling [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) to free the handle when it is no longer needed.