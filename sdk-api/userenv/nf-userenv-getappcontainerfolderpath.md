# GetAppContainerFolderPath function

## Description

Gets the path of the local app data folder for the specified app container.

## Parameters

### `pszAppContainerSid` [in]

A pointer to the SID of the app container.

### `ppszPath` [out]

The address of a pointer to a string that, when this function returns successfully, receives the path of the local folder. It is the responsibility of the caller to free this string when it is no longer needed by calling the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## Return value

This function returns an **HRESULT** code, including but not limited to the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The operation completed successfully. |
| **E_INVALIDARG** | The *pszAppContainerSid* or *ppszPath* parameter is **NULL**. |

## Remarks

The path retrieved through this function is the same path that you would get by calling the [SHGetKnownFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetknownfolderpath) function with **FOLDERID_LocalAppData**.

If a thread token is set, this function uses the app container for the current user. If no thread token is set, this function uses the app container associated with the process identity.

## See also

[GetAppContainerRegistryLocation](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-getappcontainerregistrylocation)