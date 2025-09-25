# SetEnabledUnicodeRanges function

## Description

Enables one or more Unicode point ranges on the context.

## Parameters

### `hrc`

The handle to the recognizer context.

### `cRanges`

The number of ranges in the *pRanges* buffer.

### `pcr`

An array of [CHARACTER_RANGE](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-character_range) structures. Each structure identifies a range of Unicode points that you want to enable in the recognizer. The order of the array is arbitrary.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **TPC_S_TRUNCATED** | The recognizer does not support one of the specified Unicode point ranges. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | An invalid argument was received. |
| **E_POINTER** | One of the parameters is an invalid pointer. |

## Remarks

The **SetEnabledUnicodeRanges** function is optional.

Some recognizers do not support enabling and disabling specific code points, but may still include the **SetEnabledUnicodeRanges** function. For such recognizers, the **SetEnabledUnicodeRanges** function returns E_NOTIMPL.

Each recognizer supports one or more Unicode point ranges. To determine which Unicode point ranges the recognizer supports, call the [GetUnicodeRanges](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-getunicoderanges) function. If you do not call this function, the recognizer uses a default set of Unicode point ranges. The default ranges are recognizer specific.

The Microsoft gesture recognizer uses Unicode characters from 0xF000 to 0xF0FF. Each single Unicode value in this range represents a single gesture. For a complete list of Unicode values for gestures, see [Unicode Range Values of Gestures](https://learn.microsoft.com/windows/desktop/tablet/unicode-range-values-of-gestures).

## See also

[CHARACTER_RANGE Structure](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-character_range)

[GetEnabledUnicodeRanges Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-getenabledunicoderanges)

[GetUnicodeRanges Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-getunicoderanges)