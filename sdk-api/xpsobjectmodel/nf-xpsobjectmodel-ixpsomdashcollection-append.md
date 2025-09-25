# IXpsOMDashCollection::Append

## Description

Appends an [XPS_DASH](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_dash) structure to the end of the collection.

## Parameters

### `dash` [in]

A pointer to the [XPS_DASH](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_dash) structure that is to be appended to the collection.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

The figure that follows illustrates how the collection is changed by the **Append** method.

![A figure that shows how Append adds an entry to the dash collection](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/dashcollection_append.png)

## See also

[IXpsOMDashCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdashcollection)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS_DASH](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_dash)