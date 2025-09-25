# IXpsOMPath::SetAccessibilityShortDescription

## Description

Sets the short textual description of the object's contents. This description is used by accessibility clients to describe the object.

## Parameters

### `shortDescription` [in]

The short textual description of the object's contents.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

In the document markup, the value that is set in *shortDescription* will be that of the **AutomationProperties.Name** attribute of the **Path** element.

## See also

[IXpsOMPath](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompath)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)