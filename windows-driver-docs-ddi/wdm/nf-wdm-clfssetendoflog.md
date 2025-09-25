# ClfsSetEndOfLog function

## Description

The **ClfsSetEndOfLog** routine truncates a CLFS stream.

## Parameters

### `plfoLog` [in]

A pointer to a [LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that represents a CLFS stream. This stream must be the only stream of a dedicated log. The caller previously obtained this pointer by calling [ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile).

### `plsnEnd` [in]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_lsn) structure that supplies the LSN of the record that is to become the last record of the stream. This must be the exact LSN of one of the records in the stream.

## Return value

**ClfsSetEndOfLog** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

The LSN supplied in the *plsnEnd* value is not validated. It is the responsibility of the caller to provide a valid LSN; that is, one that is the exact LSN of a record in the stream.

This stream represented by *plfoLog* must be from a dedicated log. This routine does not support streams from multiplexed logs.

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

The kernel-mode routine **ClfsSetEndOfLog** is reserved for future use and currently always returns STATUS_NOT_SUPPORTED. However, the user-mode routine **SetEndOfLog** is currently supported.

## See also

[CLFS_LSN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_lsn)

[ClfsAdvanceLogBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsadvancelogbase)

[ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile)

[ClfsSetArchiveTail](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfssetarchivetail)

[ClfsSetEndOfLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfssetendoflog)

[LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object)