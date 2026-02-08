# KERB\_SMARTCARD\_CSP\_INFO structure

The **KERB\_SMARTCARD\_CSP\_INFO** structure contains information about a smart card [*cryptographic service provider*](https://learn.microsoft.com/windows/win32/secgloss/c-gly) (CSP).

This structure is not declared in a public header.

## Members

**dwCspInfoLen**

The size, in bytes, of this structure, including any appended data.

**MessageType**

The type of message being passed. This member must be set to 1.

**ContextInformation**

Reserved.

**SpaceHolderForWow64**

Reserved.

**flags**

Reserved.

**KeySpec**

The private key to use from the key container specified within the buffer **bBuffer**. The key can be one of the following values, defined in WinCrypt.h.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------|
| **AT\_KEYEXCHANGE**<br>1 | The key is a key-exchange key.<br> |
| **AT\_SIGNATURE**<br>2 | The key is a signature key.<br> |

**nCardNameOffset**

The number of characters in the **bBuffer** buffer that precede the name of the smart card in that buffer.

> [!IMPORTANT]
> If the name of the smart card is not provided, the buffer must contain an empty string.

**nReaderNameOffset**

The number of characters in the **bBuffer** buffer that precede the name of the smart card reader in that buffer.

> [!IMPORTANT]
> If the name of the smart card reader is not provided, the buffer must contain an empty string.

**nContainerNameOffset**

The number of characters in the **bBuffer** buffer that precede the name of the key container in that buffer. This string cannot be empty.

**nCSPNameOffset**

The number of characters in the **bBuffer** buffer that precede the name of the CSP in that buffer.

**bBuffer**

An array of characters initialized to a length of `sizeof(DWORD)`. This buffer contains the names referred to by the **nCardNameOffset**, **nReaderNameOffset**, **nContainerNameOffset**, and **nCSPNameOffset** members, as well as any additional data provided by the CSP.

Any names that are not provided must be represented in this buffer by empty strings.

## Remarks

**bBuffer layout**

The **bBuffer** begins with a DWORD-sized placeholder/prefix of `sizeof(DWORD)` bytes and then stores null-terminated strings for the card, reader, container, and CSP names (each may be an empty string except the container name which must be non-empty), followed by any CSP-specific extra data.

| Component (order from start of bBuffer) | Description | Requirement |
|---|---|---|
| DWORD prefix | Reserved placeholder (`sizeof(DWORD)` = 4 bytes) | Always present |
| CardName | Empty string or null-terminated card name | Optional |
| ReaderName | Empty string or null-terminated reader name | Optional |
| ContainerName | Null-terminated key container name | Required; must be non-empty |
| CSPName | Empty string or null-terminated CSP name | Optional |
| Additional data | CSP-specific appended data after names | Optional; CSP-defined format |

- **Offsets:** `nCardNameOffset`, `nReaderNameOffset`, `nContainerNameOffset`, and `nCSPNameOffset` are the number of characters from the start of `bBuffer` to the beginning of each respective string. These counts include the initial reserved `sizeof(DWORD)` region and are measured in `TCHAR` units (ANSI `char` or Unicode `wchar_t`, depending on build).
- **Empty names:** When a name is not provided, the buffer must contain an empty string (zero-length followed by the terminator) at that position.
- **Serialization alignment:** When serialized, structure members must be aligned to 2-byte boundaries.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |

## See also

[**KERB\_CERTIFICATE\_LOGON**](https://learn.microsoft.com/windows/desktop/api/Ntsecapi/ns-ntsecapi-kerb_certificate_logon)

