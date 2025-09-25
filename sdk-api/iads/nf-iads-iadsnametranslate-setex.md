# IADsNameTranslate::SetEx

## Description

The **IADsNameTranslate::SetEx** method establishes an array of objects for name translation. The specified objects must exist in the connected directory server. To set the name and format of a single directory object, use the [IADsNameTranslate::Set](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-set) method.

## Parameters

### `lnFormatType`

The format type of the input names. For more information, see [ADS_NAME_TYPE_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_name_type_enum).

### `pvar`

A variant array of strings that hold object names.

## Return value

This method supports the standard **HRESULT** return values, including:

## Remarks

You cannot use the **IADsNameTranslate::SetEx** method to set name translation for objects residing on other servers, even when the referral chasing option is enabled. For more information about referral chasing, see [IADsNameTranslate Property Methods](https://learn.microsoft.com/windows/desktop/ADSI/iadsnametranslate-property-methods).

You can use **IADsNameTranslate::SetEx** to set names for multiple objects. All the names, however, must be of the same format.

#### Examples

The following C/C++ code example uses the **IADsNameTranslate::SetEx** method to set up an array of objects whose names are to be translated from the RFC 1779 format to the Windows user name format.

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

LPWSTR str[1] = { L"CN=jim,CN=Users,DC=myDomain,DC=Fabrikam,DC=COM",
                  L"CN=rob,CN=Users,DC=myDomain,DC=Fabrikam,DC=COM"};
DWORD dwNum = sizeof(str)/sizeof(LPWSTR);

VARIANT varStr;
VariantInit(&varStr);

hr = ADsBuildVarArrayStr(str,dwNum,&varStr);

hr =pNto->SetEx(ADS_NAME_TYPE_1779, varStr);
if(FAILED(hr)) {exit 1;}
VariantClear(&varStr);

hr = pNto->GetEx(ADS_NAME_TYPE_GUID, &varStr);
if(FAILED(hr)) {exit 1;}

LONG lstart, lend;
SAFEARRAY *sa = V_ARRAY(&varStr);
VARIANT varItem;
VariantInit(&varItem);
printf("Names in the translated format:\n");
for (long idx = lstart; idx <= lend; idx++)
{
    hr = SafeArrayGetElement(sa, &idx, &varItem);
    printf("   %S\n", V_BSTR(&varItem));
    VariantClear(&varItem);
}
VariantClear(&varStr);
pNto->Release();
```

The following Visual Basic code example uses the **IADsNameTranslate::SetEx** method to set up an array of objects whose names are to be translated from the RFC 1779 format to the s user name format.

```vb
Dim nto As New NameTranslate
dso(0)="CN=jeffSmith, CN=users, DC=Fabrikam dc=COM"
dso(1)="CN=brendaDiaz, CN=users, DC=Fabrikam dc=COM"
nto.Init  ADS_NAME_INITTYPE_SERVER, "myServer"
nto.SetEx ADS_NAME_TYPE_1779, dso
trans = nto.GetEx(ADS_NAME_TYPE_NT4)
Msgbox "Translations: " & trans(0) & "," & trans(1)
```

The following VBScript/ASP code example uses the **IADsNameTranslate::SetEx** method to set up an array of objects whose names are to be translated from the RFC 1779 format to the s user name format.

```vb
<%@ Language=VBScript %>
<html>
<body>
<%
  Dim nto
  const ADS_NAME_INITTYPE_SERVER = 2  ' VBScript cannot read
  const ADS_NAME_TYPE_1779 = 1        ' enumeration definition
  const ADS_NAME_TYPE_NT4 = 3

  dn(0) = "CN=jeffSmith,CN=Users,DC=Fabrikam,DC=COM"
  dn(1) = "CN=brendaDiaz,CN=Users,DC=Fabrikam,DC=COM"

  Set nto = Server.CreateObject("NameTranslate")
  nto.Init ADS_NAME_INITTYPE_SERVER, "myServer"
  nto.SetEx ADS_NAME_TYPE_1779, dn
  result = nto.GetEx(ADS_NAME_TYPE_NT4)

  Response.Write "<p>Name in the translated format: " & result(0) & _
       ", & result(1)

%>
</body>
</html>
```

## See also

[ADS_NAME_TYPE_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_name_type_enum)

[IADsNameTranslate](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsnametranslate)

[IADsNameTranslate Property Methods](https://learn.microsoft.com/windows/desktop/ADSI/iadsnametranslate-property-methods)

[IADsNameTranslate::Set](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-set)