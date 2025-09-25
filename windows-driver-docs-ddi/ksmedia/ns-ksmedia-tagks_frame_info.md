## Description

The **KS_FRAME_INFO** structure extends the **KSSTREAM_HEADER** structure for video streams.

## Members

### `ExtendedHeaderSize`

Specifies the size of this structure, in bytes.

### `dwFrameFlags`

Specifies flags indicating additional information about the frame captured. During capture, the minidriver sets this member to one of the following values that are defined in *ksmedia.h*:

| Flag | Meaning |
| --- | --- |
| KS_VIDEO_FLAG_FRAME | Indicates a complete frame. |
| KS_VIDEO_FLAG_FIELD1 | Indicates Field 1 of a two-field sequence. |
| KS_VIDEO_FLAG_FIELD2 | Indicates Field 2 of a two-field sequence. |
| KS_VIDEO_FLAG_I_FRAME | Indicates that this frame can be completely decoded without reference to any other frames. |
| KS_VIDEO_FLAG_P_FRAME | Indicates that this is a predicted frame. |
| KS_VIDEO_FLAG_B_FRAME | Indicates that this is a bidirectional frame. |

### `PictureNumber`

Specifies a count representing the current picture number. Initialize or update this value on transition into KSSTATE_ACQUIRE.

### `DropCount`

Specifies the number of pictures that were not captured. During capture, the minidriver sets this member. This counter should be incremented whenever a frame should have been captured but was not; this condition usually arises when no buffers were available during capture. Initialize or update this value on transition into KSSTATE_ACQUIRE.

### `hDirectDraw`

Specifies the user-mode handle to DirectDraw. This handle is only provided to the minidriver when capturing to a DirectDraw surface for preview or overlay purposes.

### `hSurfaceHandle`

Specifies the user-mode handle to the DirectDraw surface. This handle is only provided to the minidriver when capturing to a DirectDraw surface for preview or overlay purposes.

### `DirectDrawRect`

Specifies the portion of the DirectDraw surface that has been locked. This is normally the entire surface.

### `lSurfacePitch`

Contains surface pitch (also known as stride).

### `Reserved1`

Reserved and should not be used by the minidriver.

### `Reserved2`

Reserved and should not be used by the minidriver.

### `Reserved3`

Reserved and should not be used by the minidriver.

### `Reserved4`

Reserved and should not be used by the minidriver.

### `FrameCompletionNumber`

An identifying sequence number for the frame in the completed queue. This number is used to verify proper frame order. When this value is 0, the frame was cancelled.

This member is available starting with Windows 8.1.

## Remarks

The **KS_FRAME_INFO** structure provides a way to return information about the frame captured, as well as a way to pass Microsoft DirectDraw handles used when capturing to a DirectDraw surface.

The **PictureNumber** member count represents the count of the current picture, which is calculated in one of two ways depending on the device:

* Measure the time since the stream was started and divide by the frame duration. This method is appropriate for devices that do not provide their own clock. For example:

```cpp
    PictureNumber = ElapsedTime / FrameDuration;
    ```

* Add together the count of frames captured and the count of frame dropped. This method is appropriate for devices that provide their own clock. For example:

```cpp
    PictureNumber = FramesCaptured + FramesDropped;
    ```

When calculating **PictureNumber** and **DropCount**, it is important to use the frame duration specified when the stream was opened, which may not necessarily match the rate at which the device is actually producing images. For example, a USB camera may only produce images at 7.5 fps, but a client could open the stream at 8 fps. In this case, all calculations should use the 8 fps number.

For more information about updating **PictureNumber** and **DropCount** see [Capturing Video](https://learn.microsoft.com/windows-hardware/drivers/stream/capturing-video).

## See also

[KSSTREAM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksstream_header)