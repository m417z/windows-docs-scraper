# GetTransactionInformation function

## Description

Returns the requested information about the specified transaction.

## Parameters

### `TransactionHandle` [in]

A handle to the transaction. The handle must have the TRANSACTION_QUERY_INFORMATION permission to retrieve the information.

### `Outcome` [out, optional]

A pointer to a buffer that receives the current outcome of the transaction. If the call to the **GetTransactionInformation** function is successful, this value will be one of the [TRANSACTION_OUTCOME](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-transaction_outcome) enumeration values.

### `IsolationLevel` [out, optional]

Reserved.

### `IsolationFlags` [out, optional]

Reserved.

### `Timeout` [out, optional]

A pointer to a variable that receives the timeout value, in milliseconds, for this transaction.

### `BufferLength` [in]

The size of the *Description* parameter, in bytes. The buffer length value cannot be longer than the value of MAX_TRANSACTION_DESCRIPTION_LENGTH.

### `Description` [out, optional]

A pointer to a buffer that receives the user-defined description of the transaction.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

The following list identifies the possible error codes:

## See also

[CreateTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createtransaction)

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)

[SetTransactionInformation](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-settransactioninformation)