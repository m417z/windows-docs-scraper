# PF\_FOLLOWSET structure

The **PF\_FOLLOWSET** structure defines the protocols that may precede or follow a protocol.

## Members

**nEntries**

Number of protocols in the list.

**Entry**

Array of [PF\_FOLLOWENTRY](https://learn.microsoft.com/windows/win32/netmon2/pf-followentry) structures that describe each protocol.

## Remarks

The [PF\_PARSERINFO](https://learn.microsoft.com/windows/win32/netmon2/pf-parserinfo) structure uses the **PF\_FOLLOWSET** structure to list the protocols that may precede or follow the protocol that the parser detects.

Network Monitor uses the information in the **PF\_FOLLOWSET** structure to update the follow sets of specific parsers. The **PF\_FOLLOWSET** structure must be allocated using **HeapAlloc**.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[PF\_FOLLOWENTRY](https://learn.microsoft.com/windows/win32/netmon2/pf-followentry)

[PF\_PARSERINFO](https://learn.microsoft.com/windows/win32/netmon2/pf-parserinfo)

