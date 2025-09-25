# IXpsSignature::GetSigningTimeFormat

## Description

Gets the format of the signing time.

## Parameters

### `timeFormat` [out, retval]

The value of [OPC_SIGNATURE_TIME_FORMAT](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_signature_time_format) that describes the format of the signing time.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For return values that are not listed in this table, see [XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85)) and [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_UNEXPECTED** | The interface is not connected to the signature manager. |

## Remarks

For more information about the format of the date-time string that is returned in *timeFormat*, see [OPC_SIGNATURE_TIME_FORMAT](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_signature_time_format).

## See also

[IOpcDigitalSignature](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcdigitalsignature)

[IXpsSignature](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignature)

[IXpsSignatureManager](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturemanager)

[OPC_SIGNATURE_TIME_FORMAT](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_signature_time_format)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85))

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))