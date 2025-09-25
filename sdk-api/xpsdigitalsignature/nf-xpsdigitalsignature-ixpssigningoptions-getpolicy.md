# IXpsSigningOptions::GetPolicy

## Description

Gets the [XPS_SIGN_POLICY](https://learn.microsoft.com/windows/win32/api/xpsdigitalsignature/ne-xpsdigitalsignature-xps_sign_policy) value that specifies the signing policy.

## Parameters

### `policy` [out, retval]

The logical **OR** of the [XPS_SIGN_POLICY](https://learn.microsoft.com/windows/win32/api/xpsdigitalsignature/ne-xpsdigitalsignature-xps_sign_policy) value that specifies the signing policy.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For return values that are not listed in this table, see [XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85)) and [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *policy* is **NULL**. |
| **E_UNEXPECTED** | The interface is not connected to the signature manager. |

## Remarks

If the [XPS_SIGN_POLICY](https://learn.microsoft.com/windows/win32/api/xpsdigitalsignature/ne-xpsdigitalsignature-xps_sign_policy) value is set but does not have a corresponding part in the package being signed, only the relationship type will be signed.

## See also

[IXpsSignatureManager](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturemanager)

[IXpsSigningOptions](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssigningoptions)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85))

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_SIGN_POLICY](https://learn.microsoft.com/windows/win32/api/xpsdigitalsignature/ne-xpsdigitalsignature-xps_sign_policy)