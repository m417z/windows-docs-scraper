# IXpsOMPath::SetSnapsToPixels

## Description

Sets a Boolean value that indicates whether the path will be snapped to device pixels when that path is being rendered.

## Parameters

### `snapsToPixels` [in]

A Boolean value that indicates whether to snap the path to the device pixels when that path is being rendered. The following table describes the values possible for this parameter.

| Value | Meaning |
| --- | --- |
| **TRUE** | Snap the path to the device pixels. |
| **FALSE** | Do not snap the path to the device pixels. |

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## See also

[IXpsOMPath](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompath)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)