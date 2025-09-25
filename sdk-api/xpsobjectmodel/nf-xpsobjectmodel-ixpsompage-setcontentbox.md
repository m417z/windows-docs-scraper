# IXpsOMPage::SetContentBox

## Description

Sets the dimensions of the page's content box.

## Parameters

### `contentBox` [in]

The dimensions of the page's content box.

| *contentBox* field | Valid values |
| --- | --- |
| *contentBox.width* | Greater than or equal to 0.0 and less than or equal to (pageDimensions.width - contentBox.x). |
| *contentBox.height* | Greater than or equal to 0.0 and less than or equal to (pageDimensions.height - contentBox.y). |
| *contentBox.x* | Greater than or equal to 0.0 and less than pageDimensions.width. |
| *contentBox.y* | Greater than or equal to 0.0 and less than pageDimensions.height. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *contentBox* is **NULL**. |
| **XPS_E_INVALID_CONTENT_BOX** | The rectangle specified by *contentBox* contains one or more values that are not valid. |

## Remarks

The content box specifies where ink appears on the page.

The content box dimensions are not checked against the page dimensions until the page is serialized.

## See also

[IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_RECT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_rect)