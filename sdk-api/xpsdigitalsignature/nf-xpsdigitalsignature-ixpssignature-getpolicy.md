# IXpsSignature::GetPolicy

## Description

Gets the [XPS_SIGN_POLICY](https://learn.microsoft.com/windows/win32/api/xpsdigitalsignature/ne-xpsdigitalsignature-xps_sign_policy) value that represents the signing policy used when the signature is created.

## Parameters

### `policy` [out, retval]

The logical **OR** of the [XPS_SIGN_POLICY](https://learn.microsoft.com/windows/win32/api/xpsdigitalsignature/ne-xpsdigitalsignature-xps_sign_policy) values that represent the signing policy.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For return values that are not listed in this table, see [XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85)) and [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *policy* is **NULL**. |
| **E_UNEXPECTED** | The interface is not connected to the signature manager. |

## Remarks

The signing policy value that is returned in *policy* is determined by examining the signed parts and relationships in the document.

This method deduces the signature policy by examining the list of signed parts and relationships.
For example, the **XPS_SIGN_POLICY_DISCARD_CONTROL** flag is set if the discard-control relationship type from the XPS package root is signed.

## See also

[IXpsSignature](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignature)

[IXpsSignatureManager](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturemanager)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85))

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_SIGN_POLICY](https://learn.microsoft.com/windows/win32/api/xpsdigitalsignature/ne-xpsdigitalsignature-xps_sign_policy)