# GetEnabledUnicodeRanges function

## Description

Retrieves a list of Unicode point ranges enabled on the context. If you do not call the [SetEnabledUnicodeRanges](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-setenabledunicoderanges) function to specify the enabled ranges, this function returns the recognizer's default Unicode point ranges.

## Parameters

### `hrc`

The handle to the recognizer context.

### `pcRanges`

On input, the number of [CHARACTER_RANGE](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-character_range) structures the *pcr* buffer can contain. On output, the number of ranges the *pcr* buffer contains.

### `pcr`

An array of CHARACTER_RANGE structures. Each structure contains a range of Unicode points enabled on the context. The order of the array is arbitrary. To determine the size of the buffer, set *pcr* to **NULL**; use the number of ranges to allocate the *pcr* buffer.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | One of the parameters is an invalid pointer. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | An invalid argument was received. |
| **TPC_E_INSUFFICIENT_BUFFER** | The *pcr* buffer is too small. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## Remarks

This function is optional.

Some recognizers do not support enabling and disabling specific Unicode points, but may still include the **GetEnabledUnicodeRanges** function. For such recognizers the **GetEnabledUnicodeRanges** function returns the same ranges as the [GetUnicodeRanges](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-getunicoderanges) function.

Microsoft gesture recognizers use Unicode characters from 0xF000 to 0xF0FF. Each single Unicode value in this range represents a single gesture. For a complete list of Unicode values for gestures, see [Unicode Range Values of Gestures](https://learn.microsoft.com/windows/desktop/tablet/unicode-range-values-of-gestures).

## See also

[CHARACTER_RANGE Structure](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-character_range)

[GetUnicodeRanges Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-getunicoderanges)

[SetEnabledUnicodeRanges Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-setenabledunicoderanges)