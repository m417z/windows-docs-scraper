# ISceSvcAttachmentData::Initialize

## Description

The **Initialize** method informs the Security Configuration snap-in that the snap-in extension is loaded, and it establishes a context for communications.

## Parameters

### `lpServiceName` [in]

String that specifies the name of the security service to retrieve information about.

### `lpTemplateName` [in]

String that specifies the name of the template.

### `lpSceSvcPersistInfo` [in]

Pointer to the
[ISceSvcAttachmentPersistInfo](https://learn.microsoft.com/windows/desktop/api/scesvc/nn-scesvc-iscesvcattachmentpersistinfo) interface of the attachment snap-in extension.

### `pscesvcHandle` [out]

Pointer that receives an
[SCESVC_HANDLE](https://learn.microsoft.com/windows/desktop/SecMgmt/scesvc-handle) that represents the communication context between the Security Configuration snap-in and the snap-in extension. This handle is passed in as a parameter to the other [ISceSvcAttachmentData](https://learn.microsoft.com/windows/desktop/api/scesvc/nn-scesvc-iscesvcattachmentdata) methods. When the attachment snap-in extension no longer needs this handle, free it by calling
[ISceSvcAttachmentData::CloseHandle](https://learn.microsoft.com/windows/desktop/api/scesvc/nf-scesvc-iscesvcattachmentdata-closehandle).

## Return value

The return value is an HRESULT. A value of S_OK indicates the method was successful.

## See also

[ISceSvcAttachmentData](https://learn.microsoft.com/windows/desktop/api/scesvc/nn-scesvc-iscesvcattachmentdata)

[ISceSvcAttachmentData::CloseHandle](https://learn.microsoft.com/windows/desktop/api/scesvc/nf-scesvc-iscesvcattachmentdata-closehandle)

[ISceSvcAttachmentPersistInfo](https://learn.microsoft.com/windows/desktop/api/scesvc/nn-scesvc-iscesvcattachmentpersistinfo)

[SCESVC_HANDLE](https://learn.microsoft.com/windows/desktop/SecMgmt/scesvc-handle)