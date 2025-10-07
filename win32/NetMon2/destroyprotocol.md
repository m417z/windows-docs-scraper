# DestroyProtocol function

The **DestroyProtocol** function destroys the protocol that the **CreateProtocol** function creates.

## Parameters

*hProtocol* \[in\]

Handle to the protocol to be destroyed.

## Return value

None.

## Remarks

The parser DLL calls the **DestroyProtocol** function during its implementation of [DllMain](https://learn.microsoft.com/windows/win32/netmon2/dllmain-parser). **DestroyProtocol** is called when the operating system is going to unload the DLL.

| For information on | See |
|-----------------------------------------------------------|---------------------------------------------------------|
| What parsers are, and how they work with Network Monitor. | [Parsers](https://learn.microsoft.com/windows/win32/netmon2/parsers) |
| How to implement **DllMain** includes an example. | [Implementing DllMain](https://learn.microsoft.com/windows/win32/netmon2/implementing-dllmain-parser) |

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

## See also

[DllMain](https://learn.microsoft.com/windows/win32/netmon2/dllmain-parser)

