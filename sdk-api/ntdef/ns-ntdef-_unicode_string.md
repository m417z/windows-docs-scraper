# _UNICODE_STRING structure

## Description

The **UNICODE_STRING** structure is used to define Unicode strings.

## Members

### `Length`

The length, in bytes, of the string stored in **Buffer**.

### `MaximumLength`

The length, in bytes, of **Buffer**.

### `Buffer`

Pointer to a buffer used to contain a string of wide characters.

## Syntax

```
typedef struct _UNICODE_STRING {
  USHORT Length;
  USHORT MaximumLength;
  PWSTR  Buffer;
} UNICODE_STRING, *PUNICODE_STRING;
```

## Remarks

The **UNICODE_STRING** structure is used to pass Unicode strings. Use [RtlUnicodeStringInit](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntstrsafe/nf-ntstrsafe-rtlunicodestringinit) or [RtlUnicodeStringInitEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntstrsafe/nf-ntstrsafe-rtlunicodestringinitex) to initialize a **UNICODE_STRING** structure.

If the string is null-terminated, **Length** does not include the trailing null character.

The **MaximumLength** is used to indicate the length of **Buffer** so that if the string is passed to a conversion routine such as [RtlAnsiStringToUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-rtlansistringtounicodestring) the returned string does not exceed the buffer size.

## See also

[ANSI_STRING](https://learn.microsoft.com/windows/desktop/api/ntdef/ns-ntdef-string)

[OEM_STRING](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff558741(v=vs.85))

[RtlAnsiStringToUnicodeSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-rtlansistringtounicodesize)

[RtlAnsiStringToUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-rtlansistringtounicodestring)

[RtlFreeUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-rtlfreeunicodestring)

[RtlInitUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-rtlinitunicodestring)

[RtlUnicodeStringToAnsiSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-rtlunicodestringtoansisize)

[RtlUnicodeStringToAnsiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-rtlunicodestringtoansistring)