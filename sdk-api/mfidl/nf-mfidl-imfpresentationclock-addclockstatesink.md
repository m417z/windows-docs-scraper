# IMFPresentationClock::AddClockStateSink

## Description

Registers an object to be notified whenever the clock starts, stops, or pauses, or changes rate.

## Parameters

### `pStateSink` [in]

Pointer to the object's [IMFClockStateSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfclockstatesink) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Before releasing the object, call [IMFPresentationClock::RemoveClockStateSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpresentationclock-removeclockstatesink) to unregister the object for state-change notifications.

## See also

[IMFPresentationClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationclock)

[Presentation Clock](https://learn.microsoft.com/windows/desktop/medfound/presentation-clock)