# ISceSvcAttachmentPersistInfo::IsDirty

## Description

The **IsDirty** method returns a value indicating whether data in the attachment snap-in has been modified since it was last saved.

## Parameters

### `lpTemplateName` [in]

Pointer to a null-terminated string that contains a security template name. Multiple security templates can be modified so that each service extension can be expanded under multiple templates.

## Return value

The return value is an HRESULT. A value of S_OK indicates the method was successful.

## See also

[ISceSvcAttachmentPersistInfo](https://learn.microsoft.com/windows/desktop/api/scesvc/nn-scesvc-iscesvcattachmentpersistinfo)

[ISceSvcAttachmentPersistInfo::Save](https://learn.microsoft.com/windows/desktop/api/scesvc/nf-scesvc-iscesvcattachmentpersistinfo-save)