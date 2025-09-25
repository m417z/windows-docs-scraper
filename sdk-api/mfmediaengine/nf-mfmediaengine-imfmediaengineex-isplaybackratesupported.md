# IMFMediaEngineEx::IsPlaybackRateSupported

## Description

Queries whether the Media Engine can play at a specified playback rate.

## Parameters

### `rate` [in]

The requested playback rate.

## Return value

Returns **TRUE** if the playback rate is supported, or **FALSE** otherwise.

## Remarks

Playback rates are expressed as a ratio of the current rate to the normal rate. For example, 1.0 is normal playback speed, 0.5 is half speed, and 2.0 is 2× speed. Positive values mean forward playback, and negative values mean reverse playback.

The results of this method can vary depending on the media resource that is currently loaded. Some media formats might support faster playback rates than others. Also, some formats might not support reverse play.

## See also

[IMFMediaEngineEx](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineex)