## Description

Determines whether a record has been flat-read (that is, it's just a data buffer), or whether it has been parsed into its corresponding struct format.

## Parameters

### `pRecord`

Type: \_In\_ **[PDNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)**

A pointer to the [DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure to query about.

### `ullFlags`

Type: \_In\_ **[ULONG64](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Currently unused; exists for forward compatibility.

### `pfFlat`

Type: \_Out\_ **[BOOL](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

On completion of the function, if the record has been flat-read (that is, it's just a data buffer), then the value pointed to by *pfFlat* is `TRUE`; if the record has been parsed into its corresponding struct format, then the value pointed to by *pfFlat* is `FALSE`.

## Return value

On successful completion, returns a success confirmation. Otherwise, returns the appropriate DNS-specific error code, as defined in `winerror.h`.

## Remarks

## See also