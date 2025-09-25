# IXpsSignature::GetSigningTime

## Description

Gets the date and time of signature creation.

## Parameters

### `sigDateTimeString` [out, retval]

A string that contains the date and time information.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For return values that are not listed in this table, see [XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85)) and [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_UNEXPECTED** | The interface is not connected to the signature manager. |

## Remarks

The date-time string returned in *sigDateTimeString* is in a W3C date-time format, which is described at [http://www.w3.org/TR/NOTE-datetime](https://www.w3.org/TR/NOTE-datetime.html).

To get the specific format of the date-time string that is returned in *sigDateTimeString*, call [GetSigningTimeFormat](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nf-xpsdigitalsignature-ixpssignature-getsigningtimeformat).

This method allocates the memory used by the string that is returned in *sigDateTimeString*. If *sigDateTimeString* is not **NULL**, use the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free the memory.

## See also

[IOpcDigitalSignature](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcdigitalsignature)

[IXpsSignature](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignature)

[IXpsSignatureManager](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturemanager)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85))

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))