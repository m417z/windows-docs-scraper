# IFaxDocument::Submit

## Description

The **IFaxDocument::Submit** method submits a single fax document to the fax service for processing.

## Parameters

### `bstrFaxServerName` [in]

Type: **BSTR**

**BSTR** that specifies a fax server. If this parameter is **NULL** or an empty string, the local fax server is specified.

### `pvFaxOutgoingJobIDs`

Type: **VARIANT***

**VARIANT** that specifies a collection of outbound job IDs, one for each recipient of the fax.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You must provide the server name when submitting the document. To submit the document to the local server, set the *bstrFaxServerName* parameter to **NULL** or an empty string. The method returns a collection of fax job IDs, one for each recipient of the fax.

To succeed, the **IFaxDocument::Submit** method requires that the [IFaxDocument](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdocument) interface have at least one recipient, and either a cover page or a fax body. You can only use this method if the server (remote or local) is installed as a network printer on the local computer.

This method is not supported for a remote connection to a fax server running Windows XP Home Edition or Windows XP Professional, and will return the error [FAX_E_NOT_SUPPORTED_ON_THIS_SKU](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-error-codes).

To use this method, a user must have the [farSUBMIT_LOW](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum), [farSUBMIT_NORMAL](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum), or [farSUBMIT_HIGH](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right, depending on the [Priority](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument-priority-vb) of the fax document.

## See also

[FaxDocument](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument)

[IFaxDocument](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdocument)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-broadcasting-a-fax)