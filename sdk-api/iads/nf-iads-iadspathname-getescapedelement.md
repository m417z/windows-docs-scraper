# IADsPathname::GetEscapedElement

## Description

The **IADsPathname::GetEscapedElement** method is used to escape special characters in the input path.

## Parameters

### `lnReserved` [in]

Reserved for future use.

### `bstrInStr` [in]

An input string.

### `pbstrOutStr` [out]

An output string.

## Return value

This method supports the standard return values, as well as the following:

For more information and other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

This method is used to handle a path that contains special characters in a unescaped string as input from a user interface. The input string must be a single element (name-value pair) of the path; that is, "CN=Smith,Jeff".

#### Examples

The following Visual Basic code example shows the effect produced by **IADsPathname::GetEscapedElement**. After this code is executed, rdn will contain "cn=smith\,jeff".

```vb
Dim x As New Pathname

rdn = x.GetEscapedElement(0, "cn=smith,jeff")
```

The following VBScript code example shows the effect produced by **IADsPathname::GetEscapedElement**. After this code is executed, rdn will contain "cn=smith\,jeff".

```vb
Dim x
Set x = CreateObject("Pathname")
rdn = x.GetEscapedElement(0, "cn=smith,jeff")
```

The following C++ code example shows the effect produced by **IADsPathname::GetEscapedElement**. After this code is executed, rdn will contain "cn=smith\,jeff".

```cpp
LPWSTR adsPath=L"LDAP://server/cn=jeffsmith,dc=Fabrikam,dc=com";

IADsPathname *pPath = GetPathnameObject(adsPath);
BSTR rdn;
HRESULT hr = pPath->GetEscapedElement(0,CComBSTR("cn=smith,jeff")
                                      ,&rdn);

pPath->Release();
```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IADsPathname](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspathname)