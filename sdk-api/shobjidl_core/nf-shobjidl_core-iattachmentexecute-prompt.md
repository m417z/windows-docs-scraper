# IAttachmentExecute::Prompt

## Description

Presents a prompt UI to the user.

## Parameters

### `hwnd` [in]

Type: **HWND**

A handle to the parent window.

### `prompt` [in]

Type: **[ATTACHMENT_PROMPT](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-attachment_prompt)**

A member of the [ATTACHMENT_PROMPT](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-attachment_prompt) enumeration that indicates what type of prompt UI to display to the user.

### `paction` [out]

Type: **[ATTACHMENT_ACTION](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-attachment_action)***

A member of the [ATTACHMENT_ACTION](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-attachment_action) enumeration that indicates the action to be performed upon user confirmation.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You must call [IAttachmentExecute::SetFileName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-setfilename) or [IAttachmentExecute::SetLocalPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-setlocalpath) before calling **IAttachmentExecute::Prompt**.

**IAttachmentExecute::Prompt** can be called by the application to force UI presentation before the file has been copied to disk.