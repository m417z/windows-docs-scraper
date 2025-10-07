# PF\_HANDOFFSET structure

The **PF\_HANDOFFSET** structure defines the protocols that hand off to the parser, or the protocols that the parser hands off to.

## Members

**nEntries**

Number of protocols.

**Entry**

An array of [PF\_HANDOFFENTRY](https://learn.microsoft.com/windows/win32/netmon2/pf-handoffentry) structures that define each protocol.

## Remarks

The [PF\_PARSERINFO](https://learn.microsoft.com/windows/win32/netmon2/pf-parserinfo) structure uses the **PF\_HANDOFFSET** structure to list the following:

- Which protocols hand off to the parser.
- Which protocols the parser hands off to.

The **PF\_HANDOFFSET** structure must be allocated using **HeapAlloc**.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[PF\_PARSERINFO](https://learn.microsoft.com/windows/win32/netmon2/pf-parserinfo)

[PF\_HANDOFFENTRY](https://learn.microsoft.com/windows/win32/netmon2/pf-handoffentry)

