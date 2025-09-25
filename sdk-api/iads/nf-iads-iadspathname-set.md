# IADsPathname::Set

## Description

The **IADsPathname::Set** method sets up the Pathname object for parsing a directory path. The path is set with a format as defined in [ADS_SETTYPE_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_settype_enum).

## Parameters

### `bstrADsPath` [in]

Path of an ADSI object.

### `lnSetType` [in]

An [ADS_SETTYPE_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_settype_enum) option that defines the format type to be retrieved.

## Return value

This method supports the standard return values, as well as the following:

For more information and other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

This method will set the namespace as specified and identify the appropriate provider for performing the path cracking operation. Resetting to a different namespace will lose data already set by this method.

#### Examples

The following Visual Basic code example sets a full ADSI path on the Pathname object.

```vb
Dim x As New Pathname

x.Set "LDAP://server/CN=Jeff Smith, DC=Fabrikam, DC=Com", _
       ADS_SETTYPE_FULL
dn = x.GetElement(0)    ' dn now is "CN=Jeff Smith".
```

The following VBScript/ASP code example sets a full ADSI path on the Pathname object.

```vb
<%
Dim x
const ADS_SETTYPE_FULL = 1
Set x = CreateObject("Pathname")
path = "LDAP://server/CN=Jeff Smith, DC=Fabrikam,DC=com"
x.Set path, ADS_SETTYPE_FULL
dn = x.GetElement(0)    ' dn now is "CN=Jeff Smith".
%>
```

The following C++ code example sets a full ADSI path on the Pathname object.

```cpp
IADsPathname *pPathname=NULL;
HRESULT hr;

hr = CoCreateInstance(CLSID_Pathname,
                      NULL,
                      CLSCTX_INPROC_SERVER,
                      IID_IADsPathname,
                      (void**)&pPathname);

if(FAILED(hr))
{
    if(pPathname) pPathname->Release();
    return NULL;
}

hr = pPathname->Set(CComBSTR("LDAP://CN=pencil/desk"),
                    ADS_SETTYPE_FULL);
```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADS_SETTYPE_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_settype_enum)

[IADsPathname](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspathname)