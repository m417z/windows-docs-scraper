# IXpsOMDictionary::GetByKey

## Description

Gets the [IXpsOMShareable](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomshareable) interface pointer of the entry that contains the specified key.

## Parameters

### `key` [in]

The entry's key to be found in the dictionary.

### `beforeEntry` [in]

The [IXpsOMShareable](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomshareable) interface pointer to the last entry in the dictionary which is to be searched for *key*. If *beforeEntry* is **NULL** or is an interface pointer to an entry that is not in the dictionary, the entire dictionary will be searched.

### `entry` [out, retval]

The interface pointer to the dictionary entry whose key matches *key*.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

The interface pointers stored in a dictionary will usually point to interfaces, such as [IXpsOMBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsombrush) and [IXpsOMVisual](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisual), that are derived from the [IXpsOMShareable](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomshareable) interface. To determine the interface type, call the [IXpsOMShareable::GetType](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomshareable-gettype) method.

## See also

[IXpsOMDictionary](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdictionary)

[IXpsOMShareable](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomshareable)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)