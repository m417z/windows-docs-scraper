# IXpsOMCanvas::SetAccessibilityShortDescription

## Description

Sets the short textual description of the object's contents. This text is used by accessibility clients to describe the object.

## Parameters

### `shortDescription` [in]

The short textual description of the object's contents. A **NULL** pointer clears the previously assigned text.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

The property that is set by this method corresponds to the **AutomationProperties.HelpText** attribute of the **Canvas** element in the document markup.

## See also

[IXpsOMCanvas](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcanvas)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)