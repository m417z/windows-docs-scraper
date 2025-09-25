# IMFContentEnabler::AutomaticEnable

## Description

Performs a content enabling action without any user interaction.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method is asynchronous. When the operation is complete, the content enabler sends an [MEEnablerCompleted](https://learn.microsoft.com/windows/desktop/medfound/meenablercompleted) event. While the operation is in progress, the content enabler might send [MEEnablerProgress](https://learn.microsoft.com/windows/desktop/medfound/meenablerprogress) events.

To find out whether the content enabler supports this method, call [IMFContentEnabler::IsAutomaticSupported](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfcontentenabler-isautomaticsupported).

## See also

[How to Play Protected Media Files](https://learn.microsoft.com/windows/desktop/medfound/how-to-play-protected-media-files)

[IMFContentEnabler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfcontentenabler)