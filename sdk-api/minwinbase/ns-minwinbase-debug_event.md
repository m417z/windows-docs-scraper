# DEBUG_EVENT structure

## Description

Describes a debugging event.

## Members

### `dwDebugEventCode`

Type: **DWORD**

The code that identifies the type of debugging event. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CREATE_PROCESS_DEBUG_EVENT**<br><br>3 | Reports a create-process debugging event (includes both a process and its main thread). The value of **u.CreateProcessInfo** specifies a [CREATE_PROCESS_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-create_process_debug_info) structure. |
| **CREATE_THREAD_DEBUG_EVENT**<br><br>2 | Reports a create-thread debugging event (does not include the main thread of a process, see `CREATE_PROCESS_DEBUG_EVENT`). The value of **u.CreateThread** specifies a [CREATE_THREAD_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-create_thread_debug_info) structure. |
| **EXCEPTION_DEBUG_EVENT**<br><br>1 | Reports an exception debugging event. The value of **u.Exception** specifies an [EXCEPTION_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-exception_debug_info) structure. |
| **EXIT_PROCESS_DEBUG_EVENT**<br><br>5 | Reports an exit-process debugging event. The value of **u.ExitProcess** specifies an [EXIT_PROCESS_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-exit_process_debug_info) structure. |
| **EXIT_THREAD_DEBUG_EVENT**<br><br>4 | Reports an exit-thread debugging event. The value of **u.ExitThread** specifies an [EXIT_THREAD_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-exit_thread_debug_info) structure. |
| **LOAD_DLL_DEBUG_EVENT**<br><br>6 | Reports a load-dynamic-link-library (DLL) debugging event. The value of **u.LoadDll** specifies a [LOAD_DLL_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-load_dll_debug_info) structure. |
| **OUTPUT_DEBUG_STRING_EVENT**<br><br>8 | Reports an output-debugging-string debugging event. The value of **u.DebugString** specifies an [OUTPUT_DEBUG_STRING_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-output_debug_string_info) structure. |
| **RIP_EVENT**<br><br>9 | Reports a RIP-debugging event (system debugging error). The value of **u.RipInfo** specifies a [RIP_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-rip_info) structure. |
| **UNLOAD_DLL_DEBUG_EVENT**<br><br>7 | Reports an unload-DLL debugging event. The value of **u.UnloadDll** specifies an [UNLOAD_DLL_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-unload_dll_debug_info) structure. |

### `dwProcessId`

Type: **DWORD**

The identifier of the process in which the debugging event occurred. A debugger uses this value to locate
the debugger's per-process structure. These values are not necessarily small integers that can be used as table
indices.

### `dwThreadId`

Type: **DWORD**

The identifier of the thread in which the debugging event occurred. A debugger uses this value to locate
the debugger's per-thread structure. These values are not necessarily small integers that can be used as table
indices.

### `u`

Any additional information relating to the debugging event. This union takes on the type and value
appropriate to the type of debugging event, as described in the **dwDebugEventCode**
member.

### `u.Exception`

Type: **[EXCEPTION_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-exception_debug_info)**

If the **dwDebugEventCode** is **EXCEPTION_DEBUG_EVENT** (1),
**u.Exception** specifies an
[EXCEPTION_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-exception_debug_info) structure.

### `u.CreateThread`

Type: **[CREATE_THREAD_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-create_thread_debug_info)**

If the **dwDebugEventCode** is **CREATE_THREAD_DEBUG_EVENT**
(2), **u.CreateThread** specifies an
[CREATE_THREAD_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-create_thread_debug_info)
structure.

### `u.CreateProcessInfo`

Type: **[CREATE_PROCESS_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-create_process_debug_info)**

If the **dwDebugEventCode** is **CREATE_PROCESS_DEBUG_EVENT**
(3), **u.CreateProcessInfo** specifies an
[CREATE_PROCESS_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-create_process_debug_info)
structure.

### `u.ExitThread`

Type: **[EXIT_THREAD_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-exit_thread_debug_info)**

If the **dwDebugEventCode** is **EXIT_THREAD_DEBUG_EVENT**
(4), **u.ExitThread** specifies an
[EXIT_THREAD_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-exit_thread_debug_info) structure.

### `u.ExitProcess`

Type: **[EXIT_PROCESS_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-exit_process_debug_info)**

If the **dwDebugEventCode** is **EXIT_PROCESS_DEBUG_EVENT**
(5), **u.ExitProcess** specifies an
[EXIT_PROCESS_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-exit_process_debug_info) structure.

### `u.LoadDll`

Type: **[LOAD_DLL_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-load_dll_debug_info)**

If the **dwDebugEventCode** is **LOAD_DLL_DEBUG_EVENT** (6),
**u.LoadDll** specifies an
[LOAD_DLL_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-load_dll_debug_info) structure.

### `u.UnloadDll`

Type: **[UNLOAD_DLL_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-unload_dll_debug_info)**

If the **dwDebugEventCode** is **UNLOAD_DLL_DEBUG_EVENT**
(7), **u.UnloadDll** specifies an
[UNLOAD_DLL_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-unload_dll_debug_info) structure.

### `u.DebugString`

Type: **[OUTPUT_DEBUG_STRING_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-output_debug_string_info)**

If the **dwDebugEventCode** is **OUTPUT_DEBUG_STRING_EVENT**
(8), **u.DebugString** specifies an
[OUTPUT_DEBUG_STRING_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-output_debug_string_info)
structure.

### `u.RipInfo`

Type: **[RIP_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-rip_info)**

If the **dwDebugEventCode** is **RIP_EVENT** (9),
**u.RipInfo** specifies an
[RIP_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-rip_info) structure.

## Remarks

If the [WaitForDebugEvent](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-waitfordebugevent) function succeeds, it
fills in the members of a **DEBUG_EVENT** structure.

## See also

[CREATE_PROCESS_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-create_process_debug_info)

[CREATE_THREAD_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-create_thread_debug_info)

[EXCEPTION_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-exception_debug_info)

[EXIT_PROCESS_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-exit_process_debug_info)

[EXIT_THREAD_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-exit_thread_debug_info)

[LOAD_DLL_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-load_dll_debug_info)

[OUTPUT_DEBUG_STRING_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-output_debug_string_info)

[UNLOAD_DLL_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-unload_dll_debug_info)

[WaitForDebugEvent](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-waitfordebugevent)