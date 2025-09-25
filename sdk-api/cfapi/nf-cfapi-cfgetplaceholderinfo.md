# CfGetPlaceholderInfo function

## Description

Gets various characteristics of a placeholder file or folder. If the file is not a cloud files placeholder, the API will fail. On success, information is returned according to the specific *InfoClass* requested.

## Parameters

### `FileHandle` [in]

A handle to the placeholder whose information will be queried. Unlike most cloud files APIs that take a file handle, this one does not modify the file in any way. Therefore, the file handle only requires **READ_ATTRIBUTES** access.

### `InfoClass` [in]

Placeholder information. This can be set to either [CF_PLACEHOLDER_STANDARD_INFO](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_placeholder_standard_info) or [CF_PLACEHOLDER_BASIC_INFO](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_placeholder_basic_info).

### `InfoBuffer` [out]

A pointer to a buffer that will receive information about the placeholder.

### `InfoBufferLength` [in]

The length of the *InfoBuffer*, in bytes. If the buffer is not large enough to hold all the information requested, the API will return as much data as it can fit into the buffer, and the call will fail with **HRESULT_FROM_WIN32(ERROR_MORE_DATA)**.

### `ReturnedLength` [out, optional]

The number of bytes returned in the *InfoBuffer*.

## Return value

If this function succeeds, it returns `S_OK`. Otherwise, it returns an **HRESULT** error code.

## Remarks

Placeholder information includes the following attributes:

| Attribute | Description |
|--------|--------|
| OnDiskDataSize | The total number of bytes on disk. |
| ValidatedDataSize | The total number of bytes that are in sync with the cloud. |
| ModifiedDataSize | The total number of bytes that have been overwritten/appended locally, i.e., not in sync with the cloud. |
| PropertiesSize | The total number of bytes on disk that is used by all the property blobs. |
| PinState | Refer to [CfSetPinState](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfsetpinstate) for more information. |
| InSyncState | Refer to [CfSetInSyncState](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfsetinsyncstate) for more information. |
| FileId | A 64-bit volume wide non-volatile number that uniquely identifies a file or directory. |
| SyncRootFileId | The file ID of the sync root directory under which the file whose placeholder information is to be queried resides. |
| FileIdentity | An opaque blob supplied by the sync provider to the platform when the placeholder was created. File identity is provided for all sync provider callbacks. |
| FileIdentityLength | The length of the file identity in bytes. |

## See also

[CfSetPinState](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfsetpinstate)

[CfSetInSyncState](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfsetinsyncstate)

[CF_PLACEHOLDER_STANDARD_INFO](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_placeholder_standard_info)

[CF_PLACEHOLDER_BASIC_INFO](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_placeholder_basic_info)