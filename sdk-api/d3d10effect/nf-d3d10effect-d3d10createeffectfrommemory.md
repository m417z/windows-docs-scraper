## Description

Creates an ID3D10Effect from a buffer containing a compiled effect.

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

### `pEffectPool` [in]

Type: **[ID3D10EffectPool](https://learn.microsoft.com/windows/win32/api/d3d10effect/nn-d3d10effect-id3d10effectpool)***

Optional. A pointer to a memory space for effect variables that are shared across effects (see [ID3D10EffectPool Interface](https://learn.microsoft.com/windows/win32/api/d3d10effect/nn-d3d10effect-id3d10effectpool)).

### `ppEffect` [out]

Type: **[ID3D10Effect](https://learn.microsoft.com/windows/win32/api/d3d10effect/nn-d3d10effect-id3d10effect)****

A pointer to an [ID3D10Effect Interface](https://learn.microsoft.com/windows/win32/api/d3d10effect/nn-d3d10effect-id3d10effect) which contains the created effect.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

> [!NOTE]
> Linking `d3d10_1.lib` gives you the implementation in `d3d10_1.dll`, which is the Direct3D10.1 programming model implementation. Linking `d3d10.lib` gives you the implementation in `d3d10.dll`, which is the Direct3D10 programming model implementation.

This method is used to create an [ID3D10Effect Interface](https://learn.microsoft.com/windows/win32/api/d3d10effect/nn-d3d10effect-id3d10effect) object from an effect that has been compiled before runtime and loaded into memory. For help precompiling an effect, see [Offline Compiling](https://learn.microsoft.com/windows/win32/direct3dtools/dx-graphics-tools-fxc-using). To load and compile an ASCII .fx file see [Compile an Effect (Direct3D 10)](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-programming-guide-effects-compile).

## Examples

### Compile the effect

```
fxc.exe /T fx_4_0 /Fo Tutorial03.fxo Tutorial03.fx
```

### Load the compiled effect at runtime.

```
ifstream is("tutorial03.fxo", ios::binary);
is.seekg(0,ios_base::end);
streampos pos = is.tellg();
is.seekg(0,ios_base::beg);
char * effectBuffer = new char[pos];
is.read(effectBuffer,pos);
	
hr = D3D10CreateEffectFromMemory((void *)effectBuffer,pos,0,g_pd3dDevice,NULL,&g_pEffect);
```

## See also

[Effect Functions (Direct3D 10)](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-effect-functions)