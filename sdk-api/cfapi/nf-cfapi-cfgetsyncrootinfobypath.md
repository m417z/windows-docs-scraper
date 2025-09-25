# CfGetSyncRootInfoByPath function

## Description

Gets various sync root information given a file under the sync root.

## Parameters

### `FilePath` [in]

A fully qualified path to a file whose sync root information is to be queried.

### `InfoClass` [in]

Types of sync root information.

### `InfoBuffer` [out]

A pointer to a buffer that will receive the sync root information.

### `InfoBufferLength` [in]

Length, in bytes, of the *InfoBuffer*.

### `ReturnedLength` [out, optional]

Length, in bytes, of the returned sync root information. Refer to [CfRegisterSyncRoot](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfregistersyncroot) for details about the sync root information.

## Return value

If this function succeeds, it returns `S_OK`. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the file is not underneath a cloud files sync root, the API will fail. On success, information is returned according to the specific *InfoClass* requested.

The *InfoClass* parameter can be one of the following values from [CF_SYNC_ROOT_INFO_CLASS](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_sync_root_info_class):

- CF_SYNC_ROOT_INFO_BASIC
- CF_SYNC_ROOT_INFO_STANDARD
- CF_SYNC_ROOT_INFO_PROVIDER

## See also

[CfRegisterSyncRoot](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfregistersyncroot)

[CfGetSyncRootInfoByHandle](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfgetsyncrootinfobyhandle)