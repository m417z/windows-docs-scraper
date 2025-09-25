# SHGetThreadRef function

## Description

Retrieves the per-thread object reference set by [SHSetThreadRef](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shsetthreadref).

## Parameters

### `ppunk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)****

The address of a pointer that, when this function returns successfully, points to the object whose reference is stored. Your application is responsible for freeing this resource when it is no longer needed.

## Return value

Type: **HRESULT**

Returns S_OK if the object reference exists, or **E_NOINTERFACE** otherwise.

## See also

[SHCreateThread](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shcreatethread)

[SHCreateThreadRef](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shcreatethreadref)

[SHReleaseThreadRef](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shreleasethreadref)

[SHSetThreadRef](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shsetthreadref)