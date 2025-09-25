# IMFMediaEngineEx::SetBalance

## Description

Sets the audio balance.

## Parameters

### `balance` [in]

The audio balance. The value can be any number in the following range (inclusive).

| Value | Meaning |
| --- | --- |
| -1 | The left channel is at full volume; the right channel is silent. |
| 1 | The right channel is at full volume; the left channel is silent. |

If the value is zero, the left and right channels are at equal volumes. The default value is zero.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When the audio balance changes, the Media Engine sends an **MF_MEDIA_ENGINE_EVENT_BALANCECHANGE** event. See [IMFMediaEventNotify::EventNotify](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaenginenotify-eventnotify).

## See also

[IMFMediaEngineEx](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineex)