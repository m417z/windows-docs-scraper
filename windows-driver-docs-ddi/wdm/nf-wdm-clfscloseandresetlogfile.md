# ClfsCloseAndResetLogFile function

## Description

The **ClfsCloseAndResetLogFile** routine releases all references to a specified log file object and marks its associated stream for reset.

## Parameters

### `plfoLog` [in]

A pointer to a [LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure for which references will be released. The caller previously obtained this pointer by calling [ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile).

## Return value

**ClfsCloseAndResetLogFile** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

**ClfsCloseAndResetLogFile** releases all references, acquired by CLFS, to the specified log file object. Typically, the client will not have acquired any additional references to the log file object. However, if the client has obtained additional references, it is the client's responsibility to release them.

**ClfsCloseAndResetLogFile** causes the specified log file object's reference count to drop to zero, at which time the log file object is closed (that is, its memory is deallocated). The stream represented by the log file object might not be reset, however, because there could be other log file objects that represent the same stream. The stream is reset after all log file objects that represent the stream are closed (for example by calls to [ClfsCloseLogFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscloselogfileobject)).

A reset stream is like a newly created stream that has never had any records written to it.

On return from this routine, *plfoLog* is invalid.

You can call **ClfsCloseAndResetLogFile** at most 124 times for a given stream.

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[ClfsCloseLogFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscloselogfileobject)

[ClfsDeleteLogByPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsdeletelogbypointer)

[ClfsDeleteLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsdeletelogfile)