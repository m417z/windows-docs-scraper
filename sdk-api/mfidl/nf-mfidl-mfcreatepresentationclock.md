# MFCreatePresentationClock function

## Description

Creates the presentation clock. The presentation clock is used to schedule the time at which samples are rendered and to synchronize multiple streams.

## Parameters

### `ppPresentationClock`

Receives a pointer to the clock's [IMFPresentationClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationclock) interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The caller must shut down the presentation clock by calling [IMFShutdown::Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfshutdown-shutdown) on the clock.

Typically applications do not create the presentation clock. The Media Session automatically creates the presentation clock. To get a pointer to the presentation clock from the Media Session, call [IMFMediaSession::GetClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasession-getclock).

## See also

[About the Media Session](https://learn.microsoft.com/windows/desktop/medfound/about-the-media-session)

[IMFPresentationClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationclock)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)