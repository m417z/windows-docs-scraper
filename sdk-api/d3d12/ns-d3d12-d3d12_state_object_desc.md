# D3D12_STATE_OBJECT_DESC structure

## Description

Description of a state object. Pass a value of this structure type to [ID3D12Device5::CreateStateObject](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device5-createstateobject).

## Members

### `Type`

The type of the state object.

### `NumSubobjects`

Size of the *pSubobjects* array.

### `pSubobjects`

An array of subobject definitions.