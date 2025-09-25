# IFaxDocument::ConnectedSubmit

## Description

The **IFaxDocument::ConnectedSubmit** method submits a single fax document to the connected [IFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver). The method returns an array of fax job ID strings, one for each recipient of the fax.

## Parameters

### `pFaxServer` [in]

Type: **IFaxServer***

An [IFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver) interface that specifies a connected fax server.

### `pvFaxOutgoingJobIDs` [out, retval]

Type: **VARIANT***

**VARIANT** that holds an array of outbound job ID strings, one for each recipient of the fax.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note** To succeed, the **IFaxDocument::ConnectedSubmit** method requires that the [IFaxDocument](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdocument) object have at least one recipient, and either a cover page or a fax body. You can only use this method if the server (remote or local) is installed as a network printer on the local computer.

This method is not supported for a remote connection to a fax server running Windows XP Home Edition or Windows XP Professional, and will return the error: [FAX_E_NOT_SUPPORTED_ON_THIS_SKU](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-error-codes).

To use this method, a user must have the [farSUBMIT_LOW](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum), [farSUBMIT_NORMAL](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum), or [farSUBMIT_HIGH](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right, depending on the [IFaxDocument::get_Priority](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument-priority-vb) of the fax document.

## See also

[IFaxDocument](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdocument)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-sending-a-fax)