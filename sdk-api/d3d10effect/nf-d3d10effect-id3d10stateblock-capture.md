# ID3D10StateBlock::Capture

## Description

Capture the current value of states that are included in a stateblock.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

Capture captures current values for states within an existing state block. It does not capture the entire state of the device. Creating an empty stateblock and calling Capture does nothing if no states have been set.

## See also

[ID3D10StateBlock Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10stateblock)