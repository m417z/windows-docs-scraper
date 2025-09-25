# IAttachmentExecute::ClearClientState

## Description

Removes any stored state that is based on the client's GUID. An example might be a setting based on a checked box that indicates a prompt should not be displayed again for a particular file type.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

[IAttachmentExecute::SetClientGuid](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-setclientguid) must be called before using **IAttachmentExecute::ClearClientState**.