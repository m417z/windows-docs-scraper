# IADsPathname::CopyPath

## Description

The **IADsPathname::CopyPath** method
creates a copy of the Pathname object.

## Parameters

### `ppAdsPath` [out]

The [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface pointer on the
returned [IADsPathname](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspathname) object.

## Return value

This method supports the standard return values, as well as the following:

For more information and other return values, see [ADSI Error
Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

This method is used to modify the object path and retain the original object path.

#### Examples

The following Visual Basic code example shows how to make a copy of a pathname.

```vb
Dim x, y As New Pathname
x.Set "LDAP://srv1/dc=dom,dc=company,dc=com",ADS_SETTYPE_FULL
set y = x.CopyPath
MsgBox y.Retrieve(ADS_FORMAT_WINDOWS)
```

The following VBScript/ASP code example shows how to make a copy of a pathname.

```vb
<%
Dim x, y
Const ADS_SETTYPE_FULL = 1
Const ADS_FORMAT_WINDOWS = 1
Set x = CreateObject("Pathname")
x.Set "LDAP://srv1/dc=dom,dc=company,dc=com",ADS_SETTYPE_FULL

set y = x.CopyPath
Response.Write y.Retrieve(ADS_FORMAT_WINDOWS)
%>
```

The following C++ code example creates a copy of a pathname object. For more information and a code example
of the **GetPathnameObject** function, see
[IADsPathname](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspathname).

```cpp
IADsPathname *pPath;
LPWSTR adsPath;
adsPath = L"LDAP://server/cn=jeff smith,dc=Fabrikam,dc=com";

IADsPathname *pPath = GetPathnameObject(adsPath)
if (!pPath) exit(0);

IDispatch *pDisp;
HRESULT hr;
hr = pPath->CopyPath(&pDisp);
if(FAILED(hr)) exit(hr);

IADsPathname *pPathCopy;
hr = pDisp->QueryInterface(IID_IADsPathname,(void**)&pPathCopy);

// ...
```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IADsPathname](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspathname)