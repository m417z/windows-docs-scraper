# RtlFreeUTF8String function

## Description

The **RtlFreeUTF8String** function releases storage that was allocated by [**RtlUnicodeStringToUTF8String**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlunicodestringtoutf8string).

## Parameters

### `utf8String`

Pointer to the UTF8 string buffer previously allocated by **RtlUnicodeStringToUTF8String**.

## Return value

## Remarks

This routine only releases the UTF8 string buffer passed to it; it does not release the Unicode string buffer passed to **RtlUnicodeStringToUTF8String**.

## See also

[**RtlUnicodeStringToUTF8String**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlunicodestringtoutf8string)