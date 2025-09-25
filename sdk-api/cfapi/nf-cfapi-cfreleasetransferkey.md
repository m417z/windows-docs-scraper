# CfReleaseTransferKey function

## Description

Releases a transfer key obtained by [CfGetTransferKey](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfgettransferkey) when it is no longer needed.

## Parameters

### `FileHandle` [in]

The file handle of the placeholder.

### `TransferKey` [in]

An opaque handle to the placeholder.

## Remarks

**CfReleaseTransferKey** has no security requirement.

## See also

[CfGetTransferKey](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfgettransferkey)