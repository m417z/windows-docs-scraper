# NdisEqualUnicodeString macro

## Description

The
**NdisEqualUnicodeString** function compares two Unicode strings and returns whether they are
equal.

## Parameters

### `_String1` [in]

A pointer to an NDIS_STRING type that describes the first Unicode string.

### `_String2` [in]

A pointer to an NDIS_STRING type that describes the second Unicode string.

### `_CaseInsensitive`

A Boolean value that is **TRUE**, if case should be ignored when doing the comparison. Otherwise, it
is **FALSE**.

## Remarks

Starting with Windows 2000 and later drivers, a string of type NDIS_STRING is a counted,
null-terminated Unicode string. That is, NDIS defines the NDIS_STRING type as a
[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) type.

## See also

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)