# ID2D1RenderTarget::PopAxisAlignedClip

## Description

Removes the last axis-aligned clip from the render target. After this method is called, the clip is no longer applied to subsequent drawing operations.

## Remarks

A [PushAxisAlignedClip](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-pushaxisalignedclip(constd2d1_rect_f__d2d1_antialias_mode))/**PopAxisAlignedClip** pair can occur around or within a [PushLayer](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-pushlayer(constd2d1_layer_parameters__id2d1layer))/[PopLayer](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-poplayer) pair, but may not overlap. For example, a **PushAxisAlignedClip**, **PushLayer**, **PopLayer**, **PopAxisAlignedClip** sequence is valid, but a **PushAxisAlignedClip**, **PushLayer**, **PopAxisAlignedClip**, **PopLayer** sequence is not.

**PopAxisAlignedClip** must be called once for every call to [PushAxisAlignedClip](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-pushaxisalignedclip(constd2d1_rect_f__d2d1_antialias_mode)).

For an example, see [How to Clip with an Axis-Aligned Clip Rectangle](https://learn.microsoft.com/windows/win32/Direct2D/how-to-clip-with-axis-aligned-rects).

This method doesn't return an error code if it fails. To determine whether a drawing operation (such as **PopAxisAlignedClip**) failed, check the result returned by the [ID2D1RenderTarget::EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) or [ID2D1RenderTarget::Flush](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-flush) methods.

## See also

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)