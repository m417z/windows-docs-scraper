# WofSetFileDataLocation function

## Description

Used to change a file from being backed by a physical file to one backed by a system data provider.

## Parameters

### `FileHandle` [in]

A handle to a file opened with [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) or a similar API.

### `Provider` [in]

Indicates which provider is backing this file. Currently defined providers are:

|  |  |
| --- | --- |
| WOF_PROVIDER_WIM | Indicates that the data for the file should be obtained from a WIM file. On access, data is transparently extracted from the WIM file and provided to applications. If the file contents are modified, data is transparently decompressed and the file is restored to the same physical form it had if this API were not used. |
| WOF_PROVIDER_FILE | Indicates that the data for the file should be compressed and stored with the file itself. On access, data is transparently decompressed and provided to applications. If the file contents are modified, data is transparently decompressed and the file is restored to the same physical form it had if this API were not used. This provider requires Windows 10. |

### `ExternalFileInfo` [in]

Provides data specific to the specified provider. Data structures for each defined provider are:

|  |  |
| --- | --- |
| WOF_PROVIDER_WIM | [WIM_EXTERNAL_FILE_INFO](https://learn.microsoft.com/windows/desktop/api/wofapi/ns-wofapi-wim_external_file_info) |
| WOF_PROVIDER_FILE | [WOF_FILE_COMPRESSION_INFO](https://learn.microsoft.com/windows/desktop/api/wofapi/ns-wofapi-wof_file_compression_info_v1) |

### `Length` [in]

Specifies the length of provider specific data, in bytes. This should correspond to the structures defined above:

|  |  |
| --- | --- |
| WOF_PROVIDER_WIM | sizeof(WIM_EXTERNAL_FILE_INFO) |
| WOF_PROVIDER_FILE | sizeof(WOF_FILE_COMPRESSION_INFO) |

## Return value

This function returns an HRESULT indicating success or the reason for failure.

## Remarks

When using WOF_PROVIDER_FILE, the operation may fail with ERROR_COMPRESSION_NOT_BENEFICIAL. This indicates that an attempt was made to compress the data, but no disk space was saved, so the file was not compressed. For most applications, this can be treated as a success condition.

## See also

[FSCTL_SET_EXTERNAL_BACKING](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-external-backing)