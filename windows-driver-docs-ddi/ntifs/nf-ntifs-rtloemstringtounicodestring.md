# RtlOemStringToUnicodeString function

## Description

The **RtlOemStringToUnicodeString** routine translates a given source string into a null-terminated Unicode string using the current system OEM code page.

## Parameters

### `DestinationString`

Pointer to a caller-allocated buffer to receive the translated string. If *AllocateDestinationString* is **FALSE**, the caller must also allocate a buffer for the **Buffer** member of *DestinationString* to hold the null-terminated Unicode string. If *AllocateDestinationString* is **TRUE**, **RtlOemStringToUnicodeString** allocates a buffer large enough to hold the string, passes a pointer to it in **Buffer**, and updates the length and maximum length members of *DestinationString* accordingly.

### `SourceString` [in]

Pointer to the OEM string to be translated to Unicode.

### `AllocateDestinationString` [in]

Set to **TRUE** if **RtlOemStringToUnicodeString** should allocate the buffer space for the *DestinationString*, **FALSE** otherwise. If this parameter is **TRUE**, the caller is responsible for freeing the buffer when it is no longer needed by calling **RtlFreeUnicodeString**.

## Return value

**RtlOemStringToUnicodeString** returns STATUS_SUCCESS if it returns a translated string at *DestinationString*. Otherwise, no storage was allocated and no conversion was done.

## Remarks

**RtlOemStringToUnicodeString** translates the given source string using the OEM code page that was installed as the current system code page at system boot time.

This routine does not modify the source string. It returns a NULL-terminated Unicode string.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[OEM_STRING](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff558741(v=vs.85))

[RtlFreeUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfreeunicodestring)

[RtlOemStringToCountedUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtloemstringtocountedunicodestring)

[RtlOemStringToUnicodeSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtloemstringtounicodesize)

[RtlOemToUnicodeN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtloemtounicoden)

[RtlUnicodeStringToOemString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodestringtooemstring)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)