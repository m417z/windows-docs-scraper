# IAzClientContext3::AccessCheck2

## Description

The **AccessCheck2** method returns a value that specifies whether the principal represented by the current client context is allowed to perform the specified operation.

## Parameters

### `bstrObjectName` [in]

The name of the accessed object. This string is used in audits.

### `bstrScopeName` [in]

The name of the scope that contains the operation specified by the *lOperation* parameter.

### `lOperation` [in]

The [OperationID](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazoperation-get_operationid) property of the [IAzOperation](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazoperation) object for which to check access.

### `plResult` [out]

A pointer to a value that indicates whether the principal represented by the current client context is allowed to perform the operation specified by the *lOperation* parameter.

 A value of **NO_ERROR** indicates that the principal does have permission. Any other value indicates that the principal does not have permission.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).