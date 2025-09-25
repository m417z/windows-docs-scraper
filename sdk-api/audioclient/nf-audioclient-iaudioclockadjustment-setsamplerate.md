# IAudioClockAdjustment::SetSampleRate

## Description

The **SetSampleRate** method sets the sample rate of a stream.

## Parameters

### `flSampleRate` [in]

The new sample rate in frames per second.

## Return value

If the method succeeds, it returns S_OK.

| Return code | Description |
| --- | --- |
| **AUDCLNT_E_NOT_INITIALIZED** | The audio stream has not been successfully initialized. |
| **E_INVALIDARG** | The sample rate is out of the range for the Audio Processing Object. |

## Remarks

This method must not be called from a real-time processing thread.

The new sample rate will take effect after the current frame is done processing and will remain in effect until **SetSampleRate** is called again.
The audio client must be initialized in shared-mode (AUDCLNT_SHAREMODE_SHARED), otherwise **SetSampleRate** fails.

## See also

[AUDCLNT_STREAMFLAGS_XXX Constants](https://learn.microsoft.com/windows/desktop/CoreAudio/audclnt-streamflags-xxx-constants)

[IAudioClockAdjustment](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclockadjustment)