# RtlUnicodeStringToAnsiString function

## Description

Converts the specified Unicode source string into an ANSI string.

## Parameters

### `DestinationString` [in, out]

A pointer to an **ANSI_STRING** structure to hold the converted ANSI string. If *AllocateDestinationString* is **TRUE**, the routine allocates a new buffer to hold the string data and updates the **Buffer** member of *DestinationString* to point to the new buffer. Otherwise, the routine uses the currently specified buffer to hold the string.

### `SourceString` [in]

The [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure that contains the source string to be converted to ANSI.

### `AllocateDestinationString` [in]

Controls allocation of the buffer space for the *DestinationString*.

#### TRUE

Buffer space is allocated for *DestinationString*. If set to **TRUE**, the buffer must be deallocated using [RtlFreeAnsiString](https://learn.microsoft.com/windows/desktop/api/winternl/nf-winternl-rtlfreeansistring).

#### FALSE

Buffer space is not allocated for *DestinationString*.

## Return value

The various NTSTATUS values are defined in NTSTATUS.H, which is distributed with the DDK.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The Unicode string was converted to ANSI. Otherwise, no storage was allocated and no conversion was done. |

## Remarks

The translation is done with respect to the
current system locale information.

Because there is no import library for this function, you must use [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress).