# IStreamBufferRecordControl::Start

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Start** method starts the recording.

## Parameters

### `prtStart` [in, out]

Pointer to a variable that contains the start time. The time is relative to the current stream time, in 100-nanosecond units. The value zero represents now; negative values are in the past; and positive values are in the future.

For content recordings, the time must be a value between 0 and 5 seconds (50000000), inclusive. Negative times are not valid.

For reference recordings, negative times are valid if they fall within existing content. If the time given in *prtStart* is earlier than the earliest valid content, the actual start time of the content is used instead. This value is returned in *prtStart* when the method returns.

## Return value

Returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid time. |
| **E_POINTER** | NULL pointer argument. |
| **S_OK** | The method succeeded. |

## Remarks

The start time must be less than or equal to the stop time.

## See also

[IStreamBufferRecordControl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferrecordcontrol)

[IStreamBufferRecordControl::Stop](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-istreambufferrecordcontrol-stop)