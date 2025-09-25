# CfGetTransferKey function

## Description

**CfGetTransferKey** returns *TransferKey*, which is needed to initiate a transfer of data into a placeholder using the [CfExecute](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfexecute) API.

## Parameters

### `FileHandle` [in]

The file handle of the placeholder.

### `TransferKey` [out]

An opaque handle to the placeholder to be serviced.

## Return value

If this function succeeds, it returns `S_OK`. Otherwise, it returns an **HRESULT** error code.

## Remarks

This API is available for sync providers that may wish to proactively initiate a transfer of data into a placeholder, as an alternative to calling [CfHydratePlaceholder](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfhydrateplaceholder). **CfGetTransferKey** returns the same *TransferKey* that a fetch data callback would have returned. The sync provider can then pass the *TransferKey* in subsequent calls to the [CfExecute](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfexecute) API. In this way, the transfer of data is driven by the sync provider rather than the filter.

A sync provider should have **READ_DATA** or **WRITE_DAC** access to the file whose transfer key is to be obtained or **CfGetTransferKey** will be failed with **HRESULT(ERROR_CLOUD_FILE_ACCESS_DENIED)**.

The *TransferKey* is valid as long as the *FileHandle* used to obtain it remains open. The sync provider must pass the *TransferKey* to [CfExecute](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfexecute) to perform the desired operation on the placeholder file or folder. When a *TransferKey* is no longer being used, it must be released using [CfReleaseTransferKey](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfreleasetransferkey).

## See also

[CfHydratePlaceholder](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfhydrateplaceholder)

[CfExecute](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfexecute)

[CfReleaseTransferKey](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfreleasetransferkey)