## Description

Creates an [ID3D12StateObject](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12stateobject).

## Parameters

### `pDesc` [in]

The description of the state object to create.

### `riid`

The GUID of the interface to create. Use *__uuidof(ID3D12StateObject)*.

### `ppStateObject` [out]

The returned state object.

## Return value

Returns S_OK if successful; otherwise, returns one of the following values:

* E_INVALIDARG if one of the input parameters is invalid.
* E_OUTOFMEMORY if sufficient memory is not available to create the handle.
* Possibly other error codes that are described in the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues) topic.

## See also

[ID3D12Device5](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device5)