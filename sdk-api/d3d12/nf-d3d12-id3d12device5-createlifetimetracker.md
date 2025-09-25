## Description

Creates a lifetime tracker associated with an application-defined callback; the callback receives notifications when the lifetime of a tracked object is changed.

## Parameters

### `pOwner` [in]

Type: **[ID3D12LifetimeOwner](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12lifetimeowner)\***

A pointer to an **ID3D12LifetimeOwner** interface representing the application-defined callback.

### `riid` [in]

Type: **REFIID**

A reference to the interface identifier (IID) of the interface to return in *ppvTracker*.

### `ppvTracker` [out]

Type: **void\*\***

A pointer to a memory block that receives the requested interface pointer to the created object.

## Return value

## Remarks

## See also