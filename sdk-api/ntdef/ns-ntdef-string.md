# STRING structure

## Description

The **ANSI_STRING** structure defines a counted string used for ANSI strings.

## Members

### `Length`

The length in bytes of the string stored in the buffer pointed to by **Buffer**.

### `MaximumLength`

The length in bytes of the buffer pointed to by **Buffer**.

### `Buffer`

Pointer to a buffer used to contain a string of characters.

### `Buffer.size_is`

### `Buffer.size_is.MaximumLength`

### `Buffer.length_is`

### `Buffer.length_is.Length`

## Remarks

The **ANSI_STRING** structure is used to pass ANSI strings. Use the [RtlInitAnsiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-rtlinitansistring) routine to initialize an **ANSI_STRING**.

If the string is null-terminated, **Length** does not include the terminating **NULL**.

The **MaximumLength** is used to indicate the length of **Buffer** so that if the string is passed to a conversion routine such as [RtlUnicodeStringToAnsiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-rtlunicodestringtoansistring) the returned string does not exceed the buffer size.

## See also

[OEM_STRING](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff558741(v=vs.85))

[RtlAnsiStringToUnicodeSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-rtlansistringtounicodesize)

[RtlAnsiStringToUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-rtlansistringtounicodestring)

[RtlFreeAnsiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-rtlfreeansistring)

[RtlInitAnsiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-rtlinitansistring)

[RtlUnicodeStringToAnsiSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-rtlunicodestringtoansisize)

[RtlUnicodeStringToAnsiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-rtlunicodestringtoansistring)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)