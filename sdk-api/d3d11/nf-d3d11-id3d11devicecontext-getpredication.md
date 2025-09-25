# ID3D11DeviceContext::GetPredication

## Description

Get the rendering predicate state.

## Parameters

### `ppPredicate` [out, optional]

Type: **[ID3D11Predicate](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11predicate)****

Address of a pointer to a predicate (see [ID3D11Predicate](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11predicate)). Value stored here will be **NULL** upon device creation.

### `pPredicateValue` [out, optional]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Address of a boolean to fill with the predicate comparison value. **FALSE** upon device creation.

## Remarks

Any returned interfaces will have their reference count incremented by one. Applications should call IUnknown::Release on the returned interfaces when they are no longer needed to avoid memory leaks.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)