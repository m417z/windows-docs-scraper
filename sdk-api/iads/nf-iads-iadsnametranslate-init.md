# IADsNameTranslate::Init

## Description

The **IADsNameTranslate::Init** method initializes a name translate object by binding to a specified directory server, domain, or global catalog, using the credentials of the current user. To initialize the object with a different user credential, use [IADsNameTranslate::InitEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-initex).

## Parameters

### `lnSetType`

A type of initialization to be performed. Possible values are defined in [ADS_NAME_INITTYPE_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_name_inittype_enum).

### `bstrADsPath`

The name of the server or domain, depending on the value of *lnInitType*. When **ADS_NAME_INITTYPE_GC** is issued, this parameter is ignored. The global catalog server of the domain of the current computer will perform the name translate operations. This method will fail if the computer is not part of a domain as no global catalog will be found in this scenario. For more information, see [ADS_NAME_INITTYPE_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_name_inittype_enum).

## Return value

Returns a standard **HRESULT** or RPC error code, including:

## Remarks

After the successful initialization, you can proceed to use the name translate object to submit requests of name translations of objects in the directory. For more information, see [IADsNameTranslate::Set](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-set), or [IADsNameTranslate::Get](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-get).

#### Examples

The following C/C++ code example uses the **IADsNameTranslate::Init** method to initialize an [IADsNameTranslate](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsnametranslate) object before the distinguished name of a user object is rendered in the s format.

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

The following Visual Basic code example uses the **IADsNameTranslate::Init** method to initialize an [IADsNameTranslate](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsnametranslate) object in order to have the distinguished name of a user object rendered in the s user name format.

```vb
Dim nto As New NameTranslate
dso="CN=jeffsmith, CN=users, DC=Fabrikam dc=COM"

nto.Init  ADS_NAME_INITTYPE_SERVER, "myServer"
nto.Set ADS_NAME_TYPE_1779, dso
trans = nto.Get(ADS_NAME_TYPE_NT4)
```

The following VBScript/ASP code example uses the **IADsNameTranslate::Init** method to initialize an [IADsNameTranslate](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsnametranslate) object in order to have the distinguished name of a user object rendered in the s user name format.

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

[IADsNameTranslate::Get](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-get)

[IADsNameTranslate::InitEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-initex)

[IADsNameTranslate::Set](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-set)