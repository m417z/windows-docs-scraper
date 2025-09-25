# _VIDEO_POINTER_CAPABILITIES structure

## Description

The **VIDEO_POINTER_CAPABILITIES** structure contains capabilities of the screen pointer.

## Members

### `Flags`

A set of flags that specify certain capabilities of the pointer. Flags can be a combination of the following values.

|Flag|Meaning|
|--- |--- |
|VIDEO_MODE_ASYNC_POINTER|The pointer can be updated asynchronously to drawing operations.|
|VIDEO_MODE_MONO_POINTER|A monochrome hardware pointer is supported.|
|VIDEO_MODE_COLOR_POINTER|A color hardware pointer is supported.|
|VIDEO_MODE_ANIMATE_START|The current pointer has the same hotspot as the previous pointer.|
|VIDEO_MODE_ANIMATE_UPDATE|The current pointer has the same hotspot as the previous pointer.|

### `MaxWidth`

Specifies the maximum width of the pointer, in pixels.

### `MaxHeight`

Specifies the maximum height of the pointer, in pixels.

### `HWPtrBitmapStart`

Specifies the first offset, in CPU-addressable units, in the memory bitmap that is used to store the hardware pointer bitmap. A value of –1 is not valid.

### `HWPtrBitmapEnd`

Specifies the last offset, in CPU-addressable units, in the memory bitmap that is used to store the hardware pointer bitmap. A value of –1 is not valid.