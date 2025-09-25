# IXpsOMDashCollection::InsertAt

## Description

Inserts an [XPS_DASH](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_dash) structure at a specified location in the collection.

## Parameters

### `index` [in]

The zero-based index in the collection where the structure that is referenced by *dash* is to be inserted.

### `dash` [in]

A pointer to the [XPS_DASH](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_dash) structure that is to be inserted at the location specified by *index*.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

At the location specified by *index*, this method inserts the [XPS_DASH](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_dash) structure that is passed in *dash*. Prior to insertion, the structure in this and all subsequent locations is moved up by one index.

The figure that follows illustrates how the collection is changed by the **InsertAt** method.

![A figure that shows how InsertAt adds an entry to the dash collection](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/dashcollection_insertat.png)

## See also

[IXpsOMDashCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdashcollection)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS_DASH](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_dash)