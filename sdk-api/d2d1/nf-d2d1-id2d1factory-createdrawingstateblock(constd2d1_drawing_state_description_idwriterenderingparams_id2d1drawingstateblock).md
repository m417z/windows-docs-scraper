# ID2D1Factory::CreateDrawingStateBlock

## Description

Creates an [ID2D1DrawingStateBlock](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1drawingstateblock) that can be used with the [SaveDrawingState](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-savedrawingstate) and [RestoreDrawingState](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-restoredrawingstate) methods of a render target.

## Parameters

### `drawingStateDescription` [in, optional]

Type: **const [D2D1_DRAWING_STATE_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_drawing_state_description)***

A structure that contains antialiasing, transform, and tags information.

### `textRenderingParams` [in, optional]

Type: **[IDWriteRenderingParams](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriterenderingparams)***

Optional text parameters that indicate how text should be rendered.

### `drawingStateBlock` [out]

Type: **[ID2D1DrawingStateBlock](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1drawingstateblock)****

When this method returns, contains the address of a pointer to the new drawing state block created by this method.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## See also

[ID2D1Factory](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1factory)