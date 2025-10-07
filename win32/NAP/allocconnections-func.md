# AllocConnections function

> [!Note]
> The Network Access Protection platform is not available starting with Windows 10

The **AllocConnections** function allocates memory for a specified number of [**Connections**](https://learn.microsoft.com/windows/win32/nap/connections-struct) structures.

## Parameters

*connections* \[in, out\]

A pointer to an array of newly allocated [**Connections**](https://learn.microsoft.com/windows/win32/nap/connections-struct) structures.

*connectionsCount* \[in\]

The number of structures to allocate to *connections*.

## Return value

| Return code | Description |
|-----------------------------------------------------------------------------------------------|----------------------------------------------------------------------------|
| **S\_OK** | The operation has completed successfully.<br> |
| **E\_INVALIDARG** | An invalid argument was passed.<br> |
| **E\_OUTOFMEMORY** | The system is out of virtual memory. This operation has failed.<br> |

## Remarks

All the COM interfaces supported by the NAP system use standard COM memory management rules and the COM memory allocators (**CoTaskMemAlloc** and **CoTaskMemFree**):

- **In** parameters are allocated and freed by the caller.
- **Out** parameters are allocated by the callee and freed by the caller using **CoTaskMem**.
- **In/out** parameters are allocated by the caller, freed and reallocated by the callee, and ultimately freed by the caller, using **CoTaskMem**.

All NAP functions for freeing memory also free all embedded pointers.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | NapUtil.h |
| DLL<br> | Qutil.dll |

## See also

[**FreeConnections**](https://learn.microsoft.com/windows/win32/nap/freeconnections-func)

