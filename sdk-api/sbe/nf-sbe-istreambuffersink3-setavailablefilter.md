# IStreamBufferSink3::SetAvailableFilter

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **SetAvailableFilter** method limits how far the Stream Buffer Source filter can seek backward, relative to the current recording position.

## Parameters

### `prtMin` [in, out]

On input, specifies the earliest seek time, in 100-nanosecond units, relative to the recording position when the method is called. The value must be less than or equal to zero. To make the entire backing store available, use the value -MAXLONGLONG.

On output, this parameter receives the actual minimum seek time. The two values may differ if the requested time exceeds the amount of time that is available.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The minimum seek time is an absolute position within the file. For example, suppose the value is -50000000. Immediately after the method returns, the Stream Buffer Source filter can seek backward 5 seconds, but no further. After another 15 seconds of recording, the filter can seek backward 20 seconds from the new position.

## See also

[IStreamBufferSink3 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambuffersink3)