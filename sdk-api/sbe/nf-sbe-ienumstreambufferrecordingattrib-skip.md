# IEnumStreamBufferRecordingAttrib::Skip

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Skip** method skips over a specified number of attributes.

## Parameters

### `cRecords` [in]

The number of attributes to skip.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | Skipped past the end of the sequence. |
| **S_OK** | Success. |

## See also

[IEnumStreamBufferRecordingAttrib Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-ienumstreambufferrecordingattrib)