# CryptCATCDFEnumMembersByCDFTagEx function

\[The **CryptCATCDFEnumMembersByCDFTagEx** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.\]

The **CryptCATCDFEnumMembersByCDFTagEx** function enumerates the individual file members in the **CatalogFiles** section of a catalog definition file (CDF). **CryptCATCDFEnumMembersByCDFTagEx** is called by [MakeCat](https://learn.microsoft.com/windows/win32/seccrypto/makecat).

> [!Note]
> This function has no associated header file or import library. To call this function, you must create a user-defined header file and use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Mssign32.dll.

## Parameters

*pCDF* \[in\]

A pointer to a [**CRYPTCATCDF**](https://learn.microsoft.com/windows/win32/api/mscat/ns-mscat-cryptcatcdf) structure.

*pwszPrevCDFTag* \[in, out\]

A pointer to a **null**-terminated string that identifies the catalog file member.

*pfnParseError* \[in\]

A pointer to a user-defined function to handle file parse errors.

*ppMember* \[in\]

A pointer to a [**CRYPTCATMEMBER**](https://learn.microsoft.com/windows/win32/api/mscat/ns-mscat-cryptcatmember) structure that contains the file member information.

*fContinueOnError* \[in\]

A value that specifies whether to keep in memory a reference to the last enumerated member.

*pvReserved* \[in\]

This parameter is reserved; do not use it.

## Return value

Upon success, this function returns a pointer to a **null**-terminated string that identifies a file member in the **CatalogFiles** section of a CDF. The **CryptCATCDFEnumMembersByCDFTagEx** function returns a **NULL** pointer if it fails.

## Remarks

You typically call this function in a loop to enumerate all of the catalog file members in a CDF. Before entering the loop, set *pwszPrevCDFTag* to **NULL**. The function returns a pointer to the first member. Set *pwszPrevCDFTag* to the return value of the function for subsequent iterations of the loop.

## Examples

The following example shows the correct sequence of assignments for the *pwszPrevCDFTag* parameter (`pwszMemberTag`).

```C++
    CRYPTCATMEMBER      *pMember;
    LPWSTR              pwszMemberTag;
    CRYPTCATCDF         *pCDF;

    pCDF = CryptCATCDFOpen(L'myCDF', NULL);

    pMember = NULL;
    pwszMemberTag = NULL;

    while (pwszMemberTag = CryptCATCDFEnumMembersByCDFTagEx(pCDF,
                                                            pwszMemberTag,
                                                            NULL,
                                                            &pMember,
                                                            FALSE,
                                                            NULL))
    {
        //do something with pwszMemberTag and pMember
    }

    CryptCATCDFClose(pCDF);
```

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Wintrust.dll |

## See also

[MakeCat](https://learn.microsoft.com/windows/win32/seccrypto/makecat)

[**CRYPTCATCDF**](https://learn.microsoft.com/windows/win32/api/mscat/ns-mscat-cryptcatcdf)

[**CRYPTCATMEMBER**](https://learn.microsoft.com/windows/win32/api/mscat/ns-mscat-cryptcatmember)

[**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress)

[**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya)

