# IOfflineFilesSimpleProgress::ItemResult

## Description

Reports that an item has been processed during the operation. This method is called even if the operation was unsuccessful. Check the value received in the *hrResult* parameter to determine whether the operation was successful.

## Parameters

### `pszFile` [in]

Receives the fully qualified UNC path of the item that was processed.

### `hrResult` [in]

Receives the result of the operation for the item. Contains S_OK if the operation completed successfully or an error value otherwise.

### `pResponse` [out]

Set this parameter to a value from the [OFFLINEFILES_OP_RESPONSE](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_op_response) enumeration that indicates how the operation is to proceed.

## Return value

The return value is ignored.

## See also

[IOfflineFilesSimpleProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessimpleprogress)