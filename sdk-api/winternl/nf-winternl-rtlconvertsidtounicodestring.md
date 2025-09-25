# RtlConvertSidToUnicodeString function

## Description

[The **RtlConvertSidToUnicodeString** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [ConvertSidToStringSid](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertsidtostringsida) function.]

The **RtlConvertSidToUnicodeString** function converts a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) to its Unicode character representation. This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Ntdll.dll.

## Parameters

### `UnicodeString` [out]

A pointer to the Unicode character representation of the security identifier.

### `Sid` [in]

A pointer to the [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure that represents the security identifier.

### `AllocateDestinationString` [in]

If **TRUE**, then *UnicodeString* is allocated on behalf of the caller, and it is the caller's responsibility to free the allocated memory by calling the **RtlFreeUnicodeString** function. If **FALSE**, the caller is responsible for allocating and freeing *UnicodeString*.

## Return value

The return value is an NTSTATUS code. A value of STATUS_SUCCESS (0x00000000L) is returned if the function succeeds.