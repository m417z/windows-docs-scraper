# CreateProtocol function

The **CreateProtocol** function notifies Network Monitor that a specific protocol parser exists.

## Parameters

*ProtocolName* \[in\]

Name of the protocol the parser will detect.

*lpEntryPoints* \[in\]

An [ENTRYPOINTS](https://learn.microsoft.com/windows/win32/netmon2/entrypoints) structure that contains the remaining parser DLL entry points. See Remarks for a list of the export functions that each entry point references. Entry points must be provided in the order that the **ENTRYPOINTS** structure specifies.

*cbEntryPoints* \[in\]

The size of the **ENTRYPOINTS** structure. Network Monitor provides an ENTRYPOINTS\_SIZE macro that you can use to specify the size of the structure.

## Return value

If the function is successful, the return value is a handle to the protocol.

If the function is unsuccessful, the return value is **NULL**.

## Remarks

The parser DLL calls **CreateProtocol** during its implementation of [DllMain](https://learn.microsoft.com/windows/win32/netmon2/dllmain-parser). The **CreateProtocol** function is called when the operating system loads the parser DLL for the first time.

The entry points referenced in the *lpEntryPoints* parameter include pointers to the following export functions that must be provided in the order presented here.

- [Register](https://learn.microsoft.com/windows/win32/netmon2/register-parser)
- [Deregister](https://learn.microsoft.com/windows/win32/netmon2/deregister)
- [RecognizeFrame](https://learn.microsoft.com/windows/win32/netmon2/recognizeframe)
- [AttachProperties](https://learn.microsoft.com/windows/win32/netmon2/attachproperties)
- [FormatProperties](https://learn.microsoft.com/windows/win32/netmon2/formatproperties)

| For information on | See |
|----------------------------------------------------------------------------------------------------|---------------------------------------------------------|
| What parsers are, and how they work with Network Monitor. | [Parsers](https://learn.microsoft.com/windows/win32/netmon2/parsers) |
| How to implement **DllMain** includes an example of calling **CreateProtocol** within **DllMain**. | [Implementing DllMain](https://learn.microsoft.com/windows/win32/netmon2/implementing-dllmain-parser) |

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

## See also

[DllMain](https://learn.microsoft.com/windows/desktop/Dlls/dllmain)

