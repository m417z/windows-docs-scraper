# ADS_NAME_INITTYPE_ENUM enumeration

## Description

The **ADS_NAME_INITTYPE_ENUM** enumeration specifies the types of initialization to perform on a **NameTranslate** object. It is used in the [IADsNameTranslate](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsnametranslate) interface.

## Constants

### `ADS_NAME_INITTYPE_DOMAIN:1`

Initializes a **NameTranslate** object by setting the domain that the object binds to.

### `ADS_NAME_INITTYPE_SERVER:2`

Initializes a **NameTranslate** object by setting the server that the object binds to.

### `ADS_NAME_INITTYPE_GC:3`

Initializes a **NameTranslate** object by locating the global catalog that the object binds to.

## Remarks

The [IADsNameTranslate::Init](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-init) method or [IADsNameTranslate::InitEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-initex) method uses these options to initialize the **NameTranslate** object. When **ADS_NAME_INITTYPE_SERVER** is used, specify the machine name of a directory server. When **ADS_NAME_INITTYPE_DOMAIN** is set, supply the domain name within a directory forest. When **ADS_NAME_INITTYPE_GC** is issued, the second parameter in **IADsNameTranslate::Init** or **IADsNameTranslate::InitEx** is ignored. The Global Catalog server of the domain of the current computer is used to perform the name translate operations. The initialization fails if the host computer is not part of a domain because no global catalog will be found.

**Note** Because VBScript cannot read data from a type library, VBScript applications do not recognize the symbolic constants as defined above. Instead, use the numeric constants to set the appropriate flags in your VBScript applications. To use symbolic constants as a good programming practice, write explicit declarations of such constants, as done here, in your VBScript applications.

#### Examples

The following C/C++ code example uses [IADsNameTranslate::Init](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-init) method to initialize a **NameTranslate** object through the global catalog, assuming the client running the application is within the directory forest. It then renders the distinguished name of a user object in the Windows format.

```cpp
IADsNameTranslate *pNto = NULL;
HRESULT hr = S_OK;
CComBSTR sbstr;

hr = CoCreateInstance(CLSID_NameTranslate,
                      NULL,
                      CLSCTX_INPROC_SERVER,
                      IID_IADsNameTranslate,
                      (void**)&pNto);
if(FAILED(hr)) { exit 1;}

hr = pNto->Init(ADS_NAME_INITTYPE_GC, CComBSTR(""));
if (FAILED(hr))
{
   goto cleanup;
}

hr =pNto->Set(ADS_NAME_TYPE_1779,
             CComBSTR(L"cn=jeffsmith,cn=users,dc=Fabrikam,dc=com"));
if(FAILED(hr))
{
   goto cleanup;
}

hr = pNto->Get(ADS_NAME_TYPE_NT4, &sbstr);
printf("Name in the translated format: %S\n", sbstr);

cleanup:
if(pNto)
{
    pNto->Release();
}
```

The following Visual Basic code example uses the [IADsNameTranslate::Init](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-init) method to initialize a **NameTranslate** object through the global catalog, assuming the client running the application is within the directory forest. It then renders the distinguished name of a user object in the Windows format.

```vb
Dim nto as New NameTranslate
dso="CN=jeffsmith, CN=users, DC=Fabrikam dc=COM"

nto.Init  ADS_NAME_INITTYPE_GC, ""
nto.Set ADS_NAME_TYPE_1779, dso
trans = nto.Get(ADS_NAME_TYPE_NT4)
MsgBox "Translated name = " & trans
```

The following VBScript/ASP code example uses [IADsNameTranslate::Init](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-init) method to initialize a **NameTranslate** object through the global catalog, assuming the client running the application is within the directory forest. It then renders the distinguished name of a user object in the Windows format.

```vb
<%@ Language=VBScript %>
<html>
<body>
<%
  Dim nto
  const ADS_NAME_INITTYPE_GC = 3  ' VBScript cannot read.
  const ADS_NAME_TYPE_1779 = 1    ' Enumeration definition.
  const ADS_NAME_TYPE_NT4 = 3

  dn = "CN=jeff smith,CN=Users,DC=Fabrikam,DC=COM"

  Set nto = Server.CreateObject("NameTranslate")
  nto.Init ADS_NAME_INITTYPE_GC, ""
  nto.Set ADS_NAME_TYPE_1779, dn
  result = nto.Get(ADS_NAME_TYPE_NT4)

  Response.Write "<p>Name in the translated format: " & result

%>
</body>
</html>
```

## See also

[ADSI
Enumerations](https://learn.microsoft.com/windows/desktop/ADSI/adsi-enumerations)

[IADsNameTranslate](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsnametranslate)