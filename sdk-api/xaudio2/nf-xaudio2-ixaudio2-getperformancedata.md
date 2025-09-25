# IXAudio2::GetPerformanceData

## Description

Returns current resource usage details, such as available memory or CPU usage.

## Parameters

### `pPerfData` [out]

On success, pointer to an [XAUDIO2_PERFORMANCE_DATA](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_performance_data) structure that is returned.

## Remarks

For specific information on the statistics returned by **GetPerformanceData**, see the [XAUDIO2_PERFORMANCE_DATA](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_performance_data) structure reference.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAudio2](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2)