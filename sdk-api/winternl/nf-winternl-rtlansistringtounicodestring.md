# RtlAnsiStringToUnicodeString function

## Description

Converts the specified ANSI source string into a
Unicode string.

## Parameters

### `DestinationString` [in, out]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure to hold the converted Unicode string. If *AllocateDestinationString* is **TRUE**, the routine allocates a new buffer to hold the string data, and updates the **Buffer** member of *DestinationString* to point to the new buffer. Otherwise, the routine uses the currently specified buffer to hold the string.

### `SourceString` [in]

A pointer to the **ANSI_STRING** structure that contains the ANSI string to be converted to Unicode.

### `AllocateDestinationString` [in]

Controls allocation of buffer space for the destination string.

#### TRUE

Buffer space is allocated for *DestinationString*. If set to **TRUE**, the buffer must be deallocated using [RtlFreeUnicodeString](https://learn.microsoft.com/windows/desktop/api/winternl/nf-winternl-rtlfreeunicodestring).

#### FALSE

Buffer space is not allocated for *DestinationString*.

## Return value

The various NTSTATUS values are defined in NTSTATUS.H, which is distributed with the Windows DDK.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The ANSI string was converted to Unicode. On failure, the routine does not allocate any memory. |

## Remarks

The translation is done with respect to the
current system locale information.

If caller sets *AllocateDestinationString* to **TRUE**, the routine replaces the **Buffer** member of *DestinationString* with a pointer to the buffer it allocates. The old value can be overwritten even when the routine returns an error status code.

Because there is no import library for this function, you must use [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress).