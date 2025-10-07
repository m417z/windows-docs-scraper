# GetTenantRestrictionsHostnames function

The **GetTenantRestrictionsHostnames** function returns a list of `hostnames` (e.g. `foo.ca`) and `subdomainSupportedHostnames` (e.g. `.bar.ca`) to the caller. This list is kept in sync by Windows and is used by apps to apply **Tenant Restrictions** to those endpoints.

## Parameters

`hostnames [out]`

**hostnames** contains names that must match exactly. For example, if `foo.ca` is in the list, then `foo.ca` _should_ be subject to Tenant Restrictions, but `bar.foo.ca` _should not_.

`hostnameCount [out]`

The **hostnameCount** parameter contains the number of hostnames in the `hostnames` array.

`subdomainSupportedHostnames [out]`

**subdomainSupportedHostnames** contains names that allow for subdomains, e.g. if `.bar.ca` is in the list, `sub.bar.ca` _should_ be subject to Tenant Restrictions but `bar.ca` _should not_. These entries are expected to have a preceding `.` to facilitate matching.

`subdomainSupportedHostnameCount [out]`

The **subdomainSupportedHostnameCount** parameter contains the number of hostnames in the `subdomainSupportedHostnames` array.

## Return value

If the function succeeds, the function returns `S_OK`.

## Remarks

Callers should iteratively free array entries using [CoTaskMemFree](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree) and then free the array itself.

Regarding empty arrays:

- It is valid (though not expected in practice) for both lists to be empty.
- It is valid for one list to contain entries while the other does not.

In either case, de-allocating an empty list is not needed. No de-allocation is needed if the return value is not `S_OK`.

The function does not return success values other than `S_OK`.

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|--------|--------|
| Minimum supported client | Windows 10, version 2004 \[desktop apps only\] |
| Minimum supported server | Windows Server, version 2004 \[desktop apps only\] |
| DLL | TenantRestrictionsPlugin.dll |