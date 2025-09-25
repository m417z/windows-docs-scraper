# ISyncMgrEnumItems::Reset

## Description

Instructs the enumerator to position itself at the beginning of the list of elements.

## Return value

Type: **HRESULT**

Return S_OK if the method succeeds.

## Remarks

There is no guarantee that the same set of elements are enumerated on each pass through the list, nor are the elements necessarily enumerated in the same order. The exact behavior depends on the collection being enumerated. The operation is too memory-intensive for some collections, such as files in a directory, to maintain a specific state.