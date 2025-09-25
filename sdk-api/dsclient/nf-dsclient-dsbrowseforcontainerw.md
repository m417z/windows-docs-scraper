# DsBrowseForContainerW function

## Description

The **DsBrowseForContainer** function displays a dialog box used to browse for container objects in Active Directory Domain Services.

## Parameters

### `pInfo` [in]

Pointer to a [DSBROWSEINFO](https://learn.microsoft.com/windows/win32/api/dsclient/ns-dsclient-dsbrowseinfow) structure that contains data about initializing the container browser dialog and receives data about the selected object.

## Return value

The function returns **IDOK** if the user selects a container and clicks the **OK** button, or double-clicks an object. If the user cancels the dialog box, the function returns **IDCANCEL**. If an error occurs, the function returns `-1`. Use the [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to retrieve extended error information.

## Remarks

The dialog box displays a container picker which is either populated with containers from a particular root or which uses trusted domains. If it uses trusted domains, it can use either the domain that the user is currently logged on to, or it can use an alternate domain specified by the application using the **pszRoot** member of the [DSBROWSEINFO](https://learn.microsoft.com/windows/win32/api/dsclient/ns-dsclient-dsbrowseinfow) structure. If the user clicks the **OK** button or double-clicks an object, **IDOK** is returned and **pszPath** contains the ADsPath of the selected object. If the user cancels the dialog box, **DsBrowseForContainer** returns **IDCANCEL**.

The **pszRoot** member contains an ADsPath, which must be in the following format:

```cpp
LDAP://fabrikam.com/CN=Users,DC=Fabrikam,DC=com
```

**DsBrowseForContainer** uses this path as the root of the tree. The **pszRoot** member can also be used to specify a domain that has a trust with the domain that the user is signed into, so the user can browse the **Users** container of the alternate domain. If the **pszPath** member contains a path, the dialog will navigate from **pszRoot** through the containers until it reaches the object specified by **pszPath**.

The **DsBrowseForContainer** function supports a callback function as specified in the [DSBROWSEINFO](https://learn.microsoft.com/windows/win32/api/dsclient/ns-dsclient-dsbrowseinfow) structure. The callback function can be used to filter, modify, or otherwise update the view based on selection change, and so on. For more information, see
[BFFCallBack](https://learn.microsoft.com/windows/win32/api/shlobj_core/nc-shlobj_core-bffcallback).

> [!IMPORTANT]
> Beginning with Windows Server 2003, the ANSI version of this function (**DsBrowseForContainerA**) is not implemented and always returns `-1`.

#### Examples

The following code example chooses a container in the domain that the user is signed into. The view also displays all the trusted domains.

```cpp
void PickContainer(void)
{
    DSBROWSEINFOW dsbi = { 0 };
    WCHAR wszResult[MAX_PATH];

    dsbi.cbStruct = sizeof(dsbi);
    dsbi.pszCaption = L"The container picker";
    dsbi.pszTitle = L"Pick a container for this example.";
    dsbi.pszPath = wszResult;
    dsbi.cchPath = MAX_PATH;
    dsbi.dwFlags = DSBI_ENTIREDIRECTORY;

    int nReturn = DsBrowseForContainerW(&dsbi);

    if ( IDOK == nReturn )
    {
        // wszResult contains the resulting path
    }
}
```

> [!NOTE]
> The `dsclient.h` header defines **DsBrowseForContainer** as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[BFFCallBack](https://learn.microsoft.com/windows/win32/api/shlobj_core/nc-shlobj_core-bffcallback)

[DSBROWSEINFO](https://learn.microsoft.com/windows/win32/api/dsclient/ns-dsclient-dsbrowseinfow)