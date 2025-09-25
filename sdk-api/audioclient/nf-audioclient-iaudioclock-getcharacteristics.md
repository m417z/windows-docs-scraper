# IAudioClock::GetCharacteristics

## Description

The **GetCharacteristics** method is reserved for future use.

## Parameters

### `pdwCharacteristics` [out]

Pointer to a **DWORD** variable into which the method writes a value that indicates the characteristics of the audio clock.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *pdwCharacteristics* is **NULL**. |

## See also

[IAudioClock Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclock)