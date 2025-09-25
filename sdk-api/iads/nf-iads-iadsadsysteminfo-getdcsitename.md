# IADsADSystemInfo::GetDCSiteName

## Description

The **IADsADSystemInfo::GetDCSiteName** method retrieves the name of the Active Directory site that contains the local computer.

## Parameters

### `szServer` [out]

Name of the Active Directory site.

### `pszSiteName` [in]

DNS name of the service server.

## Return value

This method supports the standard **HRESULT** return values. For more information, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

An Active Directory site is one or more well-connected TCP/IP subnets holding Active Directory domain controllers. For more information, see [Active Directory Core Concepts](https://learn.microsoft.com/windows/desktop/AD/core-concepts-of-active-directory-domain-services).

#### Examples

The following C++ code example retrieves the Active Directory site name. For brevity, error checking is omitted.

```cpp
#include <activeds.h>
#include <stdio.h>

int main()
{
    HRESULT hr;

    hr = CoInitialize(NULL);

    IADsADSystemInfo *pSys;
    hr = CoCreateInstance(CLSID_ADSystemInfo,
                          NULL,
                          CLSCTX_INPROC_SERVER,
                          IID_IADsADSystemInfo,
                          (void**)&pSys);

   BSTR siteName;
   BSTR dnsServer;
   hr = pSys->GetAnyDCName(&dnsServer);

   if (SUCCEEDED(hr)) {
      printf("Domain controller: %S\n", dnsServer);

      hr = pSys->GetDCSiteName(&siteName);
      if (SUCCEEDED(hr)) {
          printf("Domain controller site: %S\n", siteName);
          SysFreeString(siteName);
      }

      SysFreeString(dnsServer);
   }

   if(pSys) {
      pSys->Release();
   }

   CoUninitialize();
   return 0;
}
```

The following Visual Basic code example retrieves the name of the Active Directory domain controller site.

```vb
Dim sys As New ADSystemInfo
dc = sys.GetAnyDCName
Debug.Print "Domain Controller site: " & sys.GetDCSiteName(dc)
```

The following VBScript/ASP code example retrieves the name of the Active Directory domain controller site.

```vb
<%
Dim sys

Set sys = CreateObject("ADSystemInfo")

dc = sys.GetAnyDCName

wscript.echo "Domain Controller     : " & dc
wscript.echo "Domain Controller site: " & sys.GetDCSiteName(dc)

%>
```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[Active Directory Core Concepts](https://learn.microsoft.com/windows/win32/ad/core-concepts-of-active-directory-domain-services)

[IADsADSystemInfo](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsadsysteminfo)