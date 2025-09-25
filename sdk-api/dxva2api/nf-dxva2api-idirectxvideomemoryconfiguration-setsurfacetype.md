# IDirectXVideoMemoryConfiguration::SetSurfaceType

## Description

Sets the video surface type that a decoder will use for DirectX Video Acceleration (DVXA) 2.0.

## Parameters

### `dwType` [in]

Member of the [DXVA2_SurfaceType](https://learn.microsoft.com/windows/win32/api/dxva2api/ne-dxva2api-dxva2_surfacetype) enumeration specifying the surface type. Currently, the only supported value is DXVA2_SurfaceType_DecoderRenderTarget.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **ERROR_UNSUPPORTED_TYPE** | The renderer does not support the specified surface type. |

## Remarks

By calling this method, the caller agrees to create surfaces of the type specified in the *dwType* parameter.

In DirectShow, during pin connection, a video decoder that supports DVXA 2.0 should call **SetSurface** with the value DXVA2_SurfaceType_DecoderRenderTarget. This notifies the video renderer that the decoder will provide the allocator and will create the Direct3D surfaces for decoding. For more information, see [Supporting DXVA 2.0 in DirectShow](https://learn.microsoft.com/windows/desktop/medfound/supporting-dxva-2-0-in-directshow).

The only way to undo the setting is to break the pin connection.

## See also

[IDirectXVideoMemoryConfiguration](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideomemoryconfiguration)

[Supporting DXVA 2.0 in DirectShow](https://learn.microsoft.com/windows/desktop/medfound/supporting-dxva-2-0-in-directshow)