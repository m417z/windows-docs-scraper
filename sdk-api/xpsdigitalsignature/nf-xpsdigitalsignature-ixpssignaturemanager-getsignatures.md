# IXpsSignatureManager::GetSignatures

## Description

Gets a pointer to an [IXpsSignatureCollection](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturecollection) interface that contains a collection of XPS digital signatures.

## Parameters

### `signatures` [out, retval]

A pointer to an [IXpsSignatureCollection](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturecollection) interface that contains a collection of XPS digital signatures.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For return values that are not listed in this table, see [XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85)) and [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *signatures* is **NULL**. |
| **XPS_E_PACKAGE_NOT_OPENED** | An XPS package has not yet been opened in the signature manager. |

## Remarks

The signature collection that is returned in *signatures* might include digital signatures that do not comply with the [XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification).

## See also

[IXpsSignatureCollection](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturecollection)

[IXpsSignatureManager](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturemanager)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85))

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))