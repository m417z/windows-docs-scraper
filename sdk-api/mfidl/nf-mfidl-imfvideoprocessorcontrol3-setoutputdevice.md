## Description

Sets the output device when the video processor is used as part of a renderer and the renderer has knowledge of the output device.

## Parameters

### `pOutputDevice` [in]

An **IUnknown** representing the output device. This may be either a [IDXGIOutput](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgioutput) or [Windows.Graphics.Display.IDisplayInformation](https://learn.microsoft.com/uwp/api/windows.graphics.display.displayinformation), depending on the renderer.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

## See also