# IXpsOMPage::SetIsHyperlinkTarget

## Description

Specifies whether the page is the target of a hyperlink.

## Parameters

### `isHyperlinkTarget` [in]

The Boolean value that indicates whether the page is the target of a hyperlink.

| Value | Meaning |
| --- | --- |
| TRUE | The page is the target of a hyperlink. |
| FALSE | The page is not the target of a hyperlink. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_MISSING_NAME** | The page has not been named. The hyperlink target status can only be set if the page has a name. |

## Remarks

Only those pages that have this property set to **TRUE** will be included in the hyperlink targets that are collected by [IXpsOMPageReference::CollectLinkTargets](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompagereference-collectlinktargets).

## See also

[IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))