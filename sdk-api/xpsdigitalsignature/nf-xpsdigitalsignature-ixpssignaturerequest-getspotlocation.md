# IXpsSignatureRequest::GetSpotLocation

## Description

Gets the page and the location on the page where the visible digital signature or the digital signature request will be displayed.

## Parameters

### `pageIndex` [out]

The index value of the FixedPage part that contains the signature or the digital signature request. If a spot location is not specified for the signature request, –1 is returned.

### `pagePartName` [out]

A pointer to an [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface of the part that contains the FixedPage on which the digital signature is to be displayed.

### `x` [out]

The x-coordinate value of the signing spot on the page.

### `y` [out]

The y-coordinate value of the signing spot on the page.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For return values that are not listed in this table, see [XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85)) and [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *pageIndex*, *pagePartName*, *x*, or *y* is **NULL**. |
| **E_UNEXPECTED** | The interface is not connected to the signature manager. |

## Remarks

The location of the signing spot is specified in XPS units from the upper-left corner of the page. There are 96 XPS units per inch.

## See also

[IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi)

[IXpsSignatureManager](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturemanager)

[IXpsSignatureRequest](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturerequest)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85))

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))