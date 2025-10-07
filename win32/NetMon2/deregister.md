# Deregister callback function

The **Deregister** export function frees the resources used to create the protocol [*property database*](https://learn.microsoft.com/windows/win32/netmon2/p). The parser DLL must implement **Deregister**.

## Parameters

*hProtocol* \[in\]

Handle of the protocol for a specific database.

## Return value

None.

## Remarks

Network Monitor calls **Deregister** after passing all the capture information to the parser DLL. The parser DLL must implement a **Deregister** function for each protocol that the parser supports.

When implementing **Deregister**, the parser DLL must call the [DestroyPropertyDatabase](https://learn.microsoft.com/windows/win32/netmon2/destroypropertydatabase) function to release the [*property database*](https://learn.microsoft.com/windows/win32/netmon2/p) resources.

| For information on | See |
|-----------------------------------------------------------|--------------------------------------------------------|
| What parsers are, and how they work with Network Monitor. | [Parsers](https://learn.microsoft.com/windows/win32/netmon2/parsers) |
| Which entry points are included in the parser DLL. | [Parser DLL Architecture](https://learn.microsoft.com/windows/win32/netmon2/parser-dll-architecture) |
| How to implement **Deregister** includes an example. | [Implementing Deregister](https://learn.microsoft.com/windows/win32/netmon2/implementing-deregister) |

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[DestroyPropertyDatabase](https://learn.microsoft.com/windows/win32/netmon2/destroypropertydatabase)

