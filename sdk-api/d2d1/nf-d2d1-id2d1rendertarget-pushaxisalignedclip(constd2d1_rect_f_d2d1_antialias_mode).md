## Description

Specifies a rectangle to which all subsequent drawing operations are clipped.

## Parameters

### `clipRect`

Type: [in] **const [D2D1_RECT_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-rect-f)***

The size and position of the clipping area, in device-independent pixels.

### `antialiasMode`

Type: [in] **[D2D1_ANTIALIAS_MODE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_antialias_mode)**

The antialiasing mode that is used to draw the edges of clip rects that have subpixel boundaries, and to blend the clip with the scene contents. The blending is performed once when the [PopAxisAlignedClip](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-popaxisalignedclip) method is called, and does not apply to each primitive within the layer.

## Remarks

The *clipRect* is transformed by the current world transform set on the render target. After the transform is applied to the *clipRect* that is passed in, the axis-aligned bounding box for the *clipRect* is computed. For efficiency, the contents are clipped to this axis-aligned bounding box and not to the original *clipRect* that is passed in.

The following diagrams show how a rotation transform is applied to the render target, the resulting *clipRect*, and a calculated axis-aligned bounding box.

1. Assume the rectangle in the following illustration is a render target that is aligned to the screen pixels.

   ![Illustration of a rectangle (render target)](https://learn.microsoft.com/windows/win32/api/d2d1/images/pushaxisalignedclip_step1_rendertarget.png)
2. Apply a rotation transform to the render target. In the following illustration, the black rectangle represents the original render target and the red dashed rectangle represents the transformed render target.

   ![Illustration of a rotated rectangle (transformed render target)](https://learn.microsoft.com/windows/win32/api/d2d1/images/pushaxisalignedclip_step2_transformed.png)
3. After calling **PushAxisAlignedClip**, the rotation transform is applied to the *clipRect*. In the following illustration, the blue rectangle represents the transformed *clipRect*.

   ![Illustration of a small blue rectangle (transformed clipRect) inside a rotated rectangle](https://learn.microsoft.com/windows/win32/api/d2d1/images/pushaxisalignedclip_step3_clipRecttransformed.png)
4. The axis-aligned bounding box is calculated. The green dashed rectangle represents the bounding box in the following illustration. All contents are clipped to this axis-aligned bounding box.

   ![Illustration of a green bounding box around a small blue rectangle inside a rotated rectangle](https://learn.microsoft.com/windows/win32/api/d2d1/images/pushaxisalignedclip_step4_boundingbox.png)

**Note** If rendering operations fail or if [PopAxisAlignedClip](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-popaxisalignedclip) is not called, clip rects may cause some artifacts on the render target. **PopAxisAlignedClip** can be considered a drawing operation that is designed to fix the borders of a clipping region. Without this call, the borders of a clipped area may be not antialiased or otherwise corrected.

The **PushAxisAlignedClip** and [PopAxisAlignedClip](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-popaxisalignedclip) must match. Otherwise, the error state is set. For the render target to continue receiving new commands, you can call [Flush](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-flush) to clear the error.

A **PushAxisAlignedClip** and [PopAxisAlignedClip](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-pushaxisalignedclip(constd2d1_rect_f_d2d1_antialias_mode)) pair can occur around or within a PushLayer and PopLayer, but cannot overlap. For example, the sequence of **PushAxisAlignedClip**, [PushLayer](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-pushlayer(constd2d1_layer_parameters__id2d1layer)), [PopLayer](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-poplayer), **PopAxisAlignedClip** is valid, but the sequence of **PushAxisAlignedClip**, **PushLayer**, **PopAxisAlignedClip**, **PopLayer** is invalid.

This method doesn't return an error code if it fails. To determine whether a drawing operation (such as [PushAxisAlignedClip](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-pushaxisalignedclip(constd2d1_rect_f_d2d1_antialias_mode))) failed, check the result returned by the [ID2D1RenderTarget::EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) or [ID2D1RenderTarget::Flush](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-flush) methods.

## See also

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)