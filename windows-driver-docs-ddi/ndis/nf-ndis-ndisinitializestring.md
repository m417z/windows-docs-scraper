# NdisInitializeString function

## Description

The **NdisInitializeString** function allocates storage for and initializes a counted string in the system-default character set.

## Parameters

### `Destination`

A pointer to an NDIS_STRING with a **NULL** buffer. On return from this function, the NDIS_STRING contains an initialized, counted string. For Windows 2000 and later, NDIS defines the NDIS_STRING type as a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) type.

### `Source`

A pointer to a null-terminated string with which to initialize the counted string. *SourceString* must not be **NULL**.

## Remarks

**NdisInitializeString** sets the **Length** and **MaximumLength** members of NDIS_STRING for the destination string and terminates the destination string with zero. For Windows 2000 and later drivers,**NdisInitializeString** converts the supplied source string to Unicode characters.

*SourceString* must not be **NULL**.

The buffer allocated by **NdisInitializeString** should be released with the [NdisFreeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreestring) function.

## See also

[ANSI_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string)

[DriverEntry of NDIS Protocol
Drivers](https://learn.microsoft.com/previous-versions/windows/embedded/gg156036(v=winembedded.80))

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[RtlAnsiStringToUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlansistringtounicodestring)

[RtlEqualUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlequalunicodestring)

[RtlFreeAnsiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfreeansistring)

[RtlFreeUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfreeunicodestring)

[RtlInitString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitstring)

[RtlInitUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitunicodestring)

[RtlUnicodeStringToAnsiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlunicodestringtoansistring)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)