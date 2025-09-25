# DXGI_PRESENT_PARAMETERS structure

## Description

Describes information about present that helps the operating system optimize presentation.

## Members

### `DirtyRectsCount`

The number of updated rectangles that you update in the back buffer for the presented frame. The operating system uses this information to optimize presentation. You can set this member to 0 to indicate that you update the whole frame.

### `pDirtyRects`

A list of updated rectangles that you update in the back buffer for the presented frame. An application must update every single pixel in each rectangle that it reports to the runtime; the application cannot assume that the pixels are saved from the previous frame. For more information about updating dirty rectangles, see Remarks. You can set this member to **NULL** if **DirtyRectsCount** is 0. An application must not update any pixel outside of the dirty rectangles.

### `pScrollRect`

 A pointer to the scrolled rectangle. The scrolled rectangle is the rectangle of the previous frame from which the runtime bit-block transfers (bitblts) content. The runtime also uses the scrolled rectangle to optimize presentation in terminal server and indirect display scenarios.

The scrolled rectangle also describes the destination rectangle, that is, the region on the current frame that is filled with scrolled content. You can set this member to **NULL** to indicate that no content is scrolled from the previous frame.

### `pScrollOffset`

A pointer to the offset of the scrolled area that goes from the source rectangle (of previous frame) to the destination rectangle (of current frame). You can set this member to **NULL** to indicate no offset.

## Remarks

This structure is used by the [Present1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-present1) method.

The scroll rectangle and the list of dirty rectangles could overlap. In this situation, the dirty rectangles take priority. Applications can then have pieces of dynamic content on top of a scrolled area. For example, an application could scroll a page and play video at the same time.

The following diagram and coordinates illustrate this example.

![Illustration of scroll and dirty rectangles overlapping](https://learn.microsoft.com/windows/win32/api/dxgi1_2/images/DXGIPresentParam.png)

``` syntax
DirtyRectsCount = 2
pDirtyRects[ 0 ] = { 10, 30, 40, 50 } // Video
pDirtyRects[ 1 ] = { 0, 70, 50, 80 } // New line
*pScrollRect = { 0, 0, 50, 70 }
*pScrollOffset = { 0, -10 }

```

Parts of the previous frame and content that the application renders are combined to produce the final frame that the operating system presents on the display screen. Most of the window is scrolled from the previous frame. The application must update the video frame with the new chunk of content that appears due to scrolling.

The dashed rectangle shows the scroll rectangle in the current frame. The scroll rectangle is specified by the **pScrollRect** member.
The arrow shows the scroll offset. The scroll offset is specified by the **pScrollOffset** member.
Filled rectangles show dirty rectangles that the application updated with new content. The filled rectangles are specified by the **DirtyRectsCount** and **pDirtyRects** members.

The scroll rectangle and offset are not supported for the [DXGI_SWAP_EFFECT_DISCARD](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_effect) or [DXGI_SWAP_EFFECT_SEQUENTIAL](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_effect) present option. Dirty rectangles and scroll rectangle are not supported for multisampled swap chains.

The actual implementation of composition and necessary bitblts is different for the bitblt model and the flip model. For more info about these models, see [DXGI Flip Model](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-flip-model).

For more info about the flip-model swap chain and optimizing presentation, see [Enhancing presentation with the flip model, dirty rectangles, and scrolled areas](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-1-2-presentation-improvements).

## See also

[DXGI Structures](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)