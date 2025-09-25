# GenerateCopyFilePaths function

## Description

A Point and Print DLL's **GenerateCopyFilePaths** function is used for modifying the source and destination paths used by print spoolers when they copy print queue-associated files to a print client.

## Parameters

### `pszPrinterName` [in]

Caller-supplied pointer to a string representing the name of the print queue.

### `pszDirectory` [in]

Caller-supplied pointer to a string representing the value supplied for the server's **Directory** entry in the registry. For more information, see [Supporting Point and Print During Printer Installations](https://learn.microsoft.com/windows-hardware/drivers/print/supporting-point-and-print-during-printer-installations).

### `pSplClientInfo` [in]

Caller-supplied pointer to an [SPLCLIENT_INFO_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_splclient_info_1) structure.

### `dwLevel` [in]

Caller-supplied value indicating the level number of the structure pointed to by *pSplClientInfo*. Must be 1.

### `pszSourceDir` [in, out]

For input, receives a caller-supplied pointer to a string representing the complete server directory path (including server name) from which files are to be copied.

For output, the function can modify this string.

### `pcchSourceDirSize` [in, out]

Caller-supplied address containing the length of the buffer pointed to by *pszSourceDir*. (Note that this is the buffer length, not the string length.)

### `pszTargetDir` [in, out]

For input, receives a caller-supplied pointer to a string representing the client directory path to which files are to be copied. The following rules apply:

* When the function is called on the server, this path is relative to PRINT$.
* When the function is called on the client, the string contains a complete path.

For output, the function can modify this string.

### `pcchTargetDirSize` [in, out]

Caller-supplied address containing the length of the buffer pointed to by *pszTargetDir*. (Note that this is the buffer length, not the string length.)

### `dwFlags` [in]

Caller-supplied flag. Can be one of the following:

#### COPYFILE_FLAG_CLIENT_SPOOLER

Indicates the function is being called by the client's spooler.

#### COPYFILE_FLAG_SERVER_SPOOLER

Indicates the function is being called by the server's spooler.

## Return value

If the operation succeeds, the function should return **ERROR_SUCCESS**. Otherwise, it should return an error code defined in winerror.h.

## Remarks

All [Point and Print DLLs](https://learn.microsoft.com/windows-hardware/drivers/print/point-and-print-dlls) must export a **GenerateCopyFilePaths** function, which is called by the print spooler. Its purpose is to allow a Point and Print DLL to modify the source or destination directory path, or both, before the print spooler copies print queue-associated files from a server to a client. (The files are copied when a client connects to a print server. For a complete description of the steps involved in creating a Point and Print connection, see [Supporting Point and Print](https://learn.microsoft.com/windows-hardware/drivers/print/supporting-point-and-print).)

A Point and Print DLL executes on both the server and the client. The **GenerateCopyFilePaths** function should check the *dwFlags* argument to determine where it is executing.

Typically, this function is used to provide compatibility when different versions of the operating system are executing on the client and server. For example if the function, when executing on the server, determines (by reading the [SPLCLIENT_INFO_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_splclient_info_1) structure) that its operating system is newer than the client's, it can modify the source and destination paths to be compatible with the client's older OS. On the other hand, if the function determines that the client's operating system is newer than the client's, it should probably do nothing on the server and perform modifications, if necessary, when executing on the client.

Arguments for the *pszSourceDir* and *pszTargetDir* parameters point to buffers containing strings that represent the current source and destination directory paths. If modifications to either of these strings is necessary, the function should make modifications in the supplied buffers. The maximum allowable string lengths are pointed to by the *pcchSourceDirSize* and *pcchTargetDirSize* arguments.

If no modifications to the source or destination directories are needed, the function should just return **ERROR_SUCCESS**.

## See also

[SpoolerCopyFileEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-spoolercopyfileevent)