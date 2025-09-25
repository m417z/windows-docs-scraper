# IMFClockStateSink::OnClockStop

## Description

Called when the presentation clock stops.

## Parameters

### `hnsSystemTime` [in]

The system time when the clock stopped, in 100-nanosecond units.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SINK_ALREADYSTOPPED** | Deprecated. Do not use this error code. |

## Remarks

When the presentation clock's [IMFPresentationClock::Stop](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpresentationclock-stop) method is called, the clock notifies the presentation time source by calling the presentation time source's **OnClockStop** method. This call occurs synchronously within the **Stop** method. If the time source returns an error from **OnClockStop**, the presentation clock's **Stop** method returns an error and the state change does not take place.

For any object that is not the presentation time source, the **OnClockStop** method is called asynchronously, after the state change is completed.

If an object is already stopped, it should return **S_OK** from **OnClockStop**. It should not return an error code.

**Note** Although the header file mferror.h defines an error code named **MF_E_SINK_ALREADYSTOPPED**, it should not be returned in this situation.

## See also

[IMFClockStateSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfclockstatesink)

[MFTIME](https://learn.microsoft.com/windows/desktop/medfound/mftime)

[Presentation Clock](https://learn.microsoft.com/windows/desktop/medfound/presentation-clock)