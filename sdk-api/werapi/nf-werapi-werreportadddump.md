# WerReportAddDump function

## Description

Adds a dump of the specified type to the specified [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) report.

## Parameters

### `hReportHandle` [in]

A handle to the report. This handle is returned by the [WerReportCreate](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportcreate) function.

### `hProcess` [in]

A handle to the process for which the report is being generated. This handle must have the STANDARD_RIGHTS_READ and PROCESS_QUERY_INFORMATION access rights.

### `hThread` [in, optional]

A handle to the thread of *hProcess* for which the report is being generated. If *dumpType* is WerDumpTypeMicro, this parameter is required. For other dump types, this parameter may be **NULL**.

### `dumpType` [in]

The type of [minidump](https://learn.microsoft.com/windows/desktop/Debug/minidump-files). This parameter can be one of the following values from the **WER_DUMP_TYPE** enumeration type.

| Value | Meaning |
| --- | --- |
| **WerDumpTypeHeapDump** | An extended minidump that contains additional data such as the process memory. <br><br>This type is equivalent to creating a minidump with the following options:<br><br>* MiniDumpWithDataSegs<br>* MiniDumpWithProcessThreadData<br>* MiniDumpWithHandleData<br>* MiniDumpWithPrivateReadWriteMemory<br>* MiniDumpWithUnloadedModules<br>* MiniDumpWithFullMemoryInfo<br>* MiniDumpWithThreadInfo (Windows 7 and later)<br>* MiniDumpWithTokenInformation (Windows 7 and later)<br>* MiniDumpWithPrivateWriteCopyMemory (Windows 7 and later) |
| **WerDumpTypeMicroDump** | A limited minidump that contains only a stack trace. <br><br>This type is equivalent to creating a minidump with the following options:<br><br>* MiniDumpWithDataSegs<br>* MiniDumpWithUnloadedModules<br>* MiniDumpWithProcessThreadData<br>* MiniDumpWithoutOptionalData |
| **WerDumpTypeMiniDump** | A minidump. <br><br>This type is equivalent to creating a minidump with the following options:<br><br>* MiniDumpWithDataSegs<br>* MiniDumpWithUnloadedModules<br>* MiniDumpWithProcessThreadData<br>* MiniDumpWithTokenInformation (Windows 7 and later) |

### `pExceptionParam` [in, optional]

A pointer to a [WER_EXCEPTION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/werapi/ns-werapi-wer_exception_information) structure that specifies exception information.

### `pDumpCustomOptions` [in, optional]

A pointer to a [WER_DUMP_CUSTOM_OPTIONS](https://learn.microsoft.com/windows/desktop/api/werapi/ns-werapi-wer_dump_custom_options) structure that specifies custom minidump options. If this parameter is **NULL**, the standard minidump information is collected.

### `dwFlags` [in]

This parameter can be 0 or the following value.

| Value | Meaning |
| --- | --- |
| **WER_DUMP_NOHEAP_ONQUEUE** | If the report is being queued, do not include a heap dump. Using this flag saves disk space. |

## Return value

This function returns **S_OK** on success or an error code on failure.

## Remarks

Use this function only for generic reporting—it has no effect on operating system crash or no-response reporting.

If the server asks for a mini dump and you specify **WerDumpTypeHeapDump** for the *dumpType* parameter, WER will not send the heap dump to the Watson server. However, if the server asks for a heap dump and the *dumpType* is **WerDumpTypeMiniDump**, WER will send the mini dump to the server. Thus, it is recommended that you set *dumpType* to **WerDumpTypeMiniDump**.

## See also

[Minidump Files](https://learn.microsoft.com/windows/desktop/Debug/minidump-files), [WER_DUMP_CUSTOM_OPTIONS](https://learn.microsoft.com/windows/desktop/api/werapi/ns-werapi-wer_dump_custom_options), [WER_EXCEPTION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/werapi/ns-werapi-wer_exception_information), [WerReportCreate](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportcreate), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)