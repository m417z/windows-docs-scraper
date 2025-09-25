# MsiGetPropertyA function

## Description

The
**MsiGetProperty** function gets the value for an installer property.

## Parameters

### `hInstall` [in]

Handle to the installation provided to a DLL custom action or obtained through [MsiOpenPackage](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackagea), [MsiOpenPackageEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackageexa), or [MsiOpenProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenproducta).

### `szName` [in]

A null-terminated string that specifies the name of the property.

### `szValueBuf` [out]

Pointer to the buffer that receives the null terminated string containing the value of the property. Do not attempt to determine the size of the buffer by passing in a null (value=0) for *szValueBuf*. You can get the size of the buffer by passing in an empty string (for example ""). The function will then return ERROR_MORE_DATA and *pchValueBuf*  will contain the required buffer size in TCHARs, not including the terminating null character. On return of ERROR_SUCCESS, *pcchValueBuf*  contains the number of TCHARs written to the buffer, not including the terminating null character.

### `pcchValueBuf` [in, out]

Pointer to the variable that specifies the size, in TCHARs, of the buffer pointed to by the variable *szValueBuf*. When the function returns ERROR_SUCCESS, this variable contains the size of the data copied to *szValueBuf*, not including the terminating null character. If *szValueBuf*  is not large enough, the function returns ERROR_MORE_DATA and stores the required size, not including the terminating null character, in the variable pointed to by *pchValueBuf*.

## Return value

This function returns UINT.

## Remarks

If the value for the property retrieved by the
**MsiGetProperty** function is not defined, it is equivalent to a 0-length value. It is not an error.

If ERROR_MORE_DATA is returned, the parameter which is a pointer gives the size of the buffer required to hold the string. If ERROR_SUCCESS is returned, it gives the number of characters written to the string buffer. Therefore you can get the size of the buffer by passing in an empty string (for example "") for the parameter that specifies the buffer. Do not attempt to determine the size of the buffer by passing in a Null (value=0).

The following example shows how a DLL custom action could access the value of a property by dynamically determining the size of the value buffer.

```cpp
UINT __stdcall MyCustomAction(MSIHANDLE hInstall)
{
    TCHAR* szValueBuf = NULL;
    DWORD cchValueBuf = 0;
    UINT uiStat =  MsiGetProperty(hInstall, TEXT("MyProperty"), TEXT(""), &cchValueBuf);
    //cchValueBuf now contains the size of the property's string, without null termination
    if (ERROR_MORE_DATA == uiStat)
    {
        ++cchValueBuf; // add 1 for null termination
        szValueBuf = new TCHAR[cchValueBuf];
        if (szValueBuf)
        {
            uiStat = MsiGetProperty(hInstall, TEXT("MyProperty"), szValueBuf, &cchValueBuf);
        }
    }
    if (ERROR_SUCCESS != uiStat)
    {
        if (szValueBuf != NULL)
           delete[] szValueBuf;
        return ERROR_INSTALL_FAILURE;
    }

    // custom action uses MyProperty
    // ...

    delete[] szValueBuf;

    return ERROR_SUCCESS;
}

```

> [!NOTE]
> The msiquery.h header defines MsiGetProperty as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Installer State Access Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)

[Passing Null as the Argument of Windows Installer Functions](https://learn.microsoft.com/windows/desktop/Msi/passing-null-as-the-argument-of-windows-installer-functions)