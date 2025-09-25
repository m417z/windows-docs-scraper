# PxeProviderQueryIndex function

## Description

Returns the index of the specified provider in the list of registered providers.

## Parameters

### `pszProviderName` [in]

Friendly name for the provider from the call to the
[PxeProviderRegister](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxeproviderregister) function.

### `puIndex` [out]

Address of a **ULONG** that will receive the index of the provider.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

## Remarks

If a provider wants to insert itself in the list of registered providers in a specific order (that is, wants to
service client requests before or after a certain provider), it can query the index of another provider and then use
the returned index to decide its own location.

#### Examples

```cpp
//
// Suppose Provider wants to handle requests after BINLSVC has rejected them.
//
dwError = PxeProviderQueryIndex(L"BINLSVC", &Index);

if (dwError == ERROR_SUCCESS)
{
 if (PxeProviderRegister(L"MYPROV",
                         L"C:\\MyDir\\MyProv.DLL",
                         PXE_REG_INDEX_BOTTOM,
                         Index + 1,              // Add after BINLSVC
                         &hKey) != ERROR_SUCCESS)
 {
  // Handle Error
 }
}

```

## See also

[PxeProviderRegister](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxeproviderregister)

[Windows Deployment Services Server Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-server-functions)