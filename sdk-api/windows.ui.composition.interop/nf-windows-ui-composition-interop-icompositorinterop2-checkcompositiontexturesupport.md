## Description

Queries whether the Direct3D device that you're using to render supports composition textures (without having to first allocate a Direct3D texture on that device). Before you attempt to create composition textures for D3D textures backed by a given Direct3D device, you should call **CheckCompositionTextureSupport**, passing that backing device.

Generally speaking, a rendering device that reports support for either monitored or non-monitored fences via [DXGI_ADAPTER_FLAG3](https://learn.microsoft.com/windows/win32/api/dxgi1_6/ne-dxgi1_6-dxgi_adapter_flag3) is able to support composition textures. But in rare cases, the operating system (OS) itself can disable the composition textures feature; in which case **CheckCompositionTextureSupport** will also report unsupported.

## Parameters

### `renderingDevice`

Type: \_In\_ **[IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown)\***

The backing Direct3D device.

### `supportsCompositionTextures`

Type: \_Out\_ **[BOOL](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Points to a value of `true` if *renderingDevice* supports composition textures; otherwise 'false`.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types) error code.

## Remarks

## See also

* [ICompositorInterop2 interface](https://learn.microsoft.com/windows/win32/api/windows.ui.composition.interop/nn-windows-ui-composition-interop-icompositorinterop2)