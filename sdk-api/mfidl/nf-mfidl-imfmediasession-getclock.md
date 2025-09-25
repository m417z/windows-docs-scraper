# IMFMediaSession::GetClock

## Description

Retrieves the Media Session's presentation clock.

## Parameters

### `ppClock` [out]

Receives a pointer to the presentation clock's [IMFClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfclock) interface. The caller must release the interface.

## Return value

The method returns an HRESULT. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_UNEXPECTED** | The Media Session does not have a presentation clock. |
| **MF_E_SHUTDOWN** | The Media Session has been shut down. |

## Remarks

The application can query the returned [IMFClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfclock) pointer for the [IMFPresentationClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationclock) interface. However, the application should not use this interface to control the state of the presentation clock. Instead, the application should always call the transport control methods on the Media Session's [IMFMediaSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasession) interface, such as [Start](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasession-start), [Stop](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasession-stop), and [Pause](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasession-pause).

## See also

[IMFMediaSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasession)