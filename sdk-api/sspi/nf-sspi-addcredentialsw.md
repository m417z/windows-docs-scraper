## Description

Adds a credential to the list of credentials associated with the current thread.

## Parameters

### `hCredentials`

The credentials to add to the list.

### `pPrincipal`

The name of the principal for the credentials.

### `pPackage`

The name of the package for the credentials.

### `fCredentialUse`

The flags indicating credential use.

### `pAuthData`

The package-specific authentication data.

### `pGetKeyFn`

The pointer to the **GetKey** function to get the key for the credentials.

### `pvGetKeyArgument`

The value to pass to the **GetKey** function.

### `ptsExpiry`

The lifetime of the credentials.

## Return value

Returns a status code indicating success or failure.

## Remarks

## See also