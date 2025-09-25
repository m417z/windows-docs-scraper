# IMFPresentationClock::SetTimeSource

## Description

Sets the time source for the presentation clock. The time source is the object that drives the clock by providing the current time.

## Parameters

### `pTimeSource` [in]

Pointer to the [IMFPresentationTimeSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationtimesource) interface of the time source.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_CLOCK_NOT_SIMPLE** | The time source does not have a frequency of 10 MHz. |
| **MF_E_NOT_INITIALIZED** | The time source has not been initialized. |

## Remarks

The presentation clock cannot start until it has a time source.

The time source is automatically registered to receive state change notifications from the clock, through the time source's [IMFClockStateSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfclockstatesink) interface, which all time sources must implement.

This time source have a frequency of 10 MHz. See [IMFClock::GetClockCharacteristics](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfclock-getclockcharacteristics). If not, the method returns MF_E_CLOCK_NOT_SIMPLE.

## See also

[IMFPresentationClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationclock)

[Presentation Clock](https://learn.microsoft.com/windows/desktop/medfound/presentation-clock)