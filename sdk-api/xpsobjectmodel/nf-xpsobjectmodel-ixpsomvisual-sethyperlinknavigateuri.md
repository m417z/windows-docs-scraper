# IXpsOMVisual::SetHyperlinkNavigateUri

## Description

Sets the destination URI of the visual's hyperlink.

## Parameters

### `hyperlinkUri` [in]

The [IUri](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775038(v=vs.85)) interface that contains the destination URI of the visual's hyperlink.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

Setting an object's URI makes the object a hyperlink. When activated or clicked, the object will navigate to the destination that is specified by the URI in *hyperlinkUri*.

## See also

[IUri](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775038(v=vs.85))

[IXpsOMVisual](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisual)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)