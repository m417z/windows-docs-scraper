# GetProtocolFromTable function

The **GetProtocolFromTable** function returns a handle to a protocol based on a given handoff table and value.

## Parameters

*hTable* \[in\]

Handle to a handoff table.

*ItemToFind* \[in\]

Value used to locate the protocol in a handoff table. The value must be available in the protocol data.

*lpInstData* \[out\]

If available in the handoff table, instance data for the next protocol. Instance data cannot be longer than a DWORD\_PTR in length.

## Return value

If the function is successful, the return value is a protocol handle.

If the function is unsuccessful, the return value is **NULL**.

## Remarks

When implementing the [RecognizeFrame](https://learn.microsoft.com/windows/win32/netmon2/recognizeframe) export function, the **GetProtocolFromTable** function is used to obtain a handle to the next protocol. The **GetProtocolFromTable** function is called to retrieve a handle from the next protocol if the protocol identifies which protocol follows.

**Instance data**

Instance data can be any data that is less than or equal to a DWORD\_PTR in length, or a pointer to data, such as raw frame data, that does not need to be allocated by or freed by the parser.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

## See also

[RecognizeFrame](https://learn.microsoft.com/windows/win32/netmon2/recognizeframe)

