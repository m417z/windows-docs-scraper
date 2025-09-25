# RtlUpcaseUnicodeStringToCountedOemString function

## Description

The **RtlUpcaseUnicodeStringToCountedOemString** routine translates a given Unicode source string into an uppercase counted OEM string using the current system OEM code page.

## Parameters

### `DestinationString`

Pointer to a caller-allocated buffer to receive the counted OEM string. If **AllocateDestinationString** is FALSE, the caller must also allocate a buffer for the **Buffer** member of **DestinationString** to hold the OEM data. If **AllocateDestinationString** is TRUE, **RtlUpcaseUnicodeStringToCountedOemString** allocates a buffer large enough to hold the string, passes a pointer to it in **Buffer**, and updates the length and maximum length members of **DestinationString** accordingly.

### `SourceString` [in]

Pointer to the Unicode string to be translated.

### `AllocateDestinationString` [in]

Set to TRUE if **RtlUpcaseUnicodeStringToCountedOemString** should allocate the buffer space for the **DestinationString**, FALSE otherwise. If this parameter is TRUE, the caller is responsible for freeing the buffer when it is no longer needed by calling **RtlFreeOemString**.

## Return value

**RtlUpcaseUnicodeStringToCountedOemString** returns STATUS_SUCCESS if it returns a translated string at **DestinationString**. Otherwise, no storage was allocated, nor was any conversion performed. It returns STATUS_UNMAPPABLE_CHARACTER if it cannot translate a character in the given **SourceString**.

## Remarks

**RtlUpcaseUnicodeStringToCountedOemString** returns a string that is not null-terminated. It translates the given source string using the OEM code page that was installed as the current system code page at system boot time, and converts the translated string to uppercase.

To find a best-match mapping for any special characters, such as a copyright character, in the given source string, **RtlUpcaseUnicodeStringToCountedOemString** performs the following operations:

1. Translates a copy of the Unicode string at **SourceString** into an OEM string

2. Translates the OEM string back into Unicode

3. Converts this new Unicode string to uppercase

4. Translates the uppercase Unicode string into a counted OEM string and returns it at **DestinationString**

This routine does not modify the source string.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[**OEM_STRING**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff558741(v=vs.85))

[**RtlFreeOemString**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlfreeoemstring)

[**RtlOemStringToCountedUnicodeString**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtloemstringtocountedunicodestring)

[**RtlUnicodeStringToCountedOemString**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodestringtocountedoemstring)

[**RtlUnicodeStringToOemSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodestringtooemsize)

[**RtlUpcaseUnicodeStringToOemString**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlupcaseunicodestringtooemstring)

[**RtlUpcaseUnicodeToOemN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlupcaseunicodetooemn)

[**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)