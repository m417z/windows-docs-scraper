# IADsNameTranslate::GetEx

## Description

The **IADsNameTranslate::GetEx** method gets the object names in the specified format. The object names must be set by [IADsNameTranslate::SetEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-setex).

## Parameters

### `lnFormatType`

The format type used for the output names. For more information about the various types of formats you can use, see [ADS_NAME_TYPE_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_name_type_enum). This method does not support the ADS_NAME_TYPE_SID_OR_SID_HISTORY_NAME element in **ADS_NAME_TYPE_ENUM**.

### `pvar`

A variant array of strings that hold names of the objects returned.

## Return value

This method supports the standard **HRESULT** return values, including:

## Remarks

This method gets the names of multiple objects. However, all of the names returned use a single format.

When referral chasing is on, this method will not attempt to chase and resolve the path of a specified object not residing on the connected server.

#### Examples

The following C/C++ code example shows how to translate a distinguished names that is compliant with RFC 1779 to the GUID format. The computer name of the directory server is "myServer".

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

The following code example shows how to convert multiple names from the RFC 1779 type to the GUID type. The computer name of the directory server is "myServer".

```vb
Dim nto As new NameTranslate
Dim result As Variant
Dim ns(1) As String

nto.Init ADS_NAME_INITTTYPE_SERVER, "myServer"

ns(0)="CN=rob,CN=users,DC=example,DC=Fabrikam,DC=COM,O=Internet"
ns(1)="CN=jim,CN=users,DC=example,DC=Fabrikam,DC=COM,O=Internet"

nto.SetEx ADS_NAME_TYPE_1779, ns
nto.GetEx ADS_NAME_TYPE_GUID, result
MsgBox "name(0): " & result(0) & " name(1): " & result(1)
```

The following VBScript/ASP code example translates two distinguished names compliant with RFC 1779 to the GUID format. The computer name of the directory server is "myServer".

```vb
<%@ Language=VBScript %>
<html>
<body>
<%
  Dim nto
  const ADS_NAME_INITTYPE_SERVER = 2
  const ADS_NAME_TYPE_1779 = 1
  const ADS_NAME_TYPE_NT4 = 3

  server = "myServer"
  user   = "jeffsmith"
  dom    = "Fabrikam"
  passwd = "top secret"

  Set nto = Server.CreateObject("NameTranslate")
  nto.InitEx ADS_NAME_INITTYPE_SERVER, server, user, dom, passwd

  ns(0)="CN=rob,CN=users,DC=example,DC=Fabrikam,DC=COM,O=Internet"
  ns(1)="CN=jim,CN=users,DC=example,DC=Fabrikam,DC=COM,O=Internet"

  nto.SetEx ADS_NAME_TYPE_1779, ns
  result = nto.GetEx(ADS_NAME_TYPE_GUID)

  Response.Write "<p>Names in the translated format: " & result(0) & _
    ", " & result(1)

%>
</body>
</html>
```

## See also

[ADS_NAME_TYPE_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_name_type_enum)

[IADsNameTranslate](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsnametranslate)

[IADsNameTranslate::SetEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-setex)