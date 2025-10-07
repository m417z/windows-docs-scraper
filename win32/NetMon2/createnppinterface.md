# CreateNPPInterface function

The **CreateNPPInterface** function uses the BLOB returned from the finder to create an NPP that the application can use.

## Parameters

*hBlob* \[in\]

Handle to the BLOB returned from the finder.

*iid* \[in\]

Identifier of the interface that you call from the NPP (**IRTC** or **IDelaydC**, for example).

*ppvObject* \[out\]

Pointer to the returned pointer to the requested interface.

## Return value

If the function is successful, the return value is NMERR\_SUCCESS.

If the function is unsuccessful, the return value is a NMERR value that describes the error.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Npptools.lib |
| DLL<br> | Npptools.dll |

