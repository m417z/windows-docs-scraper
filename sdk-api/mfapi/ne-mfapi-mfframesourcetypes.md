# MFFrameSourceTypes enumeration

## Description

Describes the type of data provided by a frame source.

## Constants

### `MFFrameSourceTypes_Color:0x0001`

The frame source provides color data.

### `MFFrameSourceTypes_Infrared:0x0002`

The frame source provides infrared data.

### `MFFrameSourceTypes_Depth:0x0004`

The frame source provides depth data.

### `MFFrameSourceTypes_Image:0x0008`

The frame source provides image data.

**Note** This value was added in Windows 10, version 1803.

### `MFFrameSourceTypes_Custom:0x0080`

The frame source provides custom data.

## Remarks

The values of this enumeration are used with the [MF_DEVICESTREAM_ATTRIBUTE_FRAMESOURCE_TYPES](https://learn.microsoft.com/windows/desktop/medfound/mf-devicestream-attribute-framesource-types) attribute.