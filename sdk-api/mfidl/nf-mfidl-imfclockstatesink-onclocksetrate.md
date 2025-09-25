# IMFClockStateSink::OnClockSetRate

## Description

Called when the rate changes on the presentation clock.

## Parameters

### `hnsSystemTime` [in]

The system time when the rate was set, in 100-nanosecond units.

### `flRate` [in]

The new rate, as a multiplier of the normal playback rate.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When the presentation clock's [IMFRateControl::SetRate](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfratecontrol-setrate) method is called, the clock notifies the presentation time source by calling the time source's **OnClockSetRate** method. This call occurs synchronously within the **SetRate** method. If the time source returns an error from **OnClockSetRate**, the presentation clock's **SetRate** method returns an error and the state change does not take place.

For any object that is not the presentation time source, the **OnClockSetRate** method is called asynchronously, after the state change is completed. In that case, the return value from this method is ignored.

## See also

[IMFClockStateSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfclockstatesink)

[MFTIME](https://learn.microsoft.com/windows/desktop/medfound/mftime)

[Presentation Clock](https://learn.microsoft.com/windows/desktop/medfound/presentation-clock)