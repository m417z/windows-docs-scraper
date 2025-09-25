# DCOMPOSITION_FRAME_STATISTICS structure

## Description

Describes timing and composition statistics for a frame.

## Members

### `lastFrameTime`

Type: **[LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1)**

The time stamp of the last batch of commands to be processed by the composition engine.

### `currentCompositionRate`

Type: **[DXGI_RATIONAL](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_rational)**

The rate at which the composition engine is producing frames, in frames per second.

### `currentTime`

Type: **[LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1)**

The current time as computed by the [QueryPerformanceCounter](https://learn.microsoft.com/windows/desktop/api/profileapi/nf-profileapi-queryperformancecounter) function.

### `timeFrequency`

Type: **[LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1)**

The units in which the **lastFrameTime** and **currentTime** members are specified, in Hertz.

### `nextEstimatedFrameTime`

Type: **[LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1)**

The estimated time when the next frame will be displayed.

## Remarks

The [IDCompositionDevice::GetFrameStatistics](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice-getframestatistics) method fills this structure. An application can use the information in this structure to estimate the timestamp of the next few frames that will be started by the composition engine. Note that this is only an estimate because the composition engine may or may not compose the next frame, depending on whether any active animations or other work are pending for that frame. In addition, the composition engine may change frame rates according to the cost of composing individual frames.

## See also

[IDCompositionDevice::GetFrameStatistics](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice-getframestatistics)