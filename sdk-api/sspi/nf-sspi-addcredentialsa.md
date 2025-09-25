## Description

Adds a credential to the list of credentials associated with the current thread.

## Parameters

### `hCredentials`

The credentials to add to the list.

### `pszPrincipal`

The name of the principal for the credentials.

### `pszPackage`

The name of the package.

### `fCredentialUse`

The flags indicating credential use.

### `pAuthData`

The package-specific authentication data.

### `pGetKeyFn`

The pointer to the **GetKey** function.

### `pvGetKeyArgument`

The value to pass to the **GetKey** function.

### `ptsExpiry`

The credential lifetime.

## Return value

Returns a handle to the credentials, if successful, or **NULL** otherwise.

## Remarks

## See also