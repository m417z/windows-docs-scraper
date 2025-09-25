# WofIsExternalFile function

## Description

Used to determine if a file is being backed by a physical file or is backed by a system data provider, and optionally indicates which provider or additional data about the file.

## Parameters

### `FilePath` [in]

Specifies the path to the file for which the backing state is desired.

### `IsExternalFile` [out, optional]

Optionally points to a BOOL value. On successful return, this value will be TRUE if the object is externally backed, FALSE if it is a physical file.

### `Provider` [out, optional]

Optionally points to a ULONG value. On successful return, this value will be set to the provider that externally backs this object. Currently defined providers are:

|  |  |
| --- | --- |
| WOF_PROVIDER_WIM | Indicates that the data for the file resides in a separate WIM file. On access, data is transparently extracted, decompressed and provided to applications. If the file contents are modified, data is transparently decompressed and the file is restored to a regular file. |
| WOF_PROVIDER_FILE | Indicates that the data for the file should be compressed and stored with the file itself. On access, data is transparently decompressed and provided to applications. If the file contents are modified, data is transparently decompressed and the file is restored to a regular file. This provider requires Windows 10. |

### `ExternalFileInfo` [out, optional]

Optionally points to a caller allocated buffer. On successful return, this buffer will contain additional information about the state of the file. If this value is provided, **BufferLength** must also be specified. Data structures for each defined provider are:

|  |  |
| --- | --- |
| WOF_PROVIDER_WIM | [WIM_EXTERNAL_FILE_INFO](https://learn.microsoft.com/windows/desktop/api/wofapi/ns-wofapi-wim_external_file_info) |
| WOF_PROVIDER_FILE | [WOF_FILE_COMPRESSION_INFO](https://learn.microsoft.com/windows/desktop/api/wofapi/ns-wofapi-wof_file_compression_info_v1) |

### `BufferLength` [in, out, optional]

Optionally points to a value that contains the length of the buffer specified in **ExternalFileInfo**. On return, this value will be set to the size of the buffer consumed, or the size of the buffer required. If the buffer is of insufficient length, this function will succeed indicating the required size and will not populate the buffer in **ExternalFileInfo**. This length should correspond to one of the structures defined above:

|  |  |
| --- | --- |
| WOF_PROVIDER_WIM | sizeof(WIM_EXTERNAL_FILE_INFO) |
| WOF_PROVIDER_FILE | sizeof(WOF_FILE_COMPRESSION_INFO) |

## Return value

This function returns an HRESULT indicating success or the reason for failure. If the buffer specified in *ExternalFileInfo* is not of the correct size, the function will return S_OK and indicate the required buffer size in *BufferLength*.

## See also

[FSCTL_GET_EXTERNAL_BACKING](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-get-external-backing)