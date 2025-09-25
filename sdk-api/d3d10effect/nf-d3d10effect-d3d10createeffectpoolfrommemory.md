## Description

Create an effect pool (or shared memory location), to enable sharing variables between effects.

## Parameters

### `pData` [in]

Type: **void***

A pointer to a compiled effect.

### `DataLength` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

Length of *pData*.

### `FXFlags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

Effect [compile options](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-effect-constants).

### `pDevice` [in]

Type: **[ID3D10Device](https://learn.microsoft.com/windows/win32/api/d3d10/nn-d3d10-id3d10device)***

A pointer to the device (see [ID3D10Device Interface](https://learn.microsoft.com/windows/win32/api/d3d10/nn-d3d10-id3d10device)).

### `ppEffectPool` [out]

Type: **[ID3D10EffectPool](https://learn.microsoft.com/windows/win32/api/d3d10effect/nn-d3d10effect-id3d10effectpool)****

A pointer to the [ID3D10EffectPool Interface](https://learn.microsoft.com/windows/win32/api/d3d10effect/nn-d3d10effect-id3d10effectpool) that contains the effect pool.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

> [!NOTE]
> Linking `d3d10_1.lib` gives you the implementation in `d3d10_1.dll`, which is the Direct3D10.1 programming model implementation. Linking `d3d10.lib` gives you the implementation in `d3d10.dll`, which is the Direct3D10 programming model implementation.

A pool is a shared location in memory. Effect variables that are located in a pool can be updated once, and the effect system will take care of updating each effect that uses that variable. To pool an effect variable, tell the effect to locate the variable in a pool when the effect is created, using a helper function such as [D3DX10CreateEffectFromFile](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10createeffectfromfile).

For help compiling an effect, see [Compile an Effect (Direct3D 10)](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-programming-guide-effects-compile).

## See also

[Effect Functions (Direct3D 10)](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-effect-functions)