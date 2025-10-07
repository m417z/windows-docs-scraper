# D3DX10CheckVersion function

Verify that the version of D3DX you compiled with is the version that you are running.

## Parameters

*D3DSdkVersion* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Use D3D10\_SDK\_VERSION. See remarks.

*D3DX10SdkVersion* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Use D3DX10\_SDK\_VERSION. See remarks.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the version doesn't match, the function will return FALSE (a number less than or equal to 0, the number itself has no meaning).

## Remarks

Use this function during the initialization of your application.

```
HRESULT hr;

if( FAILED( D3DX10CheckVersion(D3D10_SDK_VERSION, D3DX10_SDK_VERSION) ) )
    return E_FAIL;
```

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Core.h |
| Library<br> | D3DX10.lib |

## See also

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-general-purpose)

