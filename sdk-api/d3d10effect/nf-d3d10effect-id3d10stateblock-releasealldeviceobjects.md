# ID3D10StateBlock::ReleaseAllDeviceObjects

## Description

Release all references to device objects.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

Each time you return a pointer to an interface (by calling [ID3D10StateBlock::GetDevice](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10stateblock-getdevice)), the internal reference count is incremented; when you are finished using a stateblock, call this method to release all references and avoid a memory leak.

## See also

[ID3D10StateBlock Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10stateblock)