# IStreamBufferRecComp::AppendEx

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **AppendEx** method appends part of a recording to the target file.

## Parameters

### `pszSBRecording` [in]

Null-terminated, wide character string that contains the name of the file to append.

### `rtStart` [in]

Specifies the start time of the segment to append, in 100-nanosecond units.

### `rtStop` [in]

Specifies the stop time of the segment to append, in 100-nanosecond units.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |

## Remarks

The file specified in *pszSBRecording* must be completed. If the file is live, the method fails. Also, the file's profile must match the one that was configured in the **Initialize** method.

The value of *rtStop* must be at least 2 seconds (20000000) greater than *rtStart*.

The caller must validate *rtStart* and *rtStop* before calling this method. The method will not automatically correct the times if they fall past the end of the file.

## See also

[IStreamBufferRecComp Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferreccomp)