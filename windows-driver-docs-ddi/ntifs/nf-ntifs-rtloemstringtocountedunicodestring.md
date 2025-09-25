# RtlOemStringToCountedUnicodeString function

## Description

The **RtlOemStringToCountedUnicodeString** routine translates the specified source string into a Unicode string using the current system OEM code page.

## Parameters

### `DestinationString`

Pointer to a caller-allocated buffer to receive the translated Unicode string. If *AllocateDestinationString* is **FALSE**, the caller must also allocate a buffer for the **Buffer** member of *DestinationString* to hold the Unicode data. If *AllocateDestinationString* is **TRUE**, **RtlOemStringToCountedUnicodeString** allocates a buffer large enough to hold the string, passes a pointer to it in **Buffer**, and updates the length and maximum length members of *DestinationString* accordingly.

### `SourceString` [in]

Pointer to the OEM string to be translated into Unicode.

### `AllocateDestinationString` [in]

Set to **TRUE** if **RtlOemStringToCountedUnicodeString** should allocate the buffer space for the *DestinationString*, **FALSE** otherwise. If this parameter is **TRUE**, the caller is responsible for freeing the buffer when it is no longer needed by calling **RtlFreeUnicodeString**.

## Return value

If the operation succeeds, **RtlOemStringToCountedUnicodeString** returns STATUS_SUCCESS. Otherwise, no storage was allocated and no conversion was done.

## Remarks

**RtlOemStringToCountedUnicodeString** returns a translated string that does not include NULL terminator. It translates the given source string using the OEM code page that was installed as the current system code page at boot time.

**RtlOemStringToCountedUnicodeString** does not modify the source string.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[OEM_STRING](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff558741(v=vs.85))

[RtlFreeUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfreeunicodestring)

[RtlOemStringToCountedUnicodeSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtloemstringtocountedunicodesize)

[RtlOemStringToCountedUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtloemstringtocountedunicodestring)

[RtlOemToUnicodeN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtloemtounicoden)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)