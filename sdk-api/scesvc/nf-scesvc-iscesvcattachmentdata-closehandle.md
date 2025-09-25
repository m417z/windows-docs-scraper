# ISceSvcAttachmentData::CloseHandle

## Description

The **CloseHandle** method closes a handle opened during a previous call to
[ISceSvcAttachmentData::Initialize](https://learn.microsoft.com/windows/desktop/api/scesvc/nf-scesvc-iscesvcattachmentdata-initialize).

## Parameters

### `scesvcHandle` [in]

The
[SCESVC_HANDLE](https://learn.microsoft.com/windows/desktop/SecMgmt/scesvc-handle) to close.

## Return value

The return value is an **HRESULT**. A value of **S_OK** indicates the method was successful.

## Remarks

You should call this method when your attachment snap-in extension no longer requires the handle returned by
[ISceSvcAttachmentData::Initialize](https://learn.microsoft.com/windows/desktop/api/scesvc/nf-scesvc-iscesvcattachmentdata-initialize).

## See also

[ISceSvcAttachmentData](https://learn.microsoft.com/windows/desktop/api/scesvc/nn-scesvc-iscesvcattachmentdata)

[ISceSvcAttachmentData::Initialize](https://learn.microsoft.com/windows/desktop/api/scesvc/nf-scesvc-iscesvcattachmentdata-initialize)