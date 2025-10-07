# D3DXCheckVersion function

Verify that the version of D3DX you compiled with is the version that you are running.

## Parameters

*D3DSDKVersion* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Use D3D\_SDK\_VERSION. See remarks.

*D3DXSDKVersion* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Use D3DX\_SDK\_VERSION. See remarks.

## Return value

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Returns **TRUE** if the version of D3DX you compiled against is the version you are running with; otherwise, **FALSE** is returned.

## Remarks

Use this function during the initialization of your application like this:

```
HRESULT CD3DXMyApplication::Initialize(HINSTANCE hInstance,
  LPCSTR szWindowName, LPCSTR szClassName, UINT uWidth, UINT uHeight)
{
    HRESULT hr;

    if (!D3DXCheckVersion(D3D_SDK_VERSION, D3DX_SDK_VERSION))
        return E_FAIL;

    ...
}
```

Use [**Direct3DCreate9**](https://learn.microsoft.com/windows/win32/api/d3d9/nf-d3d9-direct3dcreate9) to verify that the correct runtime is installed.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9core.h |
| Library<br> | D3dx9.lib |

## See also

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-general-purpose)

