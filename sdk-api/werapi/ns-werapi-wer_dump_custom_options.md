# WER_DUMP_CUSTOM_OPTIONS structure

## Description

Specifies custom [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) minidump information to be collected by the [WerReportAddDump](https://learn.microsoft.com/windows/win32/api/werapi/nf-werapi-werreportadddump) function.

## Members

### `dwSize`

The size of the structure, in bytes.

### `dwMask`

A mask that controls which options are valid in this structure. You can specify one or more of the following values:

- WER_DUMP_MASK_DUMPTYPE
- WER_DUMP_MASK_ONLY_THISTHREAD
- WER_DUMP_MASK_OTHER_MODULESFLAGS
- WER_DUMP_MASK_OTHERTHREADFLAGS
- WER_DUMP_MASK_OTHERTHREADFLAGS_EX
- WER_DUMP_MASK_PREFERRED_MODULE_LIST
- WER_DUMP_MASK_PREFERRED_MODULESFLAGS
- WER_DUMP_MASK_THREADFLAGS
- WER_DUMP_MASK_THREADFLAGS_EX

### `dwDumpFlags`

The type information to include in the minidump. You can specify one or more of the [MINIDUMP_TYPE](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ne-minidumpapiset-minidump_type) flags.

This member is valid only if **dwMask** contains WER_DUMP_MASK_DUMPTYPE.

### `bOnlyThisThread`

If this member is **TRUE** and **dwMask** contains WER_DUMP_MASK_ONLY_THISTHREAD, the minidump is to be collected only for the calling thread.

### `dwExceptionThreadFlags`

The type of thread information to include in the minidump. You can specify one or more of the [THREAD_WRITE_FLAGS](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ne-minidumpapiset-thread_write_flags) flags.

This member is valid only if **dwMask** contains WER_DUMP_MASK_THREADFLAGS.

### `dwOtherThreadFlags`

The type of thread information to include in the minidump. You can specify one or more of the [THREAD_WRITE_FLAGS](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ne-minidumpapiset-thread_write_flags) flags.

This member is valid only if **dwMask** contains WER_DUMP_MASK_OTHERTHREADFLAGS.

### `dwExceptionThreadExFlags`

The type of thread information to include in the minidump. You can specify one or more of the [THREAD_WRITE_FLAGS](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ne-minidumpapiset-thread_write_flags) flags.

This member is valid only if **dwMask** contains WER_DUMP_MASK_THREADFLAGS_EX.

### `dwOtherThreadExFlags`

The type of thread information to include in the minidump. You can specify one or more of the [THREAD_WRITE_FLAGS](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ne-minidumpapiset-thread_write_flags) flags.

This member is valid only if **dwMask** contains WER_DUMP_MASK_OTHERTHREADFLAGS_EX.

### `dwPreferredModuleFlags`

The type of module information to include in the minidump for modules specified in the **wzPreferredModuleList** member. You can specify one or more of the [MODULE_WRITE_FLAGS](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ne-minidumpapiset-module_write_flags) flags.

This member is valid only if **dwMask** contains WER_DUMP_MASK_PREFERRED_MODULESFLAGS.

### `dwOtherModuleFlags`

The type of module information to include in the minidump. You can specify one or more of the [MODULE_WRITE_FLAGS](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ne-minidumpapiset-module_write_flags) flags.

This member is valid only if **dwMask** contains WER_DUMP_MASK_OTHER_MODULESFLAGS.

### `wzPreferredModuleList`

A list of module names (do not include the path) to which the **dwPreferredModuleFlags** flags apply. Each name must be null-terminated, and the list must be terminated with two null characters (for example, module1.dll\0module2.dll\0\0).

To specify that all modules are preferred, set this member to `*\0\0`. If you include `*` in a list with other module names, the `*` is ignored.

This member is valid only if **dwMask** contains WER_DUMP_MASK_PREFERRED_MODULE_LIST.

## Remarks

The flags specified in this structure have a direct correlation to flags passed in the [MINIDUMP_CALLBACK_ROUTINE callback function](https://learn.microsoft.com/windows/win32/api/minidumpapiset/nc-minidumpapiset-minidump_callback_routine) callback function (see [MiniDumpWriteDump function](https://learn.microsoft.com/windows/win32/api/minidumpapiset/nf-minidumpapiset-minidumpwritedump)) when WER generates the dump file.

If the minidump's callback input type is **ThreadCallback** (see the **CallbackType** member of [MINIDUMP_CALLBACK_INPUT structure](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_callback_input)), the **ThreadWriteFlags** member of [MINIDUMP_CALLBACK_OUTPUT structure](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_callback_output) is set to the flags specified in the **dwExceptionThreadFlags**, **dwExceptionThreadExFlags**, **dwOtherThreadFlags**, or **dwOtherThreadExFlags** members. If the callback is for the crashing thread, the **dwExceptionThreadFlags** or **dwExceptionThreadExFlags** flags are used; otherwise, the **dwOtherThreadFlags** or **dwOtherThreadExFlags** flags are used.

If the callback input type is **ModuleCallback**, the **ModuleWriteFlags** member of [MINIDUMP_CALLBACK_OUTPUT structure](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_callback_output) is set to the flags specified in the **dwPreferredModuleFlags** or **dwOtherModuleFlags** members. If the callback is for a module on the preferred modules list, the **dwPreferredModuleFlags** flags are used; otherwise, the **dwOtherModuleFlags** flags are used.

## See also

[WerReportAddDump function](https://learn.microsoft.com/windows/win32/api/werapi/nf-werapi-werreportadddump), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)