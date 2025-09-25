# IMFMediaEngineEx::GetStatistics

## Description

Gets a playback statistic from the Media Engine.

## Parameters

### `StatisticID` [in]

A member of the [MF_MEDIA_ENGINE_STATISTIC](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/ne-mfmediaengine-mf_media_engine_statistic) enumeration that identifies the statistic to get.

### `pStatistic` [out]

A pointer to a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) that receives the statistic. The data type and meaning of this value depends on the value of *StatisticID*. The caller must free the **PROPVARIANT** by calling [PropVariantClear](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-propvariantclear).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFMediaEngineEx](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineex)