# ISceSvcAttachmentPersistInfo::Save

## Description

The **Save** method causes the snap-in extension to return information about the data that needs to be saved. The caller is responsible for saving the data.

## Parameters

### `lpTemplateName` [in]

Pointer to a null-terminated string that contains the security template name to save data to.

### `scesvcHandle` [in]

Pointer that receives the
[SCESVC_HANDLE](https://learn.microsoft.com/windows/desktop/SecMgmt/scesvc-handle) the attachment snap-in extension is using to communicate with the Security Configuration snap-ins.

### `ppvData` [out]

Pointer that receives a buffer that contains the data to be saved.

### `pbOverwriteAll` [out]

Pointer to a **BOOL** that receives a value indicating whether preexisting data should be overwritten.

## Return value

The return value is an HRESULT. A value of S_OK indicates the method was successful.

## Remarks

The caller should free the buffer set in *ppvData* by calling
[ISceSvcAttachmentPersistInfo::FreeBuffer](https://learn.microsoft.com/windows/desktop/api/scesvc/nf-scesvc-iscesvcattachmentpersistinfo-freebuffer).

## See also

[ISceSvcAttachmentPersistInfo](https://learn.microsoft.com/windows/desktop/api/scesvc/nn-scesvc-iscesvcattachmentpersistinfo)

[ISceSvcAttachmentPersistInfo::FreeBuffer](https://learn.microsoft.com/windows/desktop/api/scesvc/nf-scesvc-iscesvcattachmentpersistinfo-freebuffer)

[ISceSvcAttachmentPersistInfo::IsDirty](https://learn.microsoft.com/windows/desktop/api/scesvc/nf-scesvc-iscesvcattachmentpersistinfo-isdirty)

[SCESVC_HANDLE](https://learn.microsoft.com/windows/desktop/SecMgmt/scesvc-handle)