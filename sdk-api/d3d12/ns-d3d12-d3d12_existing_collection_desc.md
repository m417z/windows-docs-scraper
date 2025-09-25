# D3D12_EXISTING_COLLECTION_DESC structure

## Description

A state subobject describing an existing collection that can be included in a state object.

## Members

### `pExistingCollection`

The collection to include in a state object. The enclosing state object holds a reference to the existing collection.

### `NumExports`

Size of the *pExports* array. If 0, all of the collection’s exports get exported.

#### pExports

Optional exports array. For more information, see [D3D12_EXPORT_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_export_desc).

### `pExports`