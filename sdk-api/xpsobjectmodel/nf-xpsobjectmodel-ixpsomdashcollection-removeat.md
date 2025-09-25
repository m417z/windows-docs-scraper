# IXpsOMDashCollection::RemoveAt

## Description

Removes and frees an [XPS_DASH](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_dash) structure from a specified location in the collection.

## Parameters

### `index` [in]

The zero-based index in the collection from which an [XPS_DASH](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_dash) structure is to be removed and freed.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

This method removes and frees the [XPS_DASH](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_dash) structure referenced by the pointer at the location specified by *index*. After freeing the structure, this method compacts the collection by reducing by 1 the index of each pointer subsequent to *index*.

The figure that follows illustrates how the collection is changed by the **RemoveAt** method.

![A figure that shows how RemoveAt removes an entry from the dash collection](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/dashcollection_removeat.png)

## See also

[IXpsOMDashCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdashcollection)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS_DASH](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_dash)