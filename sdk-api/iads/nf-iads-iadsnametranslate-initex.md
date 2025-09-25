# IADsNameTranslate::InitEx

## Description

The **IADsNameTranslate::InitEx** method initializes a name translate object by binding to a specified directory server, domain, or global catalog, using the specified user credential. To initialize the object without an explicit user credential, use [IADsNameTranslate::Init](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-init).

The **IADsNameTranslate::InitEx** method initializes the object by setting the server or domain that the object will point to and supplying a user credential.

## Parameters

### `lnSetType`

A type of initialization to be performed. Possible values are defined in [ADS_NAME_INITTYPE_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_name_inittype_enum).

### `bstrADsPath`

The name of the server or domain, depending on the value of *lnInitType*. When **ADS_NAME_INITTYPE_GC** is issued, this parameter is ignored. The global catalog server of the domain of the current machine will be used to carry out the name translate operations. This method will fail if the computer is not part of a domain, as no global catalog will be found in this scenario. For more information, see [ADS_NAME_INITTYPE_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_name_inittype_enum).

### `bstrUserID`

User name.

### `bstrDomain`

User domain name.

### `bstrPassword`

User password.

## Return value

Returns a standard **HRESULT** or RPC error code, including:

## Remarks

After the successful initialization, use the name translate object to submit requests of name translations of directory objects. For more information see [IADsNameTranslate::Set](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-set), [IADsNameTranslate::Get](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-get), [IADsNameTranslate::SetEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-setex), or [IADsNameTranslate::GetEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-getex).

#### Examples

The following C/C++ code example uses the **IADsNameTranslate::InitEx** method to initialize an [IADsNameTranslate](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsnametranslate) object before the distinguished name of a user object is rendered in the s format.

```cpp
IADsNameTranslate *pNto;
HRESULT hr;
hr = CoCreateInstance(CLSID_NameTranslate,
                      NULL,
                      CLSCTX_INPROC_SERVER,
                      IID_IADsNameTranslate,
                      (void**)&pNto);
if(FAILED(hr)) { exit 1;}

hr = pNto->InitEx(ADS_NAME_INITTYPE_SERVER,
                  CComBSTR("myServer"),
                  CComBSTR("jeffsmith"),
                  CComBSTR("Fabrikam"),
                  CComBSTR("top secret"));
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

The following Visual Basic code example uses the **IADsNameTranslate::InitEx** method to initialize an [IADsNameTranslate](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsnametranslate) object in order to have the distinguished name of a user object rendered in the s user name format.

```vb
Dim nto As New NameTranslate
dso="CN=jeffsmith, CN=users, DC=Fabrikam dc=COM"
server = "myServer"
domain = "Fabrikam"
user = "jeffsmith"
passwd = "myPass"

nto.InitEx  ADS_NAME_INITTYPE_SERVER, server,user,domain,passwd
nto.Set ADS_NAME_TYPE_1779, dso
trans = nto.Get(ADS_NAME_TYPE_NT4)
MsgBox "Name in the translated format: " & trans
```

The following VBScript/ASP code example uses the **IADsNameTranslate::InitEx** method to initialize an [IADsNameTranslate](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsnametranslate) object in order to have the distinguished name of a user object rendered in the s user name format.

```vb
<%@ Language=VBScript %>
<html>
<body>
<%
  Dim nto
  const ADS_NAME_INITTYPE_SERVER = 2  ' VBScript cannot read
  const ADS_NAME_TYPE_1779 = 1        ' enumeration definition
  const ADS_NAME_TYPE_NT4 = 3

  server = "myServer"
  domain = "Fabrikam"
  user = "jeffsmith"
  passwd = "myPass"

  dn = "CN=jeffsmith,CN=Users,DC=Fabrikam,DC=COM"

  Set nto = Server.CreateObject("NameTranslate")
  nto.InitEx ADS_NAME_INITTYPE_SERVER, server,user,domain,passwd
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

[IADsNameTranslate::Get](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-get)

[IADsNameTranslate::GetEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-getex)

[IADsNameTranslate::Set](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-set)

[IADsNameTranslate::SetEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-setex)