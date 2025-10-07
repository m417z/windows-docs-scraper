# PF\_PARSERINFO structure

The **PF\_PARSERINFO** structure defines one parser at a time. In the **PF\_PARSERINFO** structure, a parser is defined by the information about the protocol that the parser detects.

## Members

**szProtocolName**

Name of the protocol that the parser detects.

**szComment**

Brief description of the protocol.

**szHelpFile**

Name of the protocol Help file, if any.

**pWhoCanPrecedeMe**

Pointer to a [PF\_FOLLOWSET](https://learn.microsoft.com/windows/win32/netmon2/pf-followset) structure that lists the protocols that can precede the protocol the **PF\_PARSERINFO** structure describes. Network Monitor adds the parser protocol to the [*follow set*](https://learn.microsoft.com/windows/win32/netmon2/f) of all the protocols in the set.

**pWhoCanFollowMe**

Pointer to a [PF\_FOLLOWSET](https://learn.microsoft.com/windows/win32/netmon2/pf-followset) structure that lists the protocol that can follow the protocol the **PF\_PARSERINFO** structure describes. Network Monitor adds the protocols of the set to the [*follow set*](https://learn.microsoft.com/windows/win32/netmon2/f) of the parser protocol.

**pWhoHandsOffToMe**

Pointer to a [PF\_HANDOFFSET](https://learn.microsoft.com/windows/win32/netmon2/pf-handoffset) structure that hands-off to the protocol that the **PF\_PARSERINFO** structure describes. Network Monitor adds the parser protocol to the [*handoff sets*](https://learn.microsoft.com/windows/win32/netmon2/h) of all the protocols in the set.

**pWhoDoIHandOffTo**

Pointer to a [PF\_HANDOFFSET](https://learn.microsoft.com/windows/win32/netmon2/pf-handoffset) structure that lists the protocols that the parser protocol hands off to. Network Monitor adds the protocols of this set to the [*handoff set*](https://learn.microsoft.com/windows/win32/netmon2/h) of the parser protocol.

## Remarks

The **PF\_PARSERINFO** structure is used in the **PF\_PARSERDLLINFO** structure to provide a description of a parser. Network Monitor uses the parser description to update the [*Parser.ini*](https://learn.microsoft.com/windows/win32/netmon2/p) file, and the INI files of the parsers that precede and follow the protocol described in the **PF\_PARSERINFO** structure.

A follow set specifies the protocols that follow a protocol. Network Monitor uses a follow set when the parser cannot identify the next protocol from the data in a protocol instance. A follow set is stored in the [*Parser.ini*](https://learn.microsoft.com/windows/win32/netmon2/p) file. When the parser is installed for the first time, Network Monitor updates the follow set of the parser protocols that are listed in **pWhoCanPrecedeMe** and **pWhoCanFollowMe**.

A handoff set specifies the protocols that follow a protocol. The parser uses a handoff set only when the parser can identify the next protocol from the data in a protocol instance. A handoff set is stored in the INI files of each parser. When the parser is installed for the first time, Network Monitor updates the handoff set of the parser protocols that are listed in **pWhoHandsOffToMe** and **pWhoDoIHandOffTo**.

| For information on | See |
|------------------------------------------------------------------|------------------------------------------------------------------------------|
| What parsers are, and how they work with Network Monitor. | [Parsers](https://learn.microsoft.com/windows/win32/netmon2/parsers) |
| What follow sets contain. | [Specifying a Follow Set](https://learn.microsoft.com/windows/win32/netmon2/specifying-a-follow-set) |
| What handoff sets contain. | [Specifying a Handoff Set](https://learn.microsoft.com/windows/win32/netmon2/specifying-a-handoff-set) |
| What entry points are included in the parser DLL. | [Parser DLL Architecture](https://learn.microsoft.com/windows/win32/netmon2/parser-dll-architecture) |
| How to implement **ParserAutoInstallInfo** includes an example. | [Implementing ParserAutoInstallInfo](https://learn.microsoft.com/windows/win32/netmon2/implementing-parserautoinstallinfo) |

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[ParserAutoInstallInfo](https://learn.microsoft.com/windows/win32/netmon2/parserautoinstallinfo)

[PF\_FOLLOWSET](https://learn.microsoft.com/windows/win32/netmon2/pf-followset)

[PF\_HANDOFFSET](https://learn.microsoft.com/windows/win32/netmon2/pf-handoffset)

[PF\_PARSERDLLINFO](https://learn.microsoft.com/windows/win32/netmon2/pf-parserdllinfo)

