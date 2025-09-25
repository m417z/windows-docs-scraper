# MODULE_WRITE_FLAGS enumeration

## Description

Identifies the type of module information that will be written to the minidump file by the
[MiniDumpWriteDump](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nf-minidumpapiset-minidumpwritedump) function.

## Constants

### `ModuleWriteModule:0x0001`

Only module information will be written to the minidump file.

### `ModuleWriteDataSeg:0x0002`

Module and data segment information will be written to the minidump file. This value will only be set if the **MiniDumpWithDataSegs** enumeration value from [MINIDUMP_TYPE](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-minidump_type) is set.

### `ModuleWriteMiscRecord:0x0004`

Module, data segment, and miscellaneous record information will be written to the minidump file.

### `ModuleWriteCvRecord:0x0008`

CodeView information will be written to the minidump file. Some debuggers need the CodeView information to properly locate symbols.

### `ModuleReferencedByMemory:0x0010`

Indicates that a module was referenced by a pointer on the stack or backing store of a thread in the minidump. This value is valid only if the *DumpType* parameter of the
[MiniDumpWriteDump](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nf-minidumpapiset-minidumpwritedump) function includes **MiniDumpScanMemory**.

### `ModuleWriteTlsData:0x0020`

Per-module automatic TLS data is written to the minidump file. (Note that automatic TLS data is created using **__declspec(thread)** while [TlsAlloc](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-tlsalloc) creates dynamic TLS data). This value is valid only if the *DumpType* parameter of the
[MiniDumpWriteDump](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nf-minidumpapiset-minidumpwritedump) function includes **MiniDumpWithProcessThreadData**.

**DbgHelp 6.1 and earlier:** This value is not supported.

### `ModuleWriteCodeSegs:0x0040`

Code segment information will be written to the minidump file. This value will only be set if the **MiniDumpWithCodeSegs** enumeration value from [MINIDUMP_TYPE](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-minidump_type) is set.

**DbgHelp 6.1 and earlier:** This value is not supported.

## See also

[MINIDUMP_CALLBACK_OUTPUT](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_callback_output)

[MiniDumpWriteDump](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nf-minidumpapiset-minidumpwritedump)