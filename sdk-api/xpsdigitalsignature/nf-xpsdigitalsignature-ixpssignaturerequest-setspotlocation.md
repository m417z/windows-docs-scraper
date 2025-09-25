# IXpsSignatureRequest::SetSpotLocation

## Description

Specifies the page and the location on the page where the visible digital signature or the digital signature request will be displayed.

## Parameters

### `pageIndex` [in]

The index value of the FixedPage part in the XPS document that contains the visible digital signature or the digital signature request.

If the value of this parameter is –1, a **SpotLocation** element will not be written to the SignatureDefinitions markup.

If the value of this parameter is not –1, it must be a page number that exists in the FixedDocument part to which the signature block that contains this request is attached.

### `x` [in]

The x-coordinate value of the signing spot on the page.

### `y` [in]

The y-coordinate value of the signing spot on the page.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For return values that are not listed in this table, see [XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85)) and [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_UNEXPECTED** | The interface is not connected to the signature manager. |

## Remarks

The location of the signing spot is specified in XPS units from the upper-left corner of the page. There are 96 XPS units per inch.

## See also

[IXpsSignatureBlock](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignatureblock)

[IXpsSignatureManager](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturemanager)

[IXpsSignatureRequest](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturerequest)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85))

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))