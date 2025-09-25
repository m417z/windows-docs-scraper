# IAudioClient3::GetCurrentSharedModeEnginePeriod

## Description

Returns the current format and periodicity of the audio engine. This method enables audio clients to match the current period of the audio engine.

## Parameters

### `ppFormat` [out]

Type: **[WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85))****

The current device format that is being used by the audio engine.

### `pCurrentPeriodInFrames` [out]

Type: **UINT32***

The current period of the audio engine, in audio frames.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns **S_OK** to indicate that it has completed successfully. Otherwise it returns an appropriate error code.

## Remarks

**Note** The values returned by this method are instantaneous values and may be invalid immediately after the call returns if, for example, another audio client sets the periodicity or format to a different value.

**Note** The caller is responsible for calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to deallocate the memory of the **WAVEFORMATEX** structure populated by this method.

## See also

[IAudioClient3](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient3)