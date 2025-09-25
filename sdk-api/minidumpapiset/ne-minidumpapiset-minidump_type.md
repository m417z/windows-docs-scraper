# MINIDUMP_TYPE enumeration

## Description

Identifies the type of information that will be written to the minidump file by the
[MiniDumpWriteDump](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nf-minidumpapiset-minidumpwritedump) function.

**Important**

The minidump code has evolved greatly over the years since its inception. Many of the
constants listed on this page were added later and are not available in all versions of DbgHelp.dll.
Those that did not exist in the original code are labeled accordingly along with the version of DbgHelp.dll that
they first were implemented in. The listed version numbers corresponds to the
Debugging Tools For Windows releases and do not
apply to copies of DbgHelp.dll that are integrated into Windows. See
[DbgHelp Versions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-versions) for more details.

## Constants

### `MiniDumpNormal:0x00000000`

`0x00000000`. Include just the information necessary to capture stack traces for all existing threads in a process.

### `MiniDumpWithDataSegs:0x00000001`

`0x00000001`. Include the data sections from all loaded modules. This results in the inclusion of global variables, which
can make the minidump file significantly larger. For per-module control, use the
**ModuleWriteDataSeg** enumeration value from
[MODULE_WRITE_FLAGS](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-module_write_flags).

### `MiniDumpWithFullMemory:0x00000002`

`0x00000002`. Include all accessible memory in the process. The raw memory data is included at the end, so that the
initial structures can be mapped directly without the raw memory information. This option can result in a very
large file.

### `MiniDumpWithHandleData:0x00000004`

`0x00000004`. Include high-level information about the operating system handles that are active when the minidump is
made.

### `MiniDumpFilterMemory:0x00000008`

`0x00000008`. Stack and backing store memory written to the minidump file should be filtered to remove all but the
pointer values necessary to reconstruct a stack trace.

### `MiniDumpScanMemory:0x00000010`

`0x00000010`. Stack and backing store memory should be scanned for pointer references to modules in the module list. If a
module is referenced by stack or backing store memory, the **ModuleWriteFlags** member of
the [MINIDUMP_CALLBACK_OUTPUT](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_callback_output) structure is
set to **ModuleReferencedByMemory**.

### `MiniDumpWithUnloadedModules:0x00000020`

`0x00000020`. Include information from the list of modules that were recently unloaded, if this information is maintained
by the operating system.

**Windows Server 2003 and Windows XP:** The operating system does not maintain information for unloaded modules until
Windows Server 2003 with SP1 and Windows XP with SP2.

**DbgHelp 5.1:** This value is not supported.

### `MiniDumpWithIndirectlyReferencedMemory:0x00000040`

`0x00000040`. Include pages with data referenced by locals or other stack memory. This option can increase the size of
the minidump file significantly.

**DbgHelp 5.1:** This value is not supported.

### `MiniDumpFilterModulePaths:0x00000080`

`0x00000080`. Filter module paths for information such as user names or important directories. This option may prevent
the system from locating the image file and should be used only in special situations.

**DbgHelp 5.1:** This value is not supported.

### `MiniDumpWithProcessThreadData:0x00000100`

`0x00000100`. Include complete per-process and per-thread information from the operating system.

**DbgHelp 5.1:** This value is not supported.

### `MiniDumpWithPrivateReadWriteMemory:0x00000200`

`0x00000200`. Scan the virtual address space for **PAGE_READWRITE** memory to be included.

**DbgHelp 5.1:** This value is not supported.

### `MiniDumpWithoutOptionalData:0x00000400`

`0x00000400`. Reduce the data that is dumped by eliminating memory regions that are not essential to meet criteria
specified for the dump. This can avoid dumping memory that may contain data that is private to the user.
However, it is not a guarantee that no private information will be present.

**DbgHelp 6.1 and earlier:** This value is not supported.

### `MiniDumpWithFullMemoryInfo:0x00000800`

`0x00000800`. Include memory region information. For more information, see
[MINIDUMP_MEMORY_INFO_LIST](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_memory_info_list).

**DbgHelp 6.1 and earlier:** This value is not supported.

### `MiniDumpWithThreadInfo:0x00001000`

`0x00001000`. Include thread state information. For more information, see
[MINIDUMP_THREAD_INFO_LIST](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_thread_info_list).

**DbgHelp 6.1 and earlier:** This value is not supported.

### `MiniDumpWithCodeSegs:0x00002000`

`0x00002000`. Include all code and code-related sections from loaded modules to capture executable content. For
per-module control, use the **ModuleWriteCodeSegs** enumeration value from
[MODULE_WRITE_FLAGS](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-module_write_flags).

**DbgHelp 6.1 and earlier:** This value is not supported.

### `MiniDumpWithoutAuxiliaryState:0x00004000`

`0x00004000`. Turns off secondary auxiliary-supported memory gathering.

### `MiniDumpWithFullAuxiliaryState:0x00008000`

`0x00008000`. Requests that auxiliary data providers include their state in the dump image; the state data that is
included is provider dependent. This option can result in a large dump image.

### `MiniDumpWithPrivateWriteCopyMemory:0x00010000`

`0x00010000`. Scans the virtual address space for **PAGE_WRITECOPY** memory to be included.

**Prior to DbgHelp 6.1:** This value is not supported.

### `MiniDumpIgnoreInaccessibleMemory:0x00020000`

`0x00020000`. If you specify **MiniDumpWithFullMemory**, the
[MiniDumpWriteDump](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nf-minidumpapiset-minidumpwritedump) function will fail if the
function cannot read the memory regions; however, if you include
**MiniDumpIgnoreInaccessibleMemory**, the
**MiniDumpWriteDump** function will ignore the memory
read failures and continue to generate the dump. Note that the inaccessible memory regions are not included in
the dump.

**Prior to DbgHelp 6.1:** This value is not supported.

### `MiniDumpWithTokenInformation:0x00040000`

`0x00040000`. Adds security token related data. This will make the "!token" extension work when
processing a user-mode dump.

**Prior to DbgHelp 6.1:** This value is not supported.

### `MiniDumpWithModuleHeaders:0x00080000`

`0x00080000`. Adds module header related data.

**Prior to DbgHelp 6.1:** This value is not supported.

### `MiniDumpFilterTriage:0x00100000`

`0x00100000`. Adds filter triage related data.

**Prior to DbgHelp 6.1:** This value is not supported.

### `MiniDumpWithAvxXStateContext:0x00200000`

`0x00200000`. Adds AVX crash state context registers.

**Prior to DbgHelp 6.1:** This value is not supported.

### `MiniDumpWithIptTrace:0x00400000`

`0x00400000`. Adds Intel Processor Trace related data.

**Prior to DbgHelp 6.1:** This value is not supported.

### `MiniDumpScanInaccessiblePartialPages:0x00800000`

`0x00800000`. Scans inaccessible partial memory pages.

**Prior to DbgHelp 6.1:** This value is not supported.

### `MiniDumpValidTypeFlags:0x01ffffff`

`0x00ffffff`. Indicates which flags are valid.

## See also

[MiniDumpWriteDump](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nf-minidumpapiset-minidumpwritedump)