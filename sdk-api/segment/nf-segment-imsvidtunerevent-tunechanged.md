# IMSVidTunerEvent::TuneChanged

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Windows XP or later.

The **TuneChanged** method signals that the tuner has tuned to a new frequency.

## Parameters

### `lpd` [in]

Pointer to the **MSVidTuner** object that fired the event.

## Return value

Return S_OK or an error code.

## Remarks

The dispatch identifier (dispid) of this method is **eventidOnTuneChanged**.

## See also

[IMSVidTunerEvent Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidtunerevent)