# IWbemEventSink::SetSinkSecurity

## Description

The
**IWbemEventSink::SetSinkSecurity** method is used to set a security descriptor (SD) on a sink for all the events passing through. WMI handles the access checks based on the SD. Use this method when the provider cannot control what users are allowed to consume its events, but can set an SD for a specific sink.

## Parameters

### `lSDLength` [in]

Length of security descriptor.

### `pSD` [in]

Security descriptor, DACL.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## Remarks

The SD DACL defines who has access to the events. The access control entry (ACE) of a consumer seeking access to the events delivered to the sink must match an ACE with **WBEM_RIGHT_SUBSCRIBE** set in the *pSD* parameter. The SD owner and group specify the identity to be used when raising the event. This identity can be different than the identity of the account raising the event; however, when checking access of the event against a filter SD, both the identity of the user and the identity specified in the owner field are checked for access. For more information, see the **EventAccess** property of the
[__EventFilter](https://learn.microsoft.com/windows/desktop/WmiSdk/--eventfilter) class. The group field of the SD must be set and the SACL field is not used. For more information about event security and when to use this method, see [Securing WMI Events](https://learn.microsoft.com/windows/desktop/WmiSdk/securing-wmi-events).

For more information about providing events, see [Writing an Event Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/writing-an-event-provider).

#### Examples

The following code example sets the SD for all the events provided through the sink.The code requires the following #include statements and references.

```cpp
#define _WIN32_WINNT 0x0500
#define SECURITY_WIN32
#pragma comment(lib, "wbemuuid.lib")
#pragma comment(lib, "Secur32.lib")
#include <windows.h>
#include <sddl.h>
#include <wbemidl.h>
#include <security.h>
#include <iostream>
using namespace std;

HRESULT CMyEventProvider::ProvideEvents( IWbemObjectSink *pSink,
                                            long lFlags )
{
    IWbemEventSink *pEventSink = NULL;
    //Create SD with allowing only administrators
    // to receive events. O:BAG:BAD:(A;;0x40;;;BA)
     long lMask = WBEM_RIGHT_SUBSCRIBE;
     WCHAR wBuf[MAX_PATH];
     _ltow( lMask, wBuf, 16 );

       wstring wstrSD = L"O:BAG:BAD:(A;;0x";
        wstrSD += lMask;
       wstrSD += L";;;BA)";
    ULONG ulSize = 0;
    PSECURITY_DESCRIPTOR pSD = NULL;

    ConvertStringSecurityDescriptorToSecurityDescriptorW(
        wstrSD.c_str(), SDDL_REVISION_1, &pSD, &ulSize );
    HRESULT hRes = pSink->QueryInterface( IID_IWbemEventSink,
        (void**)pEventSink );
    if( SUCCEEDED(hRes) )
        hRes = pEventSink->SetSinkSecurity( ulLength, pSD );
    LocalFree(pSD );
    return hRes;
}
```