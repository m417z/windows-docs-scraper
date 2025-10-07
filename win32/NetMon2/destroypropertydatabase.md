# DestroyPropertyDatabase function

The **DestroyPropertyDatabase** function releases the resources used to create the protocol [*property database*](https://learn.microsoft.com/windows/win32/netmon2/p).

## Parameters

*hProtocol* \[in\]

Handle to the property database to be destroyed. The handle is passed to the parser DLL when Network Monitor calls the [Deregister](https://learn.microsoft.com/windows/win32/netmon2/deregister) function.

## Return value

If the function is successful, the return value is NMERR\_SUCCESS.

If the function is unsuccessful, the return value is an error code.

| Return code | Description |
|----------------------------------------------------------------------------------------------------------|--------------------------------------------|
| **NMERR\_INTERNAL\_ERROR** | An internal error occurred. <br> |
| **NMERR\_INVALID\_HPROTOCOL** | Invalid handle in *hProtocol*. <br> |

## Remarks

The **DestroyPropertyDatabase** function should be called only when implementing the [Deregister](https://learn.microsoft.com/windows/win32/netmon2/deregister) export function for the protocol. For parser DLLs that support multiple protocols, the **DestroyPropertyDatabase** function is called for each implementation of **Deregister**.

| For information on | See |
|-----------------------------------------------------------|--------------------------------------------------------|
| What parsers are, and how they work with Network Monitor. | [Parsers](https://learn.microsoft.com/windows/win32/netmon2/parsers) |
| Which entry points are included in the parser DLL. | [Parser DLL Architecture](https://learn.microsoft.com/windows/win32/netmon2/parser-dll-architecture) |
| How to implement **Deregister** includes an example. | [Implementing Deregister](https://learn.microsoft.com/windows/win32/netmon2/implementing-deregister) |

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

## See also

[Deregister](https://learn.microsoft.com/windows/win32/netmon2/deregister)

