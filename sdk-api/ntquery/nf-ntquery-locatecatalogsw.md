# LocateCatalogsW function

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

Finds the catalog that indexes a directory.

## Parameters

### `pwszScope` [in]

A pointer to a null-terminated string that specifies the scope for an Indexing Service query. The scope can be local (C:\directory) or a remote universal naming convention (UNC) (\\COMPUTER\SHARE\directory). The scope cannot be a redirected drive letter (a drive letter that refers to a drive on a remote computer). For Web catalogs, scopes must be physical, not IIS virtual scopes. To specify any catalog on the computer, use L"\".

### `iBmk` [in]

The zero-based bookmark of the result to be retrieved. Pass zero to retrieve the first computer and catalog that index *pwszScope*, pass one to retrieve the second computer and catalog that index *pwszScope*, and so on. If no index for the bookmark is available, **LocateCatalogs** returns S_FALSE.

### `pwszMachine` [out]

A Pointer to a buffer where a null-terminated string is written if the function is successful. The result string is the name of the computer on which a query over the scope *pwszScope* can be executed.

### `pccMachine` [in, out]

On input, a pointer to a character count that specifies the size of *pwszMachine*, including the terminating null character. On output, specifies the count of characters used in *pwszMachine* if the function is successful, or the count of characters needed to store the name of the computer if the buffer is too small. If the buffer is too small, **LocateCatalogs** returns S_OK.

### `pwszCat` [out]

A pointer to a buffer where a null-terminated string is written if the function is successful. The result string is the name of the catalog on which a query over the scope *pwszScope* can be executed.

### `pccCat` [in, out]

On input, a pointer to a character count that specifies the size of *pwszCat*, including the terminating null character. On output, specifies the count of characters used in *pwszCat* if the function is successful, or the count of characters needed to store the name of the catalog if the buffer is too small. If the buffer is too small, **LocateCatalogs** returns S_OK.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was completed successfully. |
| **S_FALSE** | No computer and catalog can be found that index the scope, or *iBmk* is beyond the count of computers and catalogs that index the scope. |
| **E_INVALIDARG** | The function received an invalid parameter. |
| **QUERY_E_INVALID_DIRECTORY** | The function received an invalid scope. |

## Remarks

Use the **LocateCatalogs** function to determine catalogs that cover a specific scope. If the computer and catalog are known, it's more efficient to execute a query without calling the **LocateCatalogs** function.

The **LocateCatalogs** function does not verify that the computer and catalog returned are available. If an application fails to issue a query with the computer and catalog returned, it should increment *iBmk* and call **LocateCatalogs** again to get the next computer and catalog that index the specified scope.

If a computer-and-catalog match is found but the computer and catalog buffers are not large enough, **LocateCatalogs** returns S_OK, and fills the *pcCat* and *pcMachine* parameters with the wide character count required. Callers of **LocateCatalogs** must check the return code, *pcMachine*, and *pcCat* to determine whether the call was successful.

**Note** If **LocateCatalogs** finds a catalog that includes the path in *pwszScope*, it does not determine whether the scope is excluded for that catalog.

#### Examples

This example enumerates all computers and catalogs capable of resolving queries over the scope "C:\directory".

```cpp
HRESULT hr = S_OK;

for ( ULONG iBmk = 0; S_OK == hr; iBmk++ )
{
    TCHAR awcMachine[ MAX_COMPUTERNAME_LENGTH + 1 ];
    const ULONG cwcMachineBuffer = sizeof awcMachine / sizeof TCHAR;
    ULONG cwcMachine = cwcMachineBuffer;
    TCHAR awcCatalog[ MAX_PATH + 1 ];
    const ULONG cwcCatalogBuffer = sizeof awcCatalog / sizeof TCHAR;
    ULONG cwcCatalog = cwcCatalogBuffer;

    hr = LocateCatalogs( L"c:\\directory",
                         iBmk,
                         awcMachine,
                         &cwcMachine,
                         awcCatalog,
                         &cwcCatalog );
    if ( ( hr == S_OK ) &&
         ( cwcMachine <= cwcMachineBuffer ) &&
         ( cwcCatalog <= cwcCatalogBuffer ) )
    {
        wprintf( L"matching machine and catalog: '%s', '%s'\n",
                awcMachine, awcCatalog );
    }
}
```

## See also

[SetCatalogState](https://learn.microsoft.com/windows/desktop/api/ntquery/nf-ntquery-setcatalogstate)