# IMFMediaEngineEx::GetBalance

## Description

Gets the audio balance.

## Return value

Returns the balance. The value can be any number in the following range (inclusive).

| Return value | Description |
| --- | --- |
| -1 | The left channel is at full volume; the right channel is silent. |
| 1 | The right channel is at full volume; the left channel is silent. |

If the value is zero, the left and right channels are at equal volumes. The default value is zero.

## See also

[IMFMediaEngineEx](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineex)