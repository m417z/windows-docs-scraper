# NTSCSI_UNICODE_STRING structure

## Description

Storage port drivers can use the **NTSCSI_UNICODE_STRING** structure to define Unicode strings.

## Members

### `Length`

Length, in bytes, of the string stored in **Buffer**.

### `MaximumLength`

Total length, in bytes, of memory allocated for **Buffer**.

### `Buffer`

Pointer to a buffer used to contain a string of wide characters.

## Remarks

If the string is null-terminated, **Length** does not include the trailing null character.

**MaximumLength** is used to indicate the length of **Buffer** so that if the string is passed to a conversion routine, the returned string does not exceed the buffer size.

## See also

[UNICODE_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfwdm/ns-wudfwdm-_unicode_string)