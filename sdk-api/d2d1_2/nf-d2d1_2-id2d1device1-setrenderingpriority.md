# ID2D1Device1::SetRenderingPriority

## Description

Sets the priority of Direct2D rendering operations performed on any device context associated with the device.

## Parameters

### `renderingPriority`

Type: **[D2D1_RENDERING_PRIORITY](https://learn.microsoft.com/windows/desktop/api/d2d1_2/ne-d2d1_2-d2d1_rendering_priority)**

The desired rendering priority for the device and associated contexts.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid parameter was passed to the returning function. |

## Remarks

Calling this method affects the rendering priority of all device contexts associated with the device. This method can be called at any time, but is not guaranteed to take effect until the beginning of the next frame. The recommended usage is to call this method outside of [BeginDraw](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-begindraw) and [EndDraw](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) blocks. Cycling this property frequently within drawing blocks will effectively reduce the benefits of any throttling that is applied.

## See also

[ID2D1Device1](https://learn.microsoft.com/windows/desktop/api/d2d1_2/nn-d2d1_2-id2d1device1)