# ID3D10Device::GetPredication

## Description

Get the rendering predicate state.

## Parameters

### `ppPredicate` [out]

Type: **[ID3D10Predicate](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10predicate)****

Address of a pointer to a predicate (see [ID3D10Predicate](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10predicate)). Value stored here will be **NULL** upon device creation.

### `pPredicateValue` [out]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Address of a boolean to fill with the predicate comparison value. **FALSE** upon device creation.

## Remarks

Any returned interfaces will have their reference count incremented by one. Applications should call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the returned interfaces when they are no longer needed to avoid memory leaks.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)