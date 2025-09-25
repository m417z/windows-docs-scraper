# GetUnicodeRanges function

## Description

Returns the ranges of Unicode points that the recognizer supports.

## Parameters

### `hrec`

Handle to the recognizer.

### `pcRanges`

On input, the number of ranges the *pcr* buffer can hold. On output, the number of ranges the *pcr* buffer contains.

### `pcr`

Array of [CHARACTER_RANGE](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-character_range) structures. Each structure contains a range of Unicode points that the recognizer supports. The order of the array is arbitrary. To determine the required size of the buffer, set *pcr* to **NULL**; use the number of ranges to allocate the *pcr* buffer.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | One of the parameters is an invalid pointer. |
| **TPC_E_INSUFFICIENT_BUFFER** | The *pcr* buffer is too small. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | An invalid argument was received. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## Remarks

This function is optional.

Some recognizers do not support this capability, but may still include the **GetUnicodeRanges Function** function. For such recognizers the **GetUnicodeRanges** function returns E_NOTIMPL.

To control the Unicode ranges used by a specific recognizer context, use the [GetEnabledUnicodeRanges](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-getenabledunicoderanges) and [SetEnabledUnicodeRanges](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-setenabledunicoderanges) functions. These ranges are constrained to be a subset of the ranges returned by **GetUnicodeRanges**.

Microsoft gesture recognizers use Unicode characters from 0xF000 to 0xF0FF. Each single Unicode value in this range represents a single gesture. For a complete list of Unicode values for gestures, see [Unicode Range Values of Gestures](https://learn.microsoft.com/windows/desktop/tablet/unicode-range-values-of-gestures).

## See also

[GetEnabledUnicodeRanges Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-getenabledunicoderanges)

[SetEnabledUnicodeRanges Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-setenabledunicoderanges)