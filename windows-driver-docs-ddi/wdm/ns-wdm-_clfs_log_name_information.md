# _CLFS_LOG_NAME_INFORMATION structure

## Description

The **CLFS_LOG_NAME_INFORMATION** structure holds the name of a Common Log File System (CLFS) stream or log.

## Members

### `NameLengthInBytes`

The size, in bytes, of the log name.

### `Name`

An array of wide characters that holds the log name.

## See also

[ClfsQueryLogFileInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsquerylogfileinformation)

[ClfsSetLogFileInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfssetlogfileinformation)