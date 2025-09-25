## Description

Enables a downloaded DLL to register its Media Foundation Transform (MFT) device catalog interfaces within its running process so that the marshaling code will be able to marshal those interfaces.

## Parameters

### `deviceInstanceId`

Type: \_In\_ **[PCWSTR](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

A null-terminated string containing the instance identifier of the device to register.

### `cookie`

Type: \_Out\_ **CO_DEVICE_CATALOG_COOKIE\***

Returns an instance of **CO_DEVICE_CATALOG_COOKIE**. You can use this value to revoke the device catalog using [CoRevokeDeviceCatalog](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-corevokedevicecatalog).

## Return value

This function can return the standard return values **E_INVALIDARG**, **E_OUTOFMEMORY**, and **S_OK**.

## Remarks

## Examples

```cpp
std::vector<CO_DEVICE_CATALOG_COOKIE> g_deviceCatalogsCookies;

HRESULT MFStartup(ULONG Version, DWORD dwFlags)
{
    // current MFStartup code elided.
    std::wstring devices{ /* set of device IDs of interest */ };
    for (const auto& device : devices)
    {
        CO_DEVICE_CATALOG_COOKIE cookie{};
        RETURN_IF_FAILED(CoRegisterDeviceCatalog(device.c_str(), &cookie));
        g_deviceCatalogsCookies.push_back(cookie);
    }

    return S_OK;
}

HRESULT STDMETHODCALLTYPE MFShutdown()
{
    // current MFShutdown code elided
    for (auto catalogCookie : g_deviceCatalogsCookies)
    {
        CoRevokeDeviceCatalog(catalogCookie);
    }

    return S_OK;
}
```

## See also

* [CoRevokeDeviceCatalog](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-corevokedevicecatalog)