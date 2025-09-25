# IMFContentEnabler::Cancel

## Description

Cancels a pending content enabling action.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The content enabler sends an [MEEnablerCompleted](https://learn.microsoft.com/windows/desktop/medfound/meenablercompleted) event with a status code of E_CANCEL.

## See also

[How to Play Protected Media Files](https://learn.microsoft.com/windows/desktop/medfound/how-to-play-protected-media-files)

[IMFContentEnabler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfcontentenabler)