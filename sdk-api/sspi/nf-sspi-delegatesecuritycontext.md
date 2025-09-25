## Description

Delegates the security context to the specified server.

## Parameters

### `phContext`

The security context to delegate.

### `pTarget`

The target path.

### `DelegationType`

The type of delegation.

### `pExpiry`

The **optional** time limit, after which the context expires.

### `pPackageParameters`

The **optional** package-specific parameters.

### `pOutput`

The output token for [ApplyControlToken](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-applycontroltoken).

## Return value

Returns a value indicating the result of the operation.

## Remarks

## See also

[ApplyControlToken](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-applycontroltoken)