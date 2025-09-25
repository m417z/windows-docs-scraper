# ClfsDeleteLogByPointer function

## Description

The **ClfsDeleteLogByPointer** routine marks a CLFS stream for deletion.

## Parameters

### `plfoLog` [in]

A pointer to a [LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that represents an open instance of the stream to be deleted. The caller previously obtained this pointer by calling [ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile).

## Return value

**ClfsDeleteLogByPointer** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

**ClfsDeleteLogByPointer** marks a stream for deletion but does not close the log file object pointed to by *plfoLog*. To close a log file object, call [ClfsCloseLogFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscloselogfileobject). A stream marked for deletion is deleted after all log file objects associated with the stream are closed.

A CLFS stream marked for deletion will refuse subsequent requests to open the stream.

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile)

[ClfsDeleteLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsdeletelogfile)