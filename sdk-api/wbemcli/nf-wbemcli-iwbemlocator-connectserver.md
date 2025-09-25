# IWbemLocator::ConnectServer

## Description

The
**IWbemLocator::ConnectServer** method creates a connection through DCOM to a WMI namespace on the computer specified in the *strNetworkResource* parameter.

[SWbemLocator.ConnectServer](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemlocator-connectserver) can connect with computers running IPv6 using an IPv6 address in the *strNetworkResource* parameter. For more information, see [IPv6 and IPv4 Support in WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/ipv6-and-ipv4-support-in-wmi).

## Parameters

### `strNetworkResource` [in]

Pointer to a valid **BSTR** that contains the object path of the correct WMI namespace. For local access to the default namespace, use a simple object path: "root\default" or "\\.\root\default". For access to the default namespace on a remote computer using COM or Microsoft-compatible networking, include the computer name: "\\myserver\root\default". For more information, see
[Describing a WMI Namespace Object Path](https://learn.microsoft.com/windows/desktop/WmiSdk/describing-a-wmi-namespace-object-path). The computer name also can be a DNS name or IP address. Starting with Windows Vista, [SWbemLocator.ConnectServer](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemlocator-connectserver) can connect with computers running IPv6 using an IPv6 address. For more information, see [IPv6 and IPv4 Support in WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/ipv6-and-ipv4-support-in-wmi).

### `strUser` [in]

Pointer to a valid **BSTR**, which contains the user name you need for a connection. A **NULL** value indicates the current security context. If the user name is from a domain different from the current domain, the string may contain the domain name and user name separated by a backslash.

`StrUserName = SysAllocString(L"Domain\\UserName");`

The *strUser* parameter cannot be an empty string.
Note that if the domain is specified in *strAuthority*, then it must not be specified here. Specifying the domain in both parameters results in an invalid parameter error.

You can use the user principal name (UPN) format, which is *Username@DomainName* to specify the *strUser*.

### `strPassword` [in]

Pointer to a valid **BSTR** that contains the password you need for a connection. A **NULL** value indicates the current security context. A blank string "" specifies a valid zero-length password.

### `strLocale` [in]

If **NULL**, the current locale is used. If not **NULL**, this parameter must be a valid **BSTR**, which indicates the correct locale for information retrieval. For Microsoft locale identifiers, the format of the string is "MS_xxx", where xxx is a string in hexadecimal form that indicates the Local Identification (LCID), for example, American English would appear as "MS_409". If an invalid locale is specified, then the method returns **WBEM_E_INVALID_PARAMETER**.

**Windows 7:** If an invalid locale is specified, then the default locale of the server is used unless there is a server-supported locale provided by the user application.

### `lSecurityFlags` [in]

Long value used to pass flag values to
**ConnectServer**. A value of zero (0) for this parameter results in the call to
**ConnectServer** returning only after connection to the server is established. This could result in your program ceasing to respond indefinitely if the server is broken. The following list lists the other valid values for *lSecurityFlags*.

#### WBEM_FLAG_CONNECT_REPOSITORY_ONLY (64 (0x40))

Reserved for internal use. Do not use.

#### WBEM_FLAG_CONNECT_USE_MAX_WAIT (128 (0x80))

The
**ConnectServer** call returns in 2 minutes or less. Use this flag to prevent your program from ceasing to respond indefinitely if the server is broken.

### `strAuthority` [in]

This parameter contains the name of the domain of the user to authenticate.

*strAuthority* can have the following values:

* blank

  If you leave this parameter blank, NTLM authentication is used and the NTLM domain of the current user is used. If the domain is specified in *strUser*, which is the recommended location, then it must not be specified here. Specifying the domain in both parameters results in an invalid parameter error.
* Kerberos:<*principal name*>

  Kerberos authentication is used and this parameter should contain a Kerberos principal name.
* NTLMDOMAIN:<*domain name*>

  NT LAN Manager authentication is used and this parameter should contain an NTLM domain name.

### `pCtx` [in]

Typically, this is **NULL**. Otherwise, this is a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object required by one or more dynamic class providers. The values in the context object must be specified in the documentation for the providers in question. For more information about this parameter, see
[Making Calls to WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/making-calls-to-wmi).

### `ppNamespace` [out]

Receives a pointer to an
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) object bound to the specified namespace. This pointer has a positive reference count. The caller must call [IWbemServices::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the pointer when it is no longer required. This pointer is set to point to **NULL** when there is an error.

## Return value

This method returns an **HRESULT** that indicates the status of the method call. The following list lists the value contained within an **HRESULT**.

COM-specific error codes may be returned if network problems cause you to lose the remote connection to WMI.

These error return codes are defined in the Wbemcli.h file in the WMI section of the PSDK \Include directory. For more information see [WMI Error Constants](https://learn.microsoft.com/windows/desktop/WmiSdk/wmi-error-constants).

## Remarks

Do not specify *strUser*, *strPassword*, or *strAuthority* when making a connection to a local namespace. For more information, see [Connecting to WMI on a Remote Computer](https://learn.microsoft.com/windows/desktop/WmiSdk/connecting-to-wmi-on-a-remote-computer).

For more information on how to use **ConnectServer**, see [Creating a Connection to a WMI Namespace](https://learn.microsoft.com/windows/desktop/WmiSdk/creating-a-connection-to-a-wmi-namespace). Note that the connection to [IWbemLocator](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemlocator) is one of the connections that you must shut down at the end of your application, as described in [Cleaning up and Shutting Down a WMI Application](https://learn.microsoft.com/windows/desktop/WmiSdk/cleaning-up-and-shutting-down-a-wmi-application).

## Examples

For multiple samples that use the **ConnectServer** method, see [WMI C++ Application Examples](https://learn.microsoft.com/windows/desktop/WmiSdk/wmi-c---application-examples).

The following C++ code sample describes how to use smi2smir.xml to connect to a specified namespace.

```cpp
int _tmain(int argc, _TCHAR* argv[])
{
    // Initialize COM. ------------------------------------------
    HRESULT hres = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
    if (FAILED(hres))
    {
        wcout << "CoInitializeEx() failure:" << hex << (unsigned long)hres;
        return 0;
    }

    // Obtain the initial locator to Windows Management
    // on a particular host computer.
    IWbemLocator *pLoc = NULL;
    hres = CoCreateInstance(CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER,IID_IWbemLocator, (LPVOID *)&pLoc);
    if (FAILED(hres))
    {
        CoUninitialize();
        wcout << "CreateInstance failure:" << hex << (unsigned long)hres;
        return 0;
    }

    // Connect to WMI through the IWbemLocator::ConnectServer method
    // Connect to the local ROOT\CIMV2 namespace
    // and obtain pointer pSvc to make IWbemServices calls.
    IWbemServices *pSvc = NULL;
    BSTR namespace = SysAllocString(L"ROOT\\CimV2");
    hres = pLoc->ConnectServer(namespace, NULL, NULL, 0, NULL, 0, 0, &pSvc);
    SysFreeString(namespace);

    if (FAILED(hres))
    {
        pLoc->Release();
        CoUninitialize();
        wcout << "ConnectServer() failure:" << hex << (unsigned long)hres;
        return 0;
    }
    ...
}
```

## See also

[Connecting to WMI on a Remote Computer](https://learn.microsoft.com/windows/desktop/WmiSdk/connecting-to-wmi-on-a-remote-computer)

[Creating a WMI Application Using C++](https://learn.microsoft.com/windows/desktop/WmiSdk/creating-a-wmi-application-using-c-)

[IWbemLocator](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemlocator)

[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices)

[WBEM_CONNECT_OPTIONS](https://learn.microsoft.com/windows/win32/api/wbemcli/ne-wbemcli-wbem_connect_options)