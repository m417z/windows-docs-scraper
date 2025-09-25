# WER_DUMP_CUSTOM_OPTIONS_V2 structure

## Description

Specifies custom [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) minidump information to be collected by the [WerReportAddDump](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportadddump) function.

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

### `wzPreferredModuleList[WER_MAX_PREFERRED_MODULES_BUFFER]`

A list of module names (do not include the path) to which the **dwPreferredModuleFlags** flags apply. Each name must be null-terminated, and the list must be terminated with two null characters (for example, module1.dll\0module2.dll\0\0).

To specify that all modules are preferred, set this member to `*\0\0`. If you include `*` in a list with other module names, the `*` is ignored.

This member is valid only if **dwMask** contains WER_DUMP_MASK_PREFERRED_MODULE_LIST.

### `dwPreferredModuleResetFlags`

The preferred type of module information to include in the minidump for modules specified in the **wzPreferredModuleList** member. You can specify one or more of the [MODULE_WRITE_FLAGS](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ne-minidumpapiset-module_write_flags) flags.

This member is valid only if **dwMask** contains WER_DUMP_MASK_PREFERRED_MODULESFLAGS.

### `dwOtherModuleResetFlags`

Other types of module information to include in the minidump for modules specified in the **wzPreferredModuleList** member. You can specify one or more of the [MODULE_WRITE_FLAGS](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ne-minidumpapiset-module_write_flags) flags.

This member is valid only if **dwMask** contains WER_DUMP_MASK_PREFERRED_MODULESFLAGS.

## Remarks

## See also

[WerReportAddDump function](https://learn.microsoft.com/windows/win32/api/werapi/nf-werapi-werreportadddump), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)