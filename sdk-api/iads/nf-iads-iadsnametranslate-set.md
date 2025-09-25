# IADsNameTranslate::Set

## Description

The **IADsNameTranslate::Set** method directs the directory service to set up a specified object for name translation. To set the names and format of multiple objects, use [IADsnametranslate::SetEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-setex).

## Parameters

### `lnSetType`

The format of the name of a directory object. For more information, see [ADS_NAME_TYPE_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_name_type_enum).

### `bstrADsPath`

The object name, for example, "CN=Administrator, CN=users, DC=Fabrikam, DC=com".

## Return value

This method supports the standard **HRESULT** return values, including:

## Remarks

Before calling this method to set the object name, you should have established a connection to the directory service using either [IADsNameTranslate::Init](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-init) or [IADsNameTranslate::InitEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-initex).

You can use the **IADsNameTranslate::Set** method to set name translation for objects residing on the directory server. When the referral chasing is on, this method will also set any object found on other servers. For more information about referral chasing, see [IADsNameTranslate Property Methods](https://learn.microsoft.com/windows/desktop/ADSI/iadsnametranslate-property-methods).

#### Examples

The following C/C++ code example uses the **IADsNameTranslate::Set** method to set an object so that its name can be translated from the RFC 1779 format to the s user name format.

```cpp
IADsNameTranslate *pNto;
HRESULT hr;
hr = CoCreateInstance(CLSID_NameTranslate,
                      NULL,
                      CLSCTX_INPROC_SERVER,
                      IID_IADsNameTranslate,
                      (void**)&pNto);
if(FAILED(hr)) { exit 1;}

hr = pNto->Init(ADS_NAME_INITTYPE_SERVER,
                  CComBSTR("myServer"));
if (FAILED(hr)) { exit 1;}

hr =pNto->Set(ADS_NAME_TYPE_1779,
             CComBSTR("cn=jeffsmith,cn=users,dc=Fabrikam,dc=com"));
if(FAILED(hr)) {exit 1;}

BSTR bstr;
hr = pNto->Get(ADS_NAME_TYPE_NT4, &bstr);
printf("Name in the translated format: %S\n", bstr);

SysFreeString(bstr);
pNto->Release();
```

The following Visual Basic code example uses the **IADsNameTranslate::Set** method to set an object so that its name can be translated from the RFC 1779 format to the s user name format.

```vb
Dim nto As New NameTranslate
dso="CN=jeffsmith, CN=users, DC=Fabrikam dc=COM"

nto.Init ADS_NAME_INITTYPE_SERVER, "myServer"
nto.Set ADS_NAME_TYPE_1779, dso
trans = nto.Get(ADS_NAME_TYPE_NT4)
```

The following VBScript/ASP code example uses the **IADsNameTranslate::Set** method to set an object to have its name translated from the RFC 1779 format to the s user name format.

```vb
<%@ Language=VBScript %>
<html>
<body>
<%
  Dim nto
  const ADS_NAME_INITTYPE_SERVER = 2  ' VBScript cannot read
  const ADS_NAME_TYPE_1779 = 1        ' enumeration definition
  const ADS_NAME_TYPE_NT4 = 3

  dn = "CN=jeffsmith,CN=Users,DC=Fabrikam,DC=COM"

  Set nto = Server.CreateObject("NameTranslate")
  nto.Init ADS_NAME_INITTYPE_SERVER, "myServer"
  nto.Set ADS_NAME_TYPE_1779, dn
  result = nto.Get(ADS_NAME_TYPE_NT4)

  Response.Write "<p>Name in the translated format: " & result

%>
</body>
</html>
```

## See also

[ADS_NAME_TYPE_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_name_type_enum)

[IADsNameTranslate](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsnametranslate)

[IADsNameTranslate Property Methods](https://learn.microsoft.com/windows/desktop/ADSI/iadsnametranslate-property-methods)

[IADsNameTranslate::Init](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-init)

[IADsNameTranslate::InitEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-initex)

[IADsNameTranslate::SetEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-setex)