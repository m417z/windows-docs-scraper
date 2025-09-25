# _VIDEO_MODE_INFORMATION structure

## Description

The VIDEO_MODE_INFORMATION structure contains all of the information about one mode of a video adapter.

## Members

### `Length`

Specifies the length, in bytes, of this structure. A miniport driver can use this value to determine the version of this structure.

### `ModeIndex`

Specifies the index of the particular mode to be used in a call to the miniport driver.

### `VisScreenWidth`

Specifies the number of visible pixels on one horizontal scan line.

### `VisScreenHeight`

Specifies the number of visible lines (or scan lines) on the screen.

### `ScreenStride`

Specifies the number of bytes between the start of one scan line and the next.

### `NumberOfPlanes`

Specifies the number of separate planes combined by the device.

### `BitsPerPlane`

Specifies the number of bits per pixel per plane.

### `Frequency`

Specifies the screen refresh rate, in Hertz.

### `XMillimeter`

Specifies the width, in millimeters, of the active region on the output device.

### `YMillimeter`

Specifies the height, in millimeters, of the active region on the output device.

### `NumberRedBits`

Specifies the number of bits in the red DAC.

### `NumberGreenBits`

Specifies the number of bits in the green DAC.

### `NumberBlueBits`

Specifies the number of bits in the blue DAC.

### `RedMask`

Is the red color mask for a device with direct color modes. For example, to indicate that bits 0 through 4 are to be used for red, use the value 0x001F.

### `GreenMask`

Is the green color mask for a device with direct color modes. For example, to indicate that bits 5 through 9 are to be used for green, use the value 0x03E0.

### `BlueMask`

Is the blue color mask for a device with direct color modes. For example, to indicate that bits 10 through 14 are to be used for blue, use the value 0x7C00.

### `AttributeFlags`

Is a set of flags indicating certain behavior for the device. The flags and their meanings are shown in the following table.

| **Flag Name** | **Flag Value** | **Bit Number** | **Bit Value and Meaning** |
|:--|:--|:--|:--|
| VIDEO_MODE_COLOR | 0x0001 | 0 | 0 = Mono-compatible<br>1 = Color |
| VIDEO_MODE_GRAPHICS | 0x0002 | 1 | 0 = Text mode<br>1 = Graphics |
| VIDEO_MODE_PALETTE_DRIVEN | 0x0004 | 2 | 0 = Colors are direct<br>1 = Colors are indexed to a [palette](https://learn.microsoft.com/windows-hardware/drivers/) |
| VIDEO_MODE_MANAGED_PALETTE | 0x0008 | 3 | 0 = Palette is fixed (must be queried from miniport driver)<br>1 = Palette is settable |
| VIDEO_MODE_INTERLACED | 0x0010 | 4 | 0 = Non-interlaced mode<br>1 = Interlaced mode |
| VIDEO_MODE_NO_OFF_SCREEN | 0x0020 | 5 | 0 = Offscreen memory is available<br>1 = Offscreen memory cannot be used to store information |
| VIDEO_MODE_NO_64_BIT_ACCESS | 0x0040 | 6 | 0 = 64-bit memory writes to [frame buffer](https://learn.microsoft.com/windows-hardware/drivers/) are handled properly<br>1 = 64-bit memory writes to frame buffer are not handled |

### `VideoMemoryBitmapWidth`

Specifies the width, in pixels, of the video memory bitmap.

### `VideoMemoryBitmapHeight`

Specifies the height, in pixels, of the video memory bitmap.

### `DriverSpecificAttributeFlags`

Is a set of flags indicating certain behavior for the device. These private flags are defined in the miniport driver, and are for the use by the miniport and display drivers only.

## Remarks

The video miniport driver returns an array of VIDEO_MODE_INFORMATION structures in response to an [IOCTL_VIDEO_QUERY_AVAIL_MODES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_query_avail_modes) request, with each structure containing information about one mode of the adapter. The miniport driver returns one VIDEO_MODE_INFORMATION structure that contains information about the adapter's current mode in response to an [IOCTL_VIDEO_QUERY_CURRENT_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_query_current_mode) request.

Three members of VIDEO_MODE_INFORMATION, **VisScreenWidth**, **VideoMemoryBitmapWidth**, and **ScreenStride**, are associated with horizontal screen width. For displays that use one or more bytes per pixel, these members satisfy the inequality

**VisScreenWidth** <= **VideoMemoryBitmapWidth** <= **ScreenStride**.

In a similar relationship for vertical screen height, **VisScreenHeight** and **VideoMemoryBitmapHeight** satisfy the inequality

**VisScreenHeight** <= **VideoMemoryBitmapHeight**.

## See also

[IOCTL_VIDEO_QUERY_AVAIL_MODES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_query_avail_modes)

[IOCTL_VIDEO_QUERY_CURRENT_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_query_current_mode)

[VIDEO_MEMORY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_memory_information)