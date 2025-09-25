# IXpsSignatureManager::SavePackageToStream

## Description

Saves the XPS package by writing it to a stream.

## Parameters

### `stream` [in]

The stream to which the XPS package is written.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For return values that are not listed in this table, see [XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85)) and [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *stream* is **NULL**. |
| **XPS_E_PACKAGE_NOT_OPENED** | An XPS package has not yet been opened in the signature manager. |

## Remarks

If this method returns an **HRESULT** value that is not in the list of return values for this method, the signature manager should be released and recreated.

## See also

[IXpsSignatureManager](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturemanager)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85))

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))