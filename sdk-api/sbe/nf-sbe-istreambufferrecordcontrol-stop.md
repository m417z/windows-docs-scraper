# IStreamBufferRecordControl::Stop

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Stop** method stops the recording and closes the file.

## Parameters

### `rtStop` [in]

Specifies when the recording stops. The time is relative to the current stream time, in 100-nanosecond units. The value zero represents now; negative values are in the past; and positive values are in the future.

For content recordings, the valid range is from 0 to 5 seconds (50000000), inclusive. Negative times are not valid.

For reference recordings, a negative time is valid if it falls within valid recorded content.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The stop time must be greater than or equal to the start time.

## See also

[IStreamBufferRecordControl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferrecordcontrol)

[IStreamBufferRecordControl::Start](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-istreambufferrecordcontrol-start)