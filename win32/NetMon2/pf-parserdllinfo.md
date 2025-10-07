# PF\_PARSERDLLINFO structure

The **PF\_PARSERDLLINFO** structure defines the parsers located in the parser DLL.

## Members

**nParsers**

Number of parsers in the parser DLL.

**ParserInfo**

Array of [PF\_PARSERINFO](https://learn.microsoft.com/windows/win32/netmon2/pf-parserinfo) structures that describe each parser in the parser DLL.

## Remarks

The **PF\_PARSERDLLINFO** structure is returned by the [ParserAutoInstallInfo](https://learn.microsoft.com/windows/win32/netmon2/parserautoinstallinfo) export function that is implemented in the parser DLL. The **ParserAutoInstallInfo** function identifies the number of parsers in the DLL, and uses an array of [PF\_PARSERINFO](https://learn.microsoft.com/windows/win32/netmon2/pf-parserinfo) structures to describe each parser.

The PF\_PARSERDLLINFO structure must be allocated using **HeapAlloc**.

| For information on | See |
|------------------------------------------------------------------|-----------------------------------------------------------------------------|
| What parsers are, and how they work with Network Monitor. | [Parsers](https://learn.microsoft.com/windows/win32/netmon2/parsers) |
| Which entry points are included in the parser DLL. | [Parser DLL Architecture](https://learn.microsoft.com/windows/win32/netmon2/parser-dll-architecture) |
| How to implement **ParserAutoInstallInfo** includes an example. | [Implementing ParserAutoIstallInfo](https://learn.microsoft.com/windows/win32/netmon2/implementing-parserautoinstallinfo) |

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[PF\_PARSERINFO](https://learn.microsoft.com/windows/win32/netmon2/pf-parserinfo)

[ParserAutoInstallInfo](https://learn.microsoft.com/windows/win32/netmon2/parserautoinstallinfo)

