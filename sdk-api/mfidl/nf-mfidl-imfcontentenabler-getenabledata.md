# IMFContentEnabler::GetEnableData

## Description

Retrieves the data for a manual content enabling action.

## Parameters

### `ppbData` [out]

Receives a pointer to a buffer that contains the data. The caller must free the buffer by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `pcbData` [out]

Receives the size of the *ppbData* buffer.

## Return value

The method returns an HRESULT. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_NOT_AVAILABLE** | No data is available. |

## Remarks

The purpose of the data depends on the content enabler type, which is obtained by calling [IMFContentEnabler::GetEnableType](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfcontentenabler-getenabletype).

| Enable type | Purpose of data |
| --- | --- |
| Individualization | Not applicable. |
| License acquisition | HTTP POST data. |
| Revocation | [MFRR_COMPONENTS](https://learn.microsoft.com/windows/desktop/api/mfidl/ns-mfidl-mfrr_components) structure. |

## See also

[How to Play Protected Media Files](https://learn.microsoft.com/windows/desktop/medfound/how-to-play-protected-media-files)

[IMFContentEnabler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfcontentenabler)