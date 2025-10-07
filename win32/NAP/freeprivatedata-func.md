# FreePrivateData function

> [!Note]
> The Network Access Protection platform is not available starting with Windows 10

The **FreePrivateData** function frees a [**PrivateData**](https://learn.microsoft.com/windows/win32/api/naptypes/ns-naptypes-privatedata) data structure.

## Parameters

*privateData* \[in\]

A pointer to the [**PrivateData**](https://learn.microsoft.com/windows/win32/api/naptypes/ns-naptypes-privatedata) data structure to free.

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

