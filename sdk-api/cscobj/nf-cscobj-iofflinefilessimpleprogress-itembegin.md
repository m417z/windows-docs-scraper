# IOfflineFilesSimpleProgress::ItemBegin

## Description

Reports that an operation on an item is beginning.

## Parameters

### `pszFile` [in]

Receives the fully qualified UNC path of the file or directory that is being processed.

### `pResponse` [out]

Set this parameter to a value from the [OFFLINEFILES_OP_RESPONSE](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_op_response) enumeration that indicates how the operation is to proceed

## Return value

The return value is ignored.

## See also

[IOfflineFilesSimpleProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessimpleprogress)