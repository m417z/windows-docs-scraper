# WofEnumFilesProc callback function

## Description

Callback function that gets called for each file backed by an external data source, such as a WIM file.

## Parameters

### `FilePath` [in]

Specifies the path to the file which is backed by an external data source.

### `ExternalFileInfo` [in]

Points to a buffer containing information about the data source backing the file. The type of this buffer depends on the provider; data structures for each provider are:

|  |  |
| --- | --- |
| WOF_PROVIDER_WIM | WIM_EXTERNAL_FILE_INFO |
| WOF_PROVIDER_FILE | WOF_FILE_COMPRESSION_INFO |

### `UserData` [in, optional]

Optional user defined data.

## Return value

A boolean value that indicates whether the enumeration was successful. The enumeration will stop if this callback function returns FALSE.