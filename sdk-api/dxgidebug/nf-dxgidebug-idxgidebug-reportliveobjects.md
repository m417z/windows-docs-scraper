## Description

Reports info about the lifetime of an object or objects.

See the [Memory management sample](https://github.com/microsoft/DirectX-Graphics-Samples/tree/master/TechniqueDemos/D3D12MemoryManagement).

## Parameters

### `apiid`

The globally unique identifier (GUID) of the object or objects to get info about. Use one of the [DXGI_DEBUG_ID](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-debug-id) GUIDs.

### `flags`

A [DXGI_DEBUG_RLO_FLAGS](https://learn.microsoft.com/windows/desktop/api/dxgidebug/ne-dxgidebug-dxgi_debug_rlo_flags)-typed value that specifies the amount of info to report.

## Return value

Returns S_OK if successful; an error code otherwise. For a list of error codes, see [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## Remarks

**Note** This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[IDXGIDebug](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nn-dxgidebug-idxgidebug)

[Memory management sample](https://github.com/microsoft/DirectX-Graphics-Samples/tree/master/TechniqueDemos/D3D12MemoryManagement)