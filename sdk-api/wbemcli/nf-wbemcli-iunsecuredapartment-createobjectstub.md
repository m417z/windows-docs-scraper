# IUnsecuredApartment::CreateObjectStub

## Description

The
**CreateObjectStub** method creates an object forwarder sink to assist in receiving asynchronous calls from Windows Management. This function binds an unsecured object sink to a local object sink so that COM security does not interfere with asynchronous retrieval of CIM objects. Because COM security is being bypassed, the remote Windows Management server is assumed to be a trusted component.

The general paradigm is that the original implementation of
[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink) in the client process is not directly used in asynchronous calls to
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices). Rather, both the original implementation and a substitute object are created, bound together, and then the substitute object is used in the asynchronous methods of
**IWbemServices**.

## Parameters

### `pObject` [in]

Pointer to the client's in-process implementation of
[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink).

### `ppStub` [out]

Receives a pointer to a substitute object to be used in asynchronous
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) calls. The user receives an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer and must call [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) for **IID_WbemObjectSink** before using this object in asynchronous
**IWbemServices** calls.

## Return value

This method returns standard COM error codes for [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)). It returns **S_OK** if the call succeeds. If the call fails because the requested interface was not supported, the method returns **E_NOINTERFACE**.

COM-specific error codes also may be returned if network problems cause you to lose the remote connection to Windows Management.

## Remarks

**Note** Because the call-back to the sink might not be returned at the same authentication level as the client requires, it is recommended that you use semisynchronous instead of asynchronous communication. For more information, see [Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

#### Examples

For a complete example that shows how to use the [IUnsecuredApartment](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iunsecuredapartment) interface, see [Example: Receiving Event Notifications Through WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/example--receiving-event-notifications-through-wmi-).

## See also

[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method)

[IUnsecuredApartment](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iunsecuredapartment)

[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink)

[IWbemUnsecuredApartment::CreateSinkStub](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemunsecuredapartment-createsinkstub)

[Lowering the Security for a Sink in a Separate Process](https://learn.microsoft.com/windows/desktop/WmiSdk/lowering-the-security-for-a-sink-in-a-separate-process)

[Performing Access Checks](https://learn.microsoft.com/windows/desktop/WmiSdk/performing-access-checks)

[Setting Security on an Asynchronous Call](https://learn.microsoft.com/windows/desktop/WmiSdk/setting-security-on-an-asynchronous-call)