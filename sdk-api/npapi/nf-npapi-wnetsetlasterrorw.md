# WNetSetLastErrorW function

## Description

Sets extended error information. Network providers should call this function instead of [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror).

When necessary, the [Multiple Provider Router](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) (MPR) calls [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) to set the Windows error returned from a network provider.

## Parameters

### `err` [in]

The error that occurred. This is a network-specific error code.

### `lpError` [in]

String that describes the network-specific error.

### `lpProviders` [in]

String that names the network provider that raised the error.

## Remarks

This function is implemented by the Windows operating system and can be called by network providers.

A provider should use this function to report errors that contain provider-specific information. The error information is saved until it is overwritten by another call to **WNetSetLastError** in the same thread.

The recommended way for a provider function to handle general errors is to use the following statement.

```cpp
return(providerError);
```

In this statement, providerError is a Windows error code, such as one of the return codes listed for the provider API in this document.

For provider-specific errors, a provider should do the following.

```cpp
//  Set up lpErrorString to be the error to be reported.
WNetSetLastError(providerError,
lpErrorString,
lpProviderName);
return(ERROR_EXTENDED_ERROR);
```

In this case, providerError is the provider-specific error code.

Providers do not need to call [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) before returning from a provider function. The MPR calls **SetLastError** to set the Windows error returned from a provider when necessary to satisfy applications.