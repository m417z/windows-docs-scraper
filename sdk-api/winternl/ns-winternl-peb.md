# PEB structure

## Description

[This structure may be altered in future versions of Windows.]

Contains process information.

## Members

### `Reserved1`

Reserved for internal use by the operating system.

### `BeingDebugged`

Indicates whether the specified process is currently being debugged. The **PEB** structure, however, is an internal operating-system structure whose layout may change in the future. It is best to use the [CheckRemoteDebuggerPresent](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-checkremotedebuggerpresent) function instead.

### `Reserved2`

Reserved for internal use by the operating system.

### `Reserved3`

Reserved for internal use by the operating system.

### `Ldr`

A pointer to a [PEB_LDR_DATA](https://learn.microsoft.com/windows/desktop/api/winternl/ns-winternl-peb_ldr_data) structure that contains information about the loaded modules for the process.

### `ProcessParameters`

A pointer to an [RTL_USER_PROCESS_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winternl/ns-winternl-rtl_user_process_parameters) structure that contains process parameter information such as the command line.

### `Reserved4`

Reserved for internal use by the operating system.

### `AtlThunkSListPtr`

### `Reserved5`

Reserved for internal use by the operating system.

### `Reserved6`

Reserved for internal use by the operating system.

### `Reserved7`

Reserved for internal use by the operating system.

### `Reserved8`

### `AtlThunkSListPtr32`

### `Reserved9`

### `Reserved10`

### `PostProcessInitRoutine`

Not supported.

### `Reserved11`

### `Reserved12`

### `SessionId`

The Terminal Services session identifier associated with the current process.

## Remarks

The syntax for this structure on 64-bit Windows is as follows:

``` syntax
typedef struct _PEB {
    BYTE Reserved1[2];
    BYTE BeingDebugged;
    BYTE Reserved2[21];
    PPEB_LDR_DATA LoaderData;
    PRTL_USER_PROCESS_PARAMETERS ProcessParameters;
    BYTE Reserved3[520];
    PPS_POST_PROCESS_INIT_ROUTINE PostProcessInitRoutine;
    BYTE Reserved4[136];
    ULONG SessionId;
} PEB;
```

## See also

[NtQueryInformationProcess](https://learn.microsoft.com/windows/desktop/api/winternl/nf-winternl-ntqueryinformationprocess)

[ZwQueryInformationProcess](https://learn.microsoft.com/windows/desktop/ProcThread/zwqueryinformationprocess)

[TEB](https://learn.microsoft.com/windows/win32/api/winternl/ns-winternl-teb)

[PEB_LDR_DATA](https://learn.microsoft.com/windows/desktop/api/winternl/ns-winternl-peb_ldr_data)

[RTL_USER_PROCESS_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winternl/ns-winternl-rtl_user_process_parameters)