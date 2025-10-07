# CreatePropertyDatabase function

The **CreatePropertyDatabase** function creates a property database that stores the properties of a protocol.

## Parameters

*hProtocol* \[in\]

Handle of the protocol that is associated with the database. When Network Monitor calls the [Register](https://learn.microsoft.com/windows/win32/netmon2/register-parser) function, Network Monitor passes the protocol handle to the parser DLL.

*nProperties* \[in\]

Number of properties stored in the database. Set this parameter to the number of properties that the protocol supports.

## Return value

If the function is successful, the return value is NMERR\_SUCCESS.

If the function is unsuccessful, the return value is an error code.

| Return code | Description |
|---------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------|
| **NMERR\_INTERNAL\_ERROR** | An internal error has occurred.<br> |
| **NMERR\_INVALID\_HPOTOCOL** | The handle to the protocol specified in *hProtocol* is invalid.<br> |
| **NMERR\_OUT\_OF\_MEMORY** | Network Monitor does not have enough memory to create the database.<br> |

## Remarks

The **CreatePropertyDatabase** function should be called only when implementing the [Register](https://learn.microsoft.com/windows/win32/netmon2/register-parser) function. The parser uses **CreatePropertyDatabase** to create a property database that describes the properties of a protocol. Network Monitor uses the database to interpret the information within the protocol.

The **CreatePropertyDatabase** function allocates the structures that Network Monitor needs to maintain a property database.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

## See also

[Register](https://learn.microsoft.com/windows/win32/netmon2/register-parser)

