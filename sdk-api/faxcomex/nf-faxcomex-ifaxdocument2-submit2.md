# IFaxDocument2::Submit2

## Description

Submits one or more documents to the fax service for processing.

**Note** This method is supported only in Windows Vista and later.

## Parameters

### `bstrFaxServerName` [in]

Type: **BSTR**

**BSTR** that specifies a fax server. If this parameter is **NULL** or an empty string, the local fax server is specified.

### `pvFaxOutgoingJobIDs` [out]

Type: **VARIANT***

**VARIANT** that specifies a collection of outbound job IDs, one for each recipient of the fax.

### `plErrorBodyFile` [out, retval]

Type: **LONG***

A **LONG** representing the zero-based position of the submitted file that caused the fax send operation to fail. See Remarks.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You must set the [IFaxDocument2::Bodies](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument2-bodies-vb) property with a semi-colon delimited list of the files to be faxed before calling **IFaxDocument2::Submit2**.

**Note** This [Body](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument-body-vb) property must be **NULL** to use **IFaxDocument2::Submit2**.

You must provide the server name when submitting the document. To submit the document to the local server, set the *bstrFaxServerName* parameter to **NULL** or an empty string. The method returns a collection of fax job IDs, one for each recipient of the fax.

To succeed, the **IFaxDocument2::Submit2** method requires that the fax has at least one recipient, and either a cover page or a fax body. You can only use this method if the server (remote or local) is installed as a network printer on the local computer.

This method is not supported for a remote connection to a fax server running Windows XP Home Edition or Windows XP Professional, and will return the error [FAX_E_NOT_SUPPORTED_ON_THIS_SKU](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-error-codes).

To use this method, a user must have the [far2SUBMIT_LOW](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum_2), [far2SUBMIT_NORMAL](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum_2), or [far2SUBMIT_HIGH](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum_2) access set correctly, depending on the [Priority](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument-priority-vb) of the fax document.

As an example of *plErrorBodyFile*, consider the following example: The following list of files is submitted as the value of [IFaxDocument2::Bodies](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument2-bodies-vb):

"MyTextFile.txt;AnotherTextFile.txt;MyPDFfile.pdf;MyWordFile.doc".

Because the "*.pdf" extension is not supported, the send operation will fail and *plErrorBodyFile* will return as 2.

## See also

[FaxDocument](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument)

[IFaxDocument2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdocument2)