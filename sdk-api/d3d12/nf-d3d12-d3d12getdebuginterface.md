# D3D12GetDebugInterface function

## Description

Gets a debug interface.

Use [D3D12GetInterface](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-d3d12getinterface) to directly access newer interfaces, especially downlevel.

## Parameters

### `riid` [in]

Type: **REFIID**

The globally unique identifier (**GUID**) for the debug interface.
The **REFIID**, or **GUID**, of the debug interface can be obtained by using the __uuidof() macro.
For example, __uuidof([ID3D12Debug](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12debug)) will get the **GUID** of the debug interface.

### `ppvDebug` [out, optional]

Type: **void****

The debug interface, as a pointer to pointer to void.
See
[ID3D12Debug](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12debug) and
[ID3D12DebugDevice](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12debugdevice).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

The function signature PFN_D3D12_GET_DEBUG_INTERFACE is provided as a typedef, so that you can use dynamic linking techniques ([GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)) instead of statically linking.

#### Examples

Enable the D3D12 debug layer.

```cpp
// Enable the D3D12 debug layer.
{

    ComPtr<ID3D12Debug> debugController;
    if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController))))
    {
        debugController->EnableDebugLayer();
    }
}

```

Refer to the [Example Code in the D3D12 Reference](https://learn.microsoft.com/windows/desktop/direct3d12/notes-on-example-code).

## See also

[Core Functions](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-functions)