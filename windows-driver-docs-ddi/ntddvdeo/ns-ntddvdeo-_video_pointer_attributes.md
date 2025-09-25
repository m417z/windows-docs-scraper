# _VIDEO_POINTER_ATTRIBUTES structure

## Description

The VIDEO_POINTER_ATTRIBUTES structure contains attributes of the screen pointer.

## Members

### `Flags`

A set of flags that specify certain attributes of the pointer. **Flags** can be a combination of the following values:
|Value|Meaning|
|--- |--- |
|VIDEO_MODE_ASYNC_POINTER|The pointer can be updated asynchronously to drawing operations.|
|VIDEO_MODE_MONO_POINTER|A monochrome hardware pointer is supported.|
|VIDEO_MODE_COLOR_POINTER|A color hardware pointer is supported.|
|VIDEO_MODE_ANIMATE_START|The current pointer has the same hotspot as the previous pointer.|
|VIDEO_MODE_ANIMATE_UPDATE|The current pointer has the same hotspot as the previous pointer.|

### `Width`

Specifies the width of the pointer in pixels.

### `Height`

Specifies the height of the pointer in pixels.

### `WidthInBytes`

Specifies the width of the pointer in bytes.

### `Enable`

Specifies whether the pointer is visible. A nonzero value specifies that the pointer is visible. A value of zero specifies that the pointer is not visible.

### `Column`

Horizontal coordinate of the pointer's hot spot.

### `Row`

Vertical coordinate of the pointer's hot spot.

### `Pixels`

The pointer data, in device-compatible DIB format. Mask data is always in 1-bpp DIB format.

## See also

[IOCTL_VIDEO_QUERY_POINTER_ATTR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_query_pointer_attr)

[IOCTL_VIDEO_SET_POINTER_ATTR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_set_pointer_attr)