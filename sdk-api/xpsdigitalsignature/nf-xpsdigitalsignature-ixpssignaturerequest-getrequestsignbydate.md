# IXpsSignatureRequest::GetRequestSignByDate

## Description

Gets the date and time before which the requested signer must sign the specified parts of the document.

## Parameters

### `dateString` [out, retval]

A string that contains the date and time before which the requested signer must sign the specified parts of the document.

The string is formatted as either `YYYY-MM-DDThh:mmZ`, which includes the UTC time zone offset, or `YYYY-MM-DDThh:mm`, which does not include the UTC time zone offset. For example, without the time zone offset, 7:30:29 P.M. on July 4, 2008 would be represented as `2008-07-04T19:30:29`.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For return values that are not listed in this table, see [XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85)) and [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *dateString* is **NULL**. |
| **E_UNEXPECTED** | The interface is not connected to the signature manager. |

## Remarks

This method allocates the memory used by the string that is returned in *dateString*. If *dateString* is not **NULL**, use the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free the memory.

## See also

[IXpsSignatureManager](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturemanager)

[IXpsSignatureRequest](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturerequest)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85))

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))