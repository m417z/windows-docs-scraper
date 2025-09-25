## Description

Incrementally add to an existing state object. This incurs lower CPU overhead than creating a state object from scratch that is a superset of an existing one (for example, adding a few more shaders).

## Parameters

### `pAddition`

Type: \_In\_ **const [D3D12_STATE_OBJECT_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_state_object_desc)\***

Description of state object contents to add to existing state object. To help generate this see the **CD3D12_STATE_OBJECT_DESC** helper in class in `d3dx12.h`.

### `pStateObjectToGrowFrom`

Type: \_In\_ **[ID3D12StateObject](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12stateobject)\***

Existing state object, which can be in use (for example, active raytracing) during this operation.

The existing state object must not be of type **Collection**.

### `riid`

Type: \_In\_ **REFIID**

Must be the IID of the [ID3D12StateObject](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12stateobject) interface.

### `ppNewStateObject`

Type: \_COM\_Outptr\_ **void\*\***

Returned state object.

Behavior is undefined if shader identifiers are retrieved for new shaders from this call and they are accessed via shader tables by any already existing or in-flight command list that references some older state object. Use of the new shaders added to the state object can occur only from commands (such as **DispatchRays** or **ExecuteIndirect** calls) recorded in a command list after the call to **AddToStateObject**.

## Return value

**S_OK** for success. **E_INVALIDARG**, **E_OUTOFMEMORY** on failure. The debug layer provides detailed status information.

## Remarks

For more info, see [AddToStateObject](https://microsoft.github.io/DirectX-Specs/d3d/Raytracing.html#addtostateobject).

## See also