# IMFMediaEngineOPMInfo::GetOPMInfo

## Description

Gets status information about the [Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager) (OPM).

## Parameters

### `pStatus` [out]

 A pointer to a [MF_MEDIA_ENGINE_OPM_STATUS](https://learn.microsoft.com/windows/desktop/medfound/mf-media-engine-opm-status) enum type that indicates the OPM status.

### `pConstricted` [out]

A pointer to a **BOOL** type that indicates the constriction status.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded |
| **INVALIDARG** | If any of the parameters are **NULL**. |

## See also

[IMFMediaEngineOPMInfo](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineopminfo)