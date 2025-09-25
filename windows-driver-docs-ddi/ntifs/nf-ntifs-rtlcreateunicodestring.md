# RtlCreateUnicodeString function

## Description

The **RtlCreateUnicodeString** routine creates a new counted Unicode string.

## Parameters

### `DestinationString` [out]

Pointer to the newly allocated and initialized Unicode string.

### `SourceString` [in]

Pointer to a null-terminated Unicode string with which to initialize the new string.

## Return value

**RtlCreateUnicodeString** returns **TRUE** if the Unicode string was successfully created, **FALSE** otherwise.

## Remarks

The *DestinationString* is allocated from paged pool. The caller is responsible for freeing the *DestinationString* by calling **RtlFreeUnicodeString**.

For information about other string-handling routines, see the string manipulation functions in [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[RtlFreeUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfreeunicodestring)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)