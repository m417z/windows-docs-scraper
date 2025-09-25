# DXGIGetDebugInterface function

## Description

Retrieves a debugging interface.

## Parameters

### `riid`

The globally unique identifier (GUID) of the requested interface type.

### `ppDebug`

A pointer to a buffer that receives a pointer to the debugging interface.

## Return value

Returns S_OK if successful; an error code otherwise. For a list of error codes, see [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## Remarks

[IDXGIDebug](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nn-dxgidebug-idxgidebug) and [IDXGIInfoQueue](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nn-dxgidebug-idxgiinfoqueue) are debugging interfaces.

To access **DXGIGetDebugInterface**, call the [GetModuleHandle](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea) function to get Dxgidebug.dll and the [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) function to get the address of **DXGIGetDebugInterface**.**Windows 8.1:** Starting in Windows 8.1, Windows Store apps call the [DXGIGetDebugInterface1](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nf-dxgi1_3-dxgigetdebuginterface1) function to get an [IDXGIDebug1](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nn-dxgidebug-idxgidebug1) interface.

**Note** This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[DXGI Functions](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-functions)

[IDXGIDebug](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nn-dxgidebug-idxgidebug)