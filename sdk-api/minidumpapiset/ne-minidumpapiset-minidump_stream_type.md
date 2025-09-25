# MINIDUMP_STREAM_TYPE enumeration

## Description

Represents the type of a minidump data stream.

## Constants

### `UnusedStream:0`

Reserved. Do not use this enumeration value.

### `ReservedStream0:1`

Reserved. Do not use this enumeration value.

### `ReservedStream1:2`

Reserved. Do not use this enumeration value.

### `ThreadListStream:3`

The stream contains thread information. For more information, see
[MINIDUMP_THREAD_LIST](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_thread_list).

### `ModuleListStream:4`

The stream contains module information. For more information, see
[MINIDUMP_MODULE_LIST](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_module_list).

### `MemoryListStream:5`

The stream contains memory allocation information. For more information, see
[MINIDUMP_MEMORY_LIST](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_memory_list).

### `ExceptionStream:6`

The stream contains exception information. For more information, see
[MINIDUMP_EXCEPTION_STREAM](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_exception_stream).

### `SystemInfoStream:7`

The stream contains general system information. For more information, see
[MINIDUMP_SYSTEM_INFO](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_system_info).

### `ThreadExListStream:8`

The stream contains extended thread information. For more information, see
[MINIDUMP_THREAD_EX_LIST](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_thread_ex_list).

### `Memory64ListStream:9`

The stream contains memory allocation information. For more information, see
[MINIDUMP_MEMORY64_LIST](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_memory64_list).

### `CommentStreamA:10`

The stream contains an ANSI string used for documentation purposes.

### `CommentStreamW:11`

The stream contains a Unicode string used for documentation purposes.

### `HandleDataStream:12`

The stream contains high-level information about the active operating system handles. For more information, see
[MINIDUMP_HANDLE_DATA_STREAM](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_handle_data_stream).

### `FunctionTableStream:13`

The stream contains function table information. For more information, see
[MINIDUMP_FUNCTION_TABLE_STREAM](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_function_table_stream).

### `UnloadedModuleListStream:14`

The stream contains module information for the unloaded modules. For more information, see
[MINIDUMP_UNLOADED_MODULE_LIST](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_unloaded_module_list).

**DbgHelp 5.1:** This value is not supported.

### `MiscInfoStream:15`

The stream contains miscellaneous information. For more information, see
[MINIDUMP_MISC_INFO](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_misc_info) or [MINIDUMP_MISC_INFO_2](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_misc_info_2).

**DbgHelp 5.1:** This value is not supported.

### `MemoryInfoListStream:16`

The stream contains memory region description information. It corresponds to the information that would be returned for the process from the [VirtualQuery](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_memory_info_list) function. For more information, see [MINIDUMP_MEMORY_INFO_LIST](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_memory_info_list).

**DbgHelp 6.1 and earlier:** This value is not supported.

### `ThreadInfoListStream:17`

The stream contains thread state information. For more information, see [MINIDUMP_THREAD_INFO_LIST](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_thread_info_list).

**DbgHelp 6.1 and earlier:** This value is not supported.

### `HandleOperationListStream:18`

This stream contains operation list information. For more information, see [MINIDUMP_HANDLE_OPERATION_LIST](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_handle_operation_list).

**DbgHelp 6.4 and earlier:** This value is not supported.

### `TokenStream:19`

### `JavaScriptDataStream:20`

### `SystemMemoryInfoStream:21`

### `ProcessVmCountersStream:22`

### `IptTraceStream:23`

### `ThreadNamesStream:24`

### `ceStreamNull:0x8000`

### `ceStreamSystemInfo:0x8001`

### `ceStreamException:0x8002`

### `ceStreamModuleList:0x8003`

### `ceStreamProcessList:0x8004`

### `ceStreamThreadList:0x8005`

### `ceStreamThreadContextList:0x8006`

### `ceStreamThreadCallStackList:0x8007`

### `ceStreamMemoryVirtualList:0x8008`

### `ceStreamMemoryPhysicalList:0x8009`

### `ceStreamBucketParameters:0x800A`

### `ceStreamProcessModuleMap:0x800B`

### `ceStreamDiagnosisList:0x800C`

### `LastReservedStream:0xffff`

Any value greater than this value will not be used by the system and can be used to represent application-defined data streams. For more information, see
[MINIDUMP_USER_STREAM](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_user_stream).

## Remarks

In this context, a data stream is a set of data in a minidump file.

The **StreamType** member of the
[MINIDUMP_DIRECTORY](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_directory) structure can be one of these types. Additional types may be added in the future, so if a program reading the minidump header encounters a stream type it does not recognize, it should ignore the stream altogether.

## See also

[MINIDUMP_DIRECTORY](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_directory)

[MINIDUMP_EXCEPTION_STREAM](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_exception_stream)

[MINIDUMP_FUNCTION_TABLE_STREAM](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_function_table_stream)

[MINIDUMP_HANDLE_DATA_STREAM](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_handle_data_stream)

[MINIDUMP_HANDLE_OPERATION_LIST](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_handle_operation_list)

[MINIDUMP_MEMORY_INFO_LIST](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_memory_info_list)

[MINIDUMP_MEMORY_LIST](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_memory_list)

[MINIDUMP_MISC_INFO](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_misc_info)

[MINIDUMP_MODULE_LIST](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_module_list)

[MINIDUMP_SYSTEM_INFO](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_system_info)

[MINIDUMP_THREAD_EX_LIST](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_thread_ex_list)

[MINIDUMP_THREAD_INFO_LIST](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_thread_info_list)

[MINIDUMP_THREAD_LIST](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_thread_list)

[MINIDUMP_UNLOADED_MODULE_LIST](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_unloaded_module_list)

[MINIDUMP_USER_STREAM](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_user_stream)