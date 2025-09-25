# IKeywordDetectorOemAdapter::ParseDetectionResultData

## Description

The **ParseDetectionResultData** method is called by the operating system after handling a keyword detection event and after retrieving the result data from [KSPROPERTY_SOUNDDETECTOR_MATCHRESULT](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-sounddetector-matchresult). The operating system passes the OEM-specific match result data to this method in order to get the results of a keyword detection. The OEMDLL processes the results and returns information about the matched keyword, the language associated with the matched keyword, and the matched user (if any).

## Parameters

### `UserModelData` [in]

A pointer to **IStream** bound to model data for the arming pattern.

### `Result` [in]

A pointer to the [SOUNDDETECTOR_PATTERNHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-sounddetector_patternheader) from the DDI.

### `KeywordId` [out]

Identifies a keyword function. The driver may return 0 to indicate no match.

### `LangId` [out]

Identifies a language.

### `pIsUserMatch` [out]

Indicates if the user matched.

### `KeywordEndPerformanceCounterValue` [out]

Optionally returns the end time of the keyword in terms of the Windows performance counter. The OEMDLL should return 0 if this is not available.

### `KeywordStartPerformanceCounterValue` [out]

Optionally returns the start time of the keyword in terms of the Windows performance counter. The OEMDLL should return 0 if this is not available.

## Return value

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | The function exited successfully. |
| E_POINTER | The *ModelData* pointer is **NULL**. |
| E_INVALIDARG | The *KeywordId* or *LangId* parameters are invalid. |
| HRESULT_FROM_WIN32(ERROR_GEN_FAILURE) | The processing was unable to complete. |
| E_HW_RESET | The hardware reset due to an internal fault. |

## Remarks

If the driver includes any portion of the spoken keyword in the burst keyword/command stream from its keyword detector pin, then the driver must return a valid value for *KeywordEndTime*. Otherwise the driver may optionally return 0.

If the driver returns *KeywordStartTime* or *KeywordEndTime*, the returned values must be consistent with the time stamps returned from the driver’s [IMiniportWaveRTInputStream::GetReadPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavertinputstream-getreadpacket) routine.

The driver may return valid values for *KeywordStartTime* and *KeywordEndTime* regardless of whether the driver includes any portion of the spoken keyword in the burst keyword/command stream.

If the caller receives **E_HW_RESET**, no keyword was detected by the hardware and the state was lost. A re-arm will be required to get back to a monitoring state.

## See also

[CoTaskMemAlloc](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemalloc)

[CoTaskMemFree](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree)

[IKeywordDetectorOemAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/keyworddetectoroemadapter/nn-keyworddetectoroemadapter-ikeyworddetectoroemadapter)

[IMiniportWaveRTInputStream::GetReadPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavertinputstream-getreadpacket)

[KSPROPERTY_SOUNDDETECTOR_MATCHRESULT](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-sounddetector-matchresult)

[SOUNDDETECTOR_PATTERNHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-sounddetector_patternheader)