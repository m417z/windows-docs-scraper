# IADsNameTranslate::Get

## Description

The **IADsNameTranslate::Get** method retrieves the name of a directory object in the specified format. The distinguished name must have been set in the appropriate format by the [IADsNameTranslate::Set](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-set) method.

## Parameters

### `lnFormatType`

The format type of the output name. For more information, see [ADS_NAME_TYPE_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_name_type_enum). This method does not support the **ADS_NAME_TYPE_SID_OR_SID_HISTORY_NAME** element in **ADS_NAME_TYPE_ENUM**.

### `pbstrADsPath`

The name of the returned object.

## Return value

This method supports the standard **HRESULT** return values, including:

## Remarks

This method lets you retrieve the name of a single directory object. To retrieve names of multiple objects use [IADsNameTranslate::GetEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-getex).

When referral chasing is on, this method will attempt to chase and resolve the path of a specified object that is not residing on the connected server.

#### Examples

The following C/C++ code example shows how to translate a distinguished name that is compliant with RFC 1779 to a GUID format. The computer name of the directory server is "myServer".

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

hr =pNto->Set(ADS_NAME_TYPE_1779, CComBSTR
  ("CN=jeff,CN=Users,DC=myDomain,DC=Fabrikam,DC=COM,O=Internet"));
if(FAILED(hr)) {exit 1;}

BSTR bstr;
hr = pNto->Get(ADS_NAME_TYPE_GUID, &bstr);
printf("Translation: %S\n", bstr);

SysFreeString(bstr);
pNto->Release();
```

The following Visual Basic code example shows how to translate a distinguished name that is compliant RFC 1779 to a GUID format. The computer name of the directory server is "myServer".

```vb
Dim nto As New NameTranslate
Dim result As String

dn = "CN=rob,CN=Users,DC=myDomain,DC=Fabrikam,DC=COM,O=Internet"
nto.Init ADS_NAME_INITTYPE_SERVER, "myServer"
nto.Set ADS_NAME_TYPE_1779, dn
result = nto.Get ADS_NAME_TYPE_GUID
MsgBox result
```

The following VBScript/ASP code example shows how to translate a distinguished name that is compliant with RFC 1779 to a GUID format. The machine name of the directory server is "myServer".

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
  nto.Set ADS_NAME_TYPE_1779, dn
  result = nto.Get(ADS_NAME_TYPE_GUID)

  Response.Write "<p>Translated name: " & result

%>
</body>
</html>
```

## See also

[ADS_NAME_TYPE_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_name_type_enum)

[IADsNameTranslate](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsnametranslate)

[IADsNameTranslate::GetEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-getex)

[IADsNameTranslate::Set](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-set)