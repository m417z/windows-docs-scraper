# IMFClockConsumer::SetPresentationClock

## Description

Called by the media pipeline to provide the app with an instance of [IMFPresentationClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationclock).

## Parameters

### `pPresentationClock` [in]

An instance of [IMFPresentationClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationclock).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFClockConsumer](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfclockconsumer)