# ClfsCloseLogFileObject function

## Description

The **ClfsCloseLogFileObject** routine releases all references to a log file object.

## Parameters

### `plfoLog` [in]

A pointer to the [LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure for which references will be released.The caller previously obtained this pointer by calling [ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile).

## Return value

**ClfsCloseLogFileObject** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

ClfsCloseLogFileObject releases all references, acquired by CLFS, to the specified log file object. Typically, the client will not have acquired any additional references to the log file object. However, if the client has obtained additional references, it is the client's responsibility to release them.

ClfsCloseLogFileObject causes the specified log file object's reference count to drop to zero, at which time the log file object is closed (that is, its memory is deallocated). The stream represented by the log file object might remain open, however, because there could be other log file objects that represent the same stream. The stream is closed after all log file objects that represent the stream are closed.

On return from this routine, *plfoLog* is invalid.

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[ClfsCloseAndResetLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscloseandresetlogfile)

[ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile)