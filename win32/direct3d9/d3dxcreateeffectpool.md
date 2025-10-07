# D3DXCreateEffectPool function

Create an effect pool. A pool is used to share parameters between effects.

## Parameters

*ppPool* \[out\]

Type: **[**LPD3DXEFFECTPOOL**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxeffectpool)\***

Returns a pointer to the created pool.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the method succeeds, the return value is S\_OK.

If the arguments are invalid, the method will return D3DERR\_INVALIDCALL.

If the method fails, the return value will be E\_FAIL.

## Remarks

For effects within a pool, shared parameters with the same name share values.

## Requirements

| Requirement | Value |
|--------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3DX9Effect.h |
| Library<br> | D3dx9.lib |

## See also

[Effect Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-effects-functions)

