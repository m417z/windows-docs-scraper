# IAttachmentExecute::SetReferrer

## Description

Sets the security zone associated with the attachment file based on the referring file.

## Parameters

### `pszReferrer` [in]

Type: **LPCWSTR**

A pointer to a string containing the path of the referring file.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**IAttachmentExecute::SetReferrer** and [IAttachmentExecute::SetSource](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-setsource) have similar functionality. If both are set, the least-trusted zone of the two is used.

**IAttachmentExecute::SetReferrer** is used by container files to indicate indirect inheritance and avoid zone elevation. It can also be used with shortcut files to limit elevation based on parameters.

Calling **IAttachmentExecute::SetReferrer** is optional.

**IAttachmentExecute::SetReferrer** is only used to determine the security zone and its associated policies.