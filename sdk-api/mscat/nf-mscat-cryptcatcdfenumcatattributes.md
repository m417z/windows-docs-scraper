# CryptCATCDFEnumCatAttributes function

## Description

[The **CryptCATCDFEnumCatAttributes** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CryptCATCDFEnumCatAttributes** function enumerates catalog-level attributes within the **CatalogHeader** section of a catalog definition file (CDF). **CryptCATCDFEnumCatAttributes** is called by [MakeCat](https://learn.microsoft.com/windows/desktop/SecCrypto/makecat).

## Parameters

### `pCDF` [in]

A pointer to a [CRYPTCATCDF](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatcdf) structure.

### `pPrevAttr` [in]

A pointer to a [CRYPTCATATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatattribute) structure for a catalog attribute in the CDF pointed to by *pCDF*.

### `pfnParseError` [in]

A pointer to a user-defined function to handle file parse errors.

## Return value

Upon success, this function returns a pointer to a [CRYPTCATATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatattribute) structure. The **CryptCATCDFEnumCatAttributes** function returns a **NULL** pointer if it fails.

## Remarks

You typically call this function in a loop to enumerate all of the catalog header attributes in a CDF. Before entering the loop, set *pPrevAttr* to **NULL**. The function returns a pointer to the first attribute. Set *pPrevAttr* to the return value of the function for subsequent iterations of the loop.

#### Examples

The following example shows the correct sequence of assignments for the *pPrevAttr* parameter (`pAttr`).

```cpp
    CRYPTCATCDF         *pCDF;
    CRYPTCATATTRIBUTE   *pAttr;

    pCDF = CryptCATCDFOpen(L"myCDF", NULL);

    pAttr = NULL;

    while (pAttr = CryptCATCDFEnumCatAttributes(pCDF, pAttr, NULL))
    {
        //do something with pAttr
    }

    CryptCATCDFClose(pCDF);

```

## See also

[CRYPTCATATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatattribute)

[CRYPTCATCDF](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatcdf)

[MakeCat](https://learn.microsoft.com/windows/desktop/SecCrypto/makecat)