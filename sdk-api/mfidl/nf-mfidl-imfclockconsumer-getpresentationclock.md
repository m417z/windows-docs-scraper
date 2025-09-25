# IMFClockConsumer::GetPresentationClock

## Description

Called by the media pipeline to get an instance of [IMFPresentationClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationclock).

## Parameters

### `ppPresentationClock` [out]

Pointer to an object that implements the [IMFPresentationClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationclock) interface. This value can be null.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | The app does not implement this method. |

## See also

[IMFClockConsumer](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfclockconsumer)