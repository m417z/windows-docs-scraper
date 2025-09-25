# GetEnlistmentRecoveryInformation function

## Description

 Retrieves an opaque structure of recovery data from KTM. Recovery information is stored in a log on behalf of a resource manager (RM) by calling the [SetEnlistmentRecoveryInformation](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-setenlistmentrecoveryinformation) function. After a failure, the RM can use the **GetEnlistmentRecoveryInformation** function to retrieve the information.

## Parameters

### `EnlistmentHandle` [in]

A handle to the enlistment.

### `BufferSize` [in]

The size of the *Buffer* parameter, in bytes.

### `Buffer` [out]

A pointer to a buffer that receives the enlistment recovery information.

### `BufferUsed` [out, optional]

A pointer to a variable that receives the actual number of bytes returned in the *Buffer* parameter.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0 (zero). To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

The following list identifies the possible error codes:

## Remarks

This call cannot be used with volatile transaction managers.

## See also

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)

[SetEnlistmentRecoveryInformation](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-setenlistmentrecoveryinformation)