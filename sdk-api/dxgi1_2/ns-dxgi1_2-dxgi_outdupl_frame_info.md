# DXGI_OUTDUPL_FRAME_INFO structure

## Description

The **DXGI_OUTDUPL_FRAME_INFO** structure describes the current desktop image.

## Members

### `LastPresentTime`

The time stamp of the last update of the desktop image. The operating system calls the [QueryPerformanceCounter](https://learn.microsoft.com/windows/desktop/api/profileapi/nf-profileapi-queryperformancecounter)
function to obtain the value. A zero value indicates that the desktop image was not updated since an application last called the [IDXGIOutputDuplication::AcquireNextFrame](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgioutputduplication-acquirenextframe) method to acquire the next frame of the desktop image.

### `LastMouseUpdateTime`

The time stamp of the last update to the mouse. The operating system calls the [QueryPerformanceCounter](https://learn.microsoft.com/windows/desktop/api/profileapi/nf-profileapi-queryperformancecounter)
function to obtain the value. A zero value indicates that the position or shape of the mouse was not updated since an application last called the [IDXGIOutputDuplication::AcquireNextFrame](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgioutputduplication-acquirenextframe) method to acquire the next frame of the desktop image. The mouse position is always supplied for a mouse update. A new pointer shape is indicated by a non-zero value in the **PointerShapeBufferSize** member.

### `AccumulatedFrames`

The number of frames that the operating system accumulated in the desktop image surface since the calling application processed the last desktop image. For more information about this number, see Remarks.

### `RectsCoalesced`

Specifies whether the operating system accumulated updates by coalescing dirty regions. Therefore, the dirty regions might contain unmodified pixels. **TRUE** if dirty regions were accumulated; otherwise, **FALSE**.

### `ProtectedContentMaskedOut`

Specifies whether the desktop image might contain protected content that was already blacked out in the desktop image. **TRUE** if protected content was already blacked; otherwise, **FALSE**. The application can use this information to notify the remote user that some of the desktop content might be protected and therefore not visible.

### `PointerPosition`

A [DXGI_OUTDUPL_POINTER_POSITION](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_outdupl_pointer_position) structure that describes the most recent mouse position if the **LastMouseUpdateTime** member is a non-zero value; otherwise, this value is ignored. This value provides the coordinates of the location where the top-left-hand corner of the pointer shape is drawn; this value is not the desktop position of the hot spot.

### `TotalMetadataBufferSize`

Size in bytes of the buffers to store all the desktop update metadata for this frame. For more information about this size, see Remarks.

### `PointerShapeBufferSize`

Size in bytes of the buffer to hold the new pixel data for the mouse shape. For more information about this size, see Remarks.

## Remarks

A non-zero **LastMouseUpdateTime** indicates an update to either a mouse pointer position or a mouse pointer position and shape. That is, the mouse pointer position is always valid for a non-zero **LastMouseUpdateTime**; however, the application must check the value of the **PointerShapeBufferSize** member to determine whether the shape was updated too.

If only the pointer was updated (that is, the desktop image was not updated), the **AccumulatedFrames**, **TotalMetadataBufferSize**, and **LastPresentTime** members are set to zero.

An **AccumulatedFrames** value of one indicates that the application completed processing the last frame before a new desktop image was presented. If the **AccumulatedFrames** value is greater than one, more desktop image updates have occurred while the application processed the last desktop update. In this situation, the operating system accumulated the update regions. For more information about desktop updates, see Desktop Update Data.

A non-zero **TotalMetadataBufferSize** indicates the total size of the buffers that are required to store all the desktop update metadata. An application cannot determine the size of each type of metadata. The application must call the [IDXGIOutputDuplication::GetFrameDirtyRects](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgioutputduplication-getframedirtyrects), [IDXGIOutputDuplication::GetFrameMoveRects](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgioutputduplication-getframemoverects), or [IDXGIOutputDuplication::GetFramePointerShape](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgioutputduplication-getframepointershape) method to obtain information about each type of metadata.

**Note** To correct visual effects, an application must process the move region data before it processes the dirty rectangles.

## See also

[DXGI Structures](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)

[IDXGIOutputDuplication::AcquireNextFrame](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgioutputduplication-acquirenextframe)