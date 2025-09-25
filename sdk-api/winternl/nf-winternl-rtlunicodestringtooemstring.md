# RtlUnicodeStringToOemString function

## Description

Converts the specified Unicode source string into an OEM string. The translation is done with respect to the OEM code page (OCP).

## Parameters

### `DestinationString` [out]

A pointer to an [OEM_STRING](https://learn.microsoft.com/windows/desktop/api/winternl/ns-winternl-string) structure that is contains the OEM equivalent to the Unicode source string. The **MaximumLength** field is set if *AllocateDestinationString* is **TRUE**.

### `SourceString` [in]

A pointer to an [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure that is to be
converted to OEM.

### `AllocateDestinationString` [in]

Controls allocation of the buffer space for the destination
string.

#### TRUE

Buffer space is allocated for *DestinationString*. If set to **TRUE**, the buffer must be deallocated using [RtlFreeOemString](https://learn.microsoft.com/windows/desktop/api/winternl/nf-winternl-rtlfreeoemstring).

#### FALSE

Buffer space is not allocated for *DestinationString*.

## Return value

The various NTSTATUS values are defined in NTSTATUS.H, which is distributed with the Windows DDK.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The Unicode string was converted to OEM. Otherwise, no storage was allocated, and no conversion was done. |

## Remarks

This routine allocates a buffer for the *DestinationString* only.