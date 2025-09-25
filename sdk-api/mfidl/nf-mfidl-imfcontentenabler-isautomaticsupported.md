# IMFContentEnabler::IsAutomaticSupported

## Description

Queries whether the content enabler can perform all of its actions automatically.

## Parameters

### `pfAutomatic` [out]

Receives a Boolean value. If **TRUE**, the content enabler can perform the enabling action automatically.

## Return value

The method returns an HRESULT. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If this method returns **TRUE** in the *pfAutomatic* parameter, call the [IMFContentEnabler::AutomaticEnable](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfcontentenabler-automaticenable) method to perform the enabling action.

If this method returns **FALSE** in the *pfAutomatic* parameter, the application must use manual enabling. To do so, call [IMFContentEnabler::GetEnableURL](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfcontentenabler-getenableurl) and [IMFContentEnabler::GetEnableData](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfcontentenabler-getenabledata) to get the URL and data needed for manual enabling.

## See also

[How to Play Protected Media Files](https://learn.microsoft.com/windows/desktop/medfound/how-to-play-protected-media-files)

[IMFContentEnabler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfcontentenabler)