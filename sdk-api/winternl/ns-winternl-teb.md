# TEB structure

## Description

[This structure may be altered in future versions of Windows. Applications should use the alternate functions listed in this topic.]

The Thread Environment Block (TEB) structure describes the state of a thread.

## Members

### `Reserved1`

Reserved for internal use by the operating system.

### `ProcessEnvironmentBlock`

A pointer to the [PEB](https://learn.microsoft.com/windows/desktop/api/winternl/ns-winternl-peb) structure that contains information for the process as a whole.

### `Reserved2`

Reserved for internal use by the operating system.

### `Reserved3`

Reserved for internal use by the operating system.

### `TlsSlots`

Data for [Thread Local Storage](https://learn.microsoft.com/windows/win32/procthread/thread-local-storage). Call the [TlsGetValue](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-tlsgetvalue) function to access it.

### `Reserved4`

Reserved for internal use by the operating system.

### `Reserved5`

Reserved for internal use by the operating system.

### `ReservedForOle`

Do not use. Call [CoGetContextToken](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetcontexttoken) instead.

### `Reserved6`

Reserved for internal use by the operating system.

### `TlsExpansionSlots`

Additional data for [Thread Local Storage](https://learn.microsoft.com/windows/win32/procthread/thread-local-storage). Call the [TlsGetValue](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-tlsgetvalue) function to access it.

## Remarks

The definition of this structure may change from one version of Windows to the next. Do not assume a maximum size for this structure. To see the members of this structure, refer to [winternal.h](https://learn.microsoft.com/windows/win32/api/winternl/).

You should not directly access this structure. To access the values of the *TlsSlots* and *TlsExpansionSlots* fields, call [TlsGetValue](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-tlsgetvalue). To access the value of the *ReservedForOle* field, call [CoGetContextToken](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetcontexttoken).

In the following versions of Windows, the offset of the 32-bit TEB address within the 64-bit TEB is 0. This can be used to directly access the 32-bit TEB of a WOW64 thread. This might change in later versions of Windows.

|  |  |
| --- | --- |
| Windows Vista | Windows Server 2008 |
| Windows 7 | Windows Server 2008 R2 |
| Windows 8 | Windows Server 2012 |
| Windows 8.1 | Windows Server 2012 R2 |

## See also

[TlsGetValue](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-tlsgetvalue)