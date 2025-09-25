# D3D12_DXIL_LIBRARY_DESC structure

## Description

Describes a DXIL library state subobject that can be included in a state object.

## Members

### `DXILLibrary`

The library to include in the state object. Must have been compiled with library target 6.3 or higher. It is fine to specify the same library multiple times either in the same state object / collection or across multiple, as long as the names exported each time don’t conflict in a given state object.

### `NumExports`

The size of *pExports* array. If 0, everything gets exported from the library.

#### pExports

Optional exports array. For more information, see [D3D12_EXPORT_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_export_desc).

### `pExports`