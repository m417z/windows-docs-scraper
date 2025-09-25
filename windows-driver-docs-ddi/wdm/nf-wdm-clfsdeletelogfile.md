# ClfsDeleteLogFile function

## Description

The **ClfsDeleteLogFile** routine marks a CLFS stream for deletion.

## Parameters

### `puszLogFileName` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that supplies the name of the CLFS stream to be deleted.

If the stream to be deleted is the only stream of a dedicated log, the name has the form log:*physical log name*, where *physical log name* is the path name of the physical log on the underlying file system.

If the stream to be deleted is one of the streams of a multiplexed log, the name has the form log:*physical log name*::*stream name*, where *physical log name* is the path name of the physical log on the underlying file system and *stream name* is the unique name of the stream to be deleted.

### `pvReserved`

Reserved.

### `fLogOptionFlag` [in]

A value that indicates the relationship between CLFS and the component that is deleting the log. For a list of possible values, see the description of the *fLogOptionFlag* parameter of the **ClfsCreateLogFile** routine.

### `pvContext` [in, optional]

A pointer to a context. The way the context is interpreted depends on the value passed in *fLogOptionFlag*.

### `cbContext` [in]

The size, in bytes, of the context pointed to by *pvContex*t. If *pvContext* is not **NULL**, this parameter must be greater than zero.

## Return value

**ClfsDeleteLogFile** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

The Common Log File System (CLFS) uses the LOG_FILE_OBJECT structure to represent logs. The [ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile) function returns a pointer to LOG_FILE_OBJECT, which clients then pass to other CLFS functions.

CLFS clients do not directly access the members of a LOG_FILE_OBJECT structure. For information about the members, see [FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object).

**ClfsDeleteLogFile** marks a stream for deletion but does not close any log file objects that are currently open. To close a log file object, call [ClfsCloseLogFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscloselogfileobject). A stream marked for deletion is deleted after all log file objects associated with the stream are closed.

A CLFS stream marked for deletion will refuse subsequent requests to open the stream.

The name of a physical CLFS log does not include the .blf extension.

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[ClfsCloseAndResetLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscloseandresetlogfile)

[ClfsCloseLogFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscloselogfileobject)

[ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile)

[ClfsDeleteLogByPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsdeletelogbypointer)