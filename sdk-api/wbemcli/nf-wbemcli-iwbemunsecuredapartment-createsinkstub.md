# IWbemUnsecuredApartment::CreateSinkStub

## Description

The [CreateSinkStub](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iunsecuredapartment-createobjectstub) method is
similar to the
**IUnsecuredApartment::CreateObjectStub**
and creates an object forwarder sink and performs access checks for receiving asynchronous calls from Windows
Management. **CreateSinkStub** differs from
**CreateObjectStub** because it can
specify that callbacks to the sink should be authenticated.

WMI provides the Unsecapp.exe process to function as the separate process. You can host
Unsecapp.exe with a call to the
[IWbemUnsecuredApartment](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemunsecuredapartment) interface or
[IUnsecuredApartment](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iunsecuredapartment) interface in other versions of
Windows. **IUnsecuredApartment** does not have any methods
that perform access checking.

An access check means that Unsecapp.exe only allows the account of the computer that
originally obtained the sink to invoke callbacks. When the registry key
**UnsecAppAccessControlDefault** is set to zero then Unsecapp.exe
does not perform access control on callbacks unless
[CreateSinkStub](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iunsecuredapartment-createobjectstub) is called by an
application with the *dwFlag* parameter set to
**WBEM_FLAG_UNSECAPP_CHECK_ACCESS**. If the parameter is not present, which is the default,
then Unsecapp.exe reads the registry key value to determine whether to authenticate
callbacks.

## Parameters

### `pSink` [in]

Pointer to the client's in-process implementation of
[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink).

### `dwFlags` [in]

You can set one of the following values from
[WBEM_UNSECAPP_FLAG_TYPE](https://learn.microsoft.com/windows/win32/api/wbemcli/ne-wbemcli-wbem_unsecapp_flag_type) enumeration. This
parameter determines how Unsecapp.exe uses the registry key checks this registry key:

**HKEY_LOCAL_MACHINE**\**SOFTWARE**\**Microsoft**\**WBEM**\**CIMOM**\**UnsecAppAccessControlDefault**

#### WBEM_FLAG_UNSECAPP_DEFAULT_CHECK_ACCESS

Unsecapp.exe reads the registry key
**UnsecAppAccessControlDefault** to determine if it should authenticate
callbacks.

#### WBEM_FLAG_UNSECAPP_CHECK_ACCESS

Unsecapp.exe authenticates callbacks regardless of the setting of the registry key
**UnsecAppAccessControlDefault**.

#### WBEM_FLAG_UNSECAPP_DONT_CHECK_ACCESS

Unsecapp.exe does not authenticate callbacks regardless of the setting of the
registry key **UnsecAppAccessControlDefault**.

### `wszReserved`

Reserved.

### `ppStub` [out]

Receives a pointer to a substitute object to be used in asynchronous
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) calls. The user receives an
[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer and must call
[QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) for
**IID_WbemObjectSink** before using this object in asynchronous
**IWbemServices** calls.

## Return value

This method returns standard COM error codes for
[QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)). It returns
**S_OK** if the call succeeds. If the call fails because the requested interface was not
supported, the method returns **E_NOINTERFACE**.

COM-specific error codes also may be returned if network problems cause you to lose the remote connection to
Windows Management.

## Remarks

This method is provided to improve the security of asynchronous calls
from client applications. For more information, see
[Setting Security on an Asynchronous Call](https://learn.microsoft.com/windows/desktop/WmiSdk/setting-security-on-an-asynchronous-call).

## See also

[IUnsecuredApartment::CreateObjectStub](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iunsecuredapartment-createobjectstub)

[IWbemUnsecuredApartment](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemunsecuredapartment)

[Lowering the Security for a Sink in a Separate Process](https://learn.microsoft.com/windows/desktop/WmiSdk/lowering-the-security-for-a-sink-in-a-separate-process)

[Performing Access Checks](https://learn.microsoft.com/windows/desktop/WmiSdk/performing-access-checks)

[Setting Security on an Asynchronous Call](https://learn.microsoft.com/windows/desktop/WmiSdk/setting-security-on-an-asynchronous-call)