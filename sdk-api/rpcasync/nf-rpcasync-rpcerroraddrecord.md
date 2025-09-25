# RpcErrorAddRecord function

## Description

The
**RpcErrorAddRecord** function adds extended error information to a chain of extended error information records.

## Parameters

### `ErrorInfo` [in]

Error information to be added, in the form of an
[RPC_EXTENDED_ERROR_INFO](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_extended_error_info) structure.

## Return value

Successful completion returns RPC_S_OK.

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcErrorAddRecord** function enables applications or servers other than the RPC Runtime to add extended error information to a chain of extended error information records.

Responsibility for the strings pointed to by *ErrorInfo* belong to the caller; the
**RpcErrorAddRecord** function makes a copy of those strings, if necessary. The following restrictions on the members of *ErrorInfo* must be observed:

**Version** must be set to a valid version, such as RPC_EEINFO_VERSION.

**ComputerName** must be set to **NULL**. Any other value results in ERROR_INVALID_PARAMETER.

**ProcessID** must be set to zero. Any other value results in ERROR_INVALID_PARAMETER.

**SystemTime** or **FileTime** is ignored on input, and is set by the RPC Runtime.

**GeneratingComponent** must be set to zero. Any other value results in ERROR_INVALID_PARAMETER. The RPC Runtime sets this to EEInfoGCApplication.

**Status** can be set to the error code the caller wants to add to the chain.

**DetectionLocation** must be set to zero. Any other value results in ERROR_INVALID_PARAMETER.

**NumberOfParameters** indicates the number of parameters in the Parameters array. This value must be equal or greater than zero or MaxNumberOfEEInfoParams. The RPC Runtime does not use any memory after the specified number of parameters, so callers can safely allocate memory for less than MaxNumberOfEEInfoParams parameters.

**Parameters** represents the parameters for the extended error information record. The only restriction on Parameters is that **Pval** is used to represent pointers, and is always 64 bits. Use **Pval** regardless of whether the system used is 32 bits or 64 bits. Do not use **Lval**.

## See also

[Obtaining Extended RPC Error Information](https://learn.microsoft.com/windows/desktop/Rpc/obtaining-extended-rpc-error-information)

[RPC_EXTENDED_ERROR_INFO](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_extended_error_info)

[RpcErrorGetNextRecord](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorgetnextrecord)

[RpcErrorStartEnumeration](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorstartenumeration)