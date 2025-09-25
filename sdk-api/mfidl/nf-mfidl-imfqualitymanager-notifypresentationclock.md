# IMFQualityManager::NotifyPresentationClock

## Description

Called when the Media Session selects a presentation clock.

## Parameters

### `pClock` [in]

Pointer to the [IMFPresentationClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationclock) interface of the presentation clock. If this parameter is **NULL**, the quality manager should release any references to the presentation clock.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFQualityManager](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfqualitymanager)