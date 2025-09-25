## Description

Enables the debug layer.

## Remarks

To enable the debug layers using this API, it must be called before the D3D12 device is created. Calling this API after creating the D3D12 device will cause the D3D12 runtime to remove the device.

## Examples

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

[ID3D12Debug](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12debug)