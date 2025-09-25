# IInkRecognizer2::get_UnicodeRanges

## Description

Retrieves the Unicode ranges set for the current recognizer.

## Parameters

### `UnicodeRanges` [out]

A VARIANT array containing the Unicode ranges being used by the recognizer. An array (VT_ARRAY) of long integers (VT_ARRAY|VT_UI4). The array consists of alternating pairs for each range. For each pair in the array, the first value specifies the low Unicode code point in the range of supported Unicode points, and the second value specifies the number of Unicode points in the range.

## Return value

This method can return one of these values.

## See also

[IInkRecognizer2 Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognizer2)