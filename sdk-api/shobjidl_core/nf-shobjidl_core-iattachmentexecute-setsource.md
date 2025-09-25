# IAttachmentExecute::SetSource

## Description

Sets an alternate path or URL for the source of a file transfer.

## Parameters

### `pszSource` [in]

Type: **LPCWSTR**

A pointer to a string containing the path or URL to use as the source.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The path or URL declared here is used as the primary zone determinant. The policy under which the attachment is handled is based partially on the perceived zone. If *pszSource* is **NULL**, the default is Restricted Zone.

Calling **IAttachmentExecute::SetSource** is optional.

The path or URL declared here can also be used in the prompt UI as the **From** field.

The path or URL declared here can also be sent to handlers that can process URLs.