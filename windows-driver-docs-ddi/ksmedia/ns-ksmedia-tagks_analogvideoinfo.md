# tagKS_AnalogVideoInfo structure

## Description

The KS_ANALOGVIDEOINFO structure describes an analog video stream.

## Members

### `rcSource`

Specifies a clipping rectangle that selects the portion of the active video signal to use.

### `rcTarget`

Specifies a rectangle that indicates which part of the target buffer to use.

### `dwActiveWidth`

Specifies the width of the active incoming video signal. For example, the value for ITUR-601 could be set to 720 active samples per line.

### `dwActiveHeight`

Specifies the height of the active incoming video signal. For example, the value for NTSC could be set to 483. For PAL/SECAM, the value could be set to 575.

### `AvgTimePerFrame`

Specifies the average time per frame, in 100-nanosecond units.

## Remarks

A source filter can request that the sink filter take only a section of the video by providing values that effectively define a clipping rectangle in the **rcSource** member. However, if the sink filter does not check for the clipping rectangle on connection, the sink filter simply renders all of the video, effectively ignoring any clipping information passed from the source filter to the sink filter.

Ideally, a sink filter checks **rcSource**. If the sink filter does not support image extraction, and the rectangle is *not* empty, then it rejects the connection. A filter should use the Win32 function **SetRectEmpty** to reset a rectangle to all zeros (and set **IsRectEmpty** to later check the rectangle).

The **rcTarget** member specifies the destination rectangle for the video. Most source filters set this member to all zeros. A downstream filter can request that the video be placed in a particular area of the buffers it supplies. In this case, it calls the Win32 function **QueryAccept** with a nonempty target.