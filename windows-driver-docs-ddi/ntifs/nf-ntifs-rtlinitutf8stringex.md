# RtlInitUTF8StringEx function (ntifs.h)

## Description

**RtlInitUTF8StringEx** initializes a counted string of UTF-8 characters.

## Parameters

### `DestinationString`

Pointer to the UTF8_STRING structure to be initialized. The *ntdef.h* header file defines this structure to be identical to the [ANSI_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string) structure.

### `SourceString`

Pointer to a null-terminated character string. *SourceString* is used to initialize the counted string that *DestinationString* points to.

## Return value

**RtlInitUTF8StringEx** returns STATUS_NAME_TOO_LONG if the *SourceString* is too long. Otherwise, this routine returns STATUS_SUCCESS.

## Remarks

**RtlInitUTF8StringEx** sets the members of the UTF8_STRING structure that *DestinationString* points to as follows:

- Copies the pointer value of *SourceString* into the **Buffer** member.

- Sets the **Length** member to the length, in bytes, of the source string, excluding the terminating null.

- Sets the **MaximumLength** member to the length, in bytes, of the source string, including the terminating null.

If *SourceString* is **NULL**, **Length** and **MaximumLength** are both set to zero.

**RtlInitStringEx** does not alter the source string pointed to by *SourceString*.

Callers of **RtlInitStringEx** can be running at IRQL <= DISPATCH_LEVEL if the *DestinationString* buffer is nonpageable. Usually, callers run at IRQL = PASSIVE_LEVEL because most other **Rtl*Xxx*String** routines cannot be called at IRQL > PASSIVE_LEVEL.

## See also

[ANSI_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string)