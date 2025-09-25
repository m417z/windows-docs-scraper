# RtlUnicodeStringToCountedOemString function

## Description

The **RtlUnicodeStringToCountedOemString** routine translates the specified Unicode source string into a counted OEM string using the current system OEM code page.

## Parameters

### `DestinationString`

Pointer to a caller-allocated buffer to receive the counted OEM string. If *AllocateDestinationString* is **FALSE**, the caller must also allocate a buffer for the **Buffer** member of *DestinationString* to hold the OEM data. If *AllocateDestinationString* is **TRUE**, **RtlUnicodeStringToCountedOemString** allocates a buffer large enough to hold the string, passes a pointer to it in **Buffer**, and updates the length and maximum length members of *DestinationString* accordingly.

### `SourceString` [in]

Pointer to the source Unicode string to be translated.

### `AllocateDestinationString` [in]

Set to **TRUE** if **RtlUnicodeStringToCountedOemString** should allocate the buffer space for the *DestinationString*, **FALSE** otherwise. If this parameter is **TRUE**, the caller is responsible for freeing the buffer when it is no longer needed by calling **RtlFreeOemString**.

## Return value

**RtlUnicodeStringToCountedOemString** returns STATUS_SUCCESS if the string at *DestinationString* is translated. Otherwise, no storage was allocated, and no conversion was performed. This routine returns STATUS_UNMAPPABLE_CHARACTER if it cannot translate a character in the given *SourceString*.

## Remarks

**RtlUnicodeStringToCountedOemString** returns a translated string that does not include a NULL terminator. It translates the given source string using the OEM code page that was installed as the current system code page at system boot time.

**RtlUnicodeStringToCountedOemString** does not modify the source string.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[OEM_STRING](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff558741(v=vs.85))

[RtlFreeOemString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlfreeoemstring)

[RtlOemStringToCountedUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtloemstringtocountedunicodestring)

[RtlUnicodeStringToOemString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodestringtooemstring)

[RtlUnicodeToOemN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodetooemn)

[RtlUpcaseUnicodeStringToCountedOemString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlupcaseunicodestringtocountedoemstring)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)