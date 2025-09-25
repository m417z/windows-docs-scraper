# IAppxManifestApplication::GetAppUserModelId

## Description

Gets the application user model identifier.

## Parameters

### `appUserModelId` [out, retval]

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The user model identifier.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The caller must free the memory allocated for *appUserModelId* using the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## See also

[Application User Model IDs](https://learn.microsoft.com/windows/desktop/shell/appids)

**Concepts**

[IAppxManifestApplication](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestapplication)

**Reference**