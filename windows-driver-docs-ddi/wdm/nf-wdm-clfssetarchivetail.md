# ClfsSetArchiveTail function

## Description

The **ClfsSetArchiveTail** routine sets the archive tail of a CLFS log to a specified LSN.

## Parameters

### `plfoLog` [in]

A pointer to a [LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that represents a CLFS log. The caller previously obtained this pointer by calling [ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile).

### `plsnArchiveTail` [in]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_lsn) structure that specifies the LSN that is to become the new archive tail. This must be the exact LSN of a record in the log.

## Return value

**ClfsSetArchiveTail** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

The *plsnArchiveTail* value specifies where archiving starts in the log. The next archiving will start at or before this LSN.

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[ClfsAdvanceLogBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsadvancelogbase)

[ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile)

[ClfsSetEndOfLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfssetendoflog)

[LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object)