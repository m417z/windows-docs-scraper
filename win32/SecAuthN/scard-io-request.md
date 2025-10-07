# SCARD\_IO\_REQUEST structure

The **SCARD\_IO\_REQUEST** structure begins a protocol control information structure. Any protocol-specific information then immediately follows this structure. The entire length of the structure must be aligned with the underlying hardware architecture word size. For example, in Win32 the length of any PCI information must be a multiple of four bytes so that it aligns on a 32-bit boundary.

## Members

**dwProtocol**

Protocol in use.

**cbPciLength**

Length, in bytes, of the **SCARD\_IO\_REQUEST** structure plus any following PCI-specific information.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Header<br> | Winsmcrd.h |

## See also

[**SCardTransmit**](https://learn.microsoft.com/windows/desktop/api/Winscard/nf-winscard-scardtransmit)

