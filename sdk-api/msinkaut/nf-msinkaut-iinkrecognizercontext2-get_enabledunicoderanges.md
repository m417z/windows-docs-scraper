# IInkRecognizerContext2::get_EnabledUnicodeRanges

## Description

Gets or sets a set of one or more Unicode ranges that the recognizer context will support.

This property is read/write.

## Parameters

## Remarks

Use this method to specify a sub-set of Unicode character ranges that the recognizer should use during recognition. This is particularly useful when working with Asian character set where only a sub-set of the characters are commonly used.

Your application should check whether all input ranges are supported by the recognizer. TPC_S_TRUNCATED is returned to indicate that the Unicode ranges passed in were accepted, with the exception of those which were not valid. You can call **get_EnabledUnicodeRanges** to determine the ranges that were accepted.

## See also

[IInkRecognizerContext2 Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognizercontext2)