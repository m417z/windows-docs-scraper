# KSCAMERA_PERFRAMESETTING_FRAME_HEADER structure

## Description

This structure contains the header information for a frame in a per-frame settings payload.

## Members

### `Size`

The size of this header, all the item headers, value payloads, custom items, and custom data for this frame.

### `Id`

The frame ID in the range of 0 and KSCAMERA_PERFRAMESETTING_HEADER.FrameCount - 1.

### `ItemCount`

The number of item settings for this frame. The value 0 indicates using global settings for this frame.

### `Reserved`

Reserved for future use.