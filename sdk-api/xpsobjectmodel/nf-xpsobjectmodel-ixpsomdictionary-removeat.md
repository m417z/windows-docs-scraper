# IXpsOMDictionary::RemoveAt

## Description

Removes and releases the entry from a specified location in the dictionary.

## Parameters

### `index` [in]

The zero-based index in the dictionary from which an entry is to be removed and released.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

At the location specified by *index*, this method releases the interface referenced by the pointer. After releasing the interface, this method compacts the dictionary by reducing by 1 the index of each pointer subsequent to *index*.

The figure that follows illustrates how the dictionary is changed by the **RemoveAt** method.

![A figure that shows how RemoveAt removes an entry from the dictionary](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/dictionary_removeat.png)

## See also

[IXpsOMDictionary](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdictionary)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)