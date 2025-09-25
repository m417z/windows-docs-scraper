# ISBE2EnumStream::Skip

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Skips a specified number of streams in the enumeration sequence.

## Parameters

### `cRecords` [in]

The number of streams to skip.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The method succeeded. |
| ****S_FALSE**** | The end of the sequence was reached before skipping the requested number of streams. |

## See also

[ISBE2EnumStream](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2enumstream)