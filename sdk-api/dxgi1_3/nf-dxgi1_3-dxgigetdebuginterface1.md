# DXGIGetDebugInterface1 function

## Description

Retrieves an interface that Windows Store apps use for debugging the Microsoft DirectX Graphics Infrastructure (DXGI).

## Parameters

### `Flags`

Not used.

### `riid`

The globally unique identifier (GUID) of the requested interface type, which can be the identifier for the [IDXGIDebug](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nn-dxgidebug-idxgidebug), [IDXGIDebug1](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nn-dxgidebug-idxgidebug1), or [IDXGIInfoQueue](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nn-dxgidebug-idxgiinfoqueue) interfaces.

### `pDebug` [out]

A pointer to a buffer that receives a pointer to the debugging interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **DXGIGetDebugInterface1** function returns **E_NOINTERFACE** on systems without the Windows Software Development Kit (SDK) installed, because it's a development-time aid.

## See also

[DXGI Functions](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-functions)

[IDXGIDebug1](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nn-dxgidebug-idxgidebug1)