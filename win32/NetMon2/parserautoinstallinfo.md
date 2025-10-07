# ParserAutoInstallInfo callback function

The **ParserAutoInstallInfo** export function identifies the parser, or parsers that are located in a DLL. **ParserAutoInstallInfo** should be implemented in all parser DLLs.

## Parameters

This callback function has no parameters.

## Return value

If the function is successful, the return value is a [PF\_PARSERDLLINFO](https://learn.microsoft.com/windows/win32/netmon2/pf-parserdllinfo) structure that describes the parsers in the DLL.

If the function is unsuccessful, the return value is **FALSE**.

## Remarks

When Network Monitor loads for the first time, it calls **ParserAutoInstallInfo** (if it exists) to automatically install each parser, and then enumerate all the parser DLLs in the parser subdirectory.

The information returned in the **PF\_PARSERDLLINFO** structure includes the following:

- The number of parsers in the DLL (typically one).
- The name and a brief description of the protocol that each parser detects.
- An optional Help file for each protocol.
- The protocols that precede each protocol.
- The protocols that follow each protocol.

Each parser DLL should contain one parser. However, Network Monitor allows you to create a DLL that contains more than one parser. For example, tcpip.dll is a Network Monitor DLL with more than one parser.

| For information on | See |
|------------------------------------------------------------------|------------------------------------------------------------------------------|
| What parsers are, and how they work with Network Monitor. | [Parsers](https://learn.microsoft.com/windows/win32/netmon2/parsers) |
| Which entry points are included in the parser DLL. | [Parser DLL Architecture](https://learn.microsoft.com/windows/win32/netmon2/parser-dll-architecture) |
| How to implement **ParserAutoInstallInfo** includes an example. | [Implementing ParserAutoInstallInfo](https://learn.microsoft.com/windows/win32/netmon2/implementing-parserautoinstallinfo) |

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[PF\_PARSERDLLINFO](https://learn.microsoft.com/windows/win32/netmon2/pf-parserdllinfo)

