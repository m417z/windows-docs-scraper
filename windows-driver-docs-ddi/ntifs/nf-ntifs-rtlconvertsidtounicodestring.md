# RtlConvertSidToUnicodeString function

## Description

The **RtlConvertSidToUnicodeString** routine generates a printable Unicode string representation of a security identifier ([SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)).

## Parameters

### `UnicodeString` [in, out]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure to contain the generated Unicode string. The *UnicodeString->MaximumLength* member is set only if *AllocateDestinationString* is **TRUE**.

### `Sid` [in]

A pointer to the SID structure that is to be converted to Unicode (the SID structure is unaffected).

### `AllocateDestinationString` [in]

A Boolean flag that indicates whether this routine will allocate the UnicodeString buffer. If **TRUE**, only the *UnicodeString->Buffer* member is allocated and the rest of the *UnicodeString* structure must be allocated by the caller.

## Return value

The **RtlConvertSidToUnicodeString** routine can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The conversion was successful. |
| **STATUS_BUFFER_OVERFLOW** | This is returned if *AllocateDestinationString* is **FALSE** and the caller supplied *UnicodeString* buffer is too small to hold the converted Unicode string. |
| **STATUS_NO_MEMORY** | This is returned if *AllocateDestinationString* is **TRUE** and there is insufficient memory to allocate the *UnicodeString* buffer. |
| **STATUS_INVALID_SID** | The specified *SID* structure is not structurally valid. |

## Remarks

The generated Unicode string will take one of two forms. If the value of the IdentifierAuthority member of the *SID* is less than or equal to 2^32, the IdentifierAuthority member will be generated as decimal. For example, a *SID* with an IdentifierAuthority of 281,736 generates:

```
 S-1-281736-12-72-9-110
```

Otherwise the IdentifierAuthority will be generated as hexadecimal. For example, a *SID* with an IdentifierAuthority of 173,495,281,736 generates:

```
 S-1-0x28651FE848-12-72-9-110
```

All other members in the *SID* will be generated as decimal.

If *AllocateDestinationString* is **TRUE**, the allocated buffer must be deallocated by using [RtlFreeUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfreeunicodestring).

## See also

[RtlFreeUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfreeunicodestring)

[SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)