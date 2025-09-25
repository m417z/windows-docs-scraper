# IXpsOMPage::SetBleedBox

## Description

Sets the dimensions of the page's bleed box.

## Parameters

### `bleedBox` [in]

The dimensions of the page's bleed box. This parameter must not be **NULL**.

A valid bleed box has the following properties:

####### x)) ≤ value )

####### y)) ≤ value )

###### 0)

###### 0)

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *bleedBox* is **NULL**. |
| **XPS_E_INVALID_BLEED_BOX** | The rectangle described by *bleedBox* contains one or more values that are not valid. |

## Remarks

The bleed box dimensions are not checked against the page dimensions until the page is serialized.

## See also

[IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_RECT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_rect)