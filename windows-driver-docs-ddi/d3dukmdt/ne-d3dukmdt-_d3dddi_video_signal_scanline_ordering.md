# _D3DDDI_VIDEO_SIGNAL_SCANLINE_ORDERING enumeration

## Description

The D3DDDI_VIDEO_SIGNAL_SCANLINE_ORDERING enumeration is used to indicate the scan line ordering of a video output signal.

## Constants

### `D3DDDI_VSSLO_UNINITIALIZED`

Indicates that a variable of type D3DDDI_VIDEO_SIGNAL_SCANLINE_ORDERING has not yet been assigned a meaningful value.

### `D3DDDI_VSSLO_PROGRESSIVE`

Indicates that each field contains an entire frame.

### `D3DDDI_VSSLO_INTERLACED_UPPERFIELDFIRST`

Indicates that each field contains half of a frame, and the odd scan lines are displayed first.

### `D3DDDI_VSSLO_INTERLACED_LOWERFIELDFIRST`

Indicates that each field contains half of a frame, and the even scan lines are displayed first.

### `D3DDDI_VSSLO_OTHER`

Indicates that the video signal has a scan line ordering other than those given in the previous constants of this enumeration.

## Remarks

The values of the D3DDDI_VIDEO_SIGNAL_SCANLINE_ORDERING enumeration type indicate whether the image displayed on the monitor contains the entire content of a video frame or only half of the content (that is, either the even or odd scan lines, which occur interchangeably). The values also indicate which field comes first in the ordering.