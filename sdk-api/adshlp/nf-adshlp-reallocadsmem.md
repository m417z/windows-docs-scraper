# ReallocADsMem function

## Description

The **ReallocADsMem** function reallocates and copies an existing memory block.

## Parameters

### `pOldMem` [in]

Type: **LPVOID**

Pointer to the memory to copy. **ReallocADsMem** will free this memory with [FreeADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-freeadsmem) after it has been copied. If additional memory cannot be allocated, this memory is not freed. This memory must have been allocated with the [AllocADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-allocadsmem), [AllocADsStr](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-allocadsstr), **ReallocADsMem**, or [ReallocADsStr](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-reallocadsstr) function.

The caller must free this memory when it is no longer required by passing this pointer to [FreeADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-freeadsmem).

### `cbOld` [in]

Type: **DWORD**

Size, in bytes, of the memory to copy.

### `cbNew` [in]

Type: **DWORD**

Size, in bytes, of the memory to allocate.

## Return value

Type: **LPVOID**

When successful, the function returns a pointer to the new allocated memory. Otherwise it returns **NULL**.

## Remarks

If *cbNew* is less than *cbOld*, the existing memory is truncated to fit the new memory size.

#### Examples

The following code example shows how to use **ReallocADsMem** to enlarge a string.

```cpp
LPWSTR pwszPrefix = L"LDAP://"
DWORD dwOldSize = (lstrlenW(pwszPrefix) + 1) * sizeof(WCHAR);

LPWSTR pwszADsPath = (LPWSTR)AllocADsMem(dwOldSize);
if(pwszADsPath)
{
    LPWSTR pwszDN = L"DC=fabrikam,DC=com";

    wcsncpy_s(pwszADsPath, pwszPrefix); // Path becomes "LDAP://"
    wprintf(L"path = %s\n", pwszADsPath);

    DWORD dwNewSize = (lstrlenW(pwszPrefix) + lstrlenW(pwszDN) + 1) * sizeof(WCHAR);

    /*
    If successful, this will free the old path buffer, so it does not have to be
    freed manually. But if it fails, the original memory still exists, so the
    reallocated memory pointer is temporarily placed in another variable.
    */
    LPWSTR pwszNewPath = (LPWSTR)ReallocADsMem(pwszADsPath, dwOldSize, dwNewSize);
    if(pwszNewPath)
    {
        pwszADsPath = pwszNewPath;

        // Path is still "LDAP://"
        wcsncat_s(pwszADsPath, pwszDN);

        // Path is "LDAP://DC=fabrikam,DC=com"
        wprintf(L"path = %s\n", pwszADsPath);
    }
    else
    {
        wprintf(L"Unable to allocate additional memory.");
    }

    // Free remaining memory.
    FreeADsMem(pwszADsPath);
}
```

## See also

[ADSI Functions](https://learn.microsoft.com/windows/desktop/ADSI/adsi-functions)

[AllocADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-allocadsmem)

[AllocADsStr](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-allocadsstr)

[FreeADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-freeadsmem)

[ReallocADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-reallocadsmem)