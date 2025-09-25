# IXpsOMDashCollection::SetAt

## Description

Replaces an [XPS_DASH](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_dash) structure at a specified location in the collection.

## Parameters

### `index` [in]

The zero-based index in the collection where an [XPS_DASH](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_dash) structure is to be replaced.

### `dash` [in]

A pointer to the [XPS_DASH](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_dash) structure that will replace the current contents at the location specified by *index*.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

At the location specified by *index*, this method frees the existing [XPS_DASH](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_dash) structure then replaces it with the structure that is passed in *dash*.

The figure that follows illustrates how the collection is changed by the **SetAt** method.

![A figure that shows how SetAt changes an entry in the dash collection](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/dashcollection_setat.png)

## See also

[IXpsOMDashCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdashcollection)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS_DASH](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_dash)