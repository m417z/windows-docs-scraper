# ISceSvcAttachmentPersistInfo::FreeBuffer

## Description

The **FreeBuffer** method frees memory allocated by the attachment snap-in extension.

## Parameters

### `pvData` [in]

Pointer to the buffer to free.

## Return value

The return value is an HRESULT. A value of S_OK indicates the method was successful.

## Remarks

You should call this method to free the data buffer returned by
[ISceSvcAttachmentPersistInfo::Save](https://learn.microsoft.com/windows/desktop/api/scesvc/nf-scesvc-iscesvcattachmentpersistinfo-save).

## See also

[ISceSvcAttachmentPersistInfo](https://learn.microsoft.com/windows/desktop/api/scesvc/nn-scesvc-iscesvcattachmentpersistinfo)

[ISceSvcAttachmentPersistInfo::Save](https://learn.microsoft.com/windows/desktop/api/scesvc/nf-scesvc-iscesvcattachmentpersistinfo-save)