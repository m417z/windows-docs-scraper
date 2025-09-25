# IStreamBufferRecComp::Append

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Append** method appends an entire recording to the target file.

## Parameters

### `pszSBRecording` [in]

Null-terminated, wide character string that contains the name of the file to append.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |

## Remarks

The file specified in *pszSBRecording* must be completed. If the file is live, the method fails. Also, the file's profile must match the one that was configured in the **Initialize** method.

## See also

[IStreamBufferRecComp Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferreccomp)