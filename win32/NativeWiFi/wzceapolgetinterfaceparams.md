# WZCEapolGetInterfaceParams function

\[**WZCEapolGetInterfaceParams** is no longer supported as of Windows Vista and Windows Server 2008. Instead, use the [Native Wifi API](https://learn.microsoft.com/windows/win32/nativewifi/native-wifi-reference), which provides similar functionality. For more information, see [About the Native Wifi API](https://learn.microsoft.com/windows/win32/nativewifi/about-the-native-wifi-api).\]

The **WZCEapolGetInterfaceParams** function gets EAPOL configuration parameters for the specified wireless LAN interface.

## Parameters

*pSrvAddr* \[in\]

A pointer to a string containing the name of the computer on which to execute this function. If this parameter is **NULL**, then the Wireless Zero Configuration service is called on the local computer.

If the *pSrvAddr* parameter specified is a remote computer, then the remote computer must support remote RPC calls.

*pwszGuid* \[in\]

The GUID of the interface for which data is to be retrieved.

*dwSizeOfSSID* \[in\]

The size of the network identifier for which data is to be retrieved.

*pbSSID* \[in\]

A pointer to the network identifier for which data is to be retrieved.

*pIntfParams* \[in, out\]

A pointer to a [**EAPOL\_INTF\_PARAMS**](https://learn.microsoft.com/windows/win32/nativewifi/eapol-intf-params) structure that contains interface parameters.

## Return value

Returns ERROR\_SUCCESS if the operation completes successfully; otherwise, returns one of the Windows system error codes.

## Remarks

If the **WZCEapolGetInterfaceParams** returns ERROR\_SUCCESS, the caller should call [**LocalFree**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-localfree) to release the internal buffers allocated for the data returned once this information is no longer needed.

> [!Note]
> The *Wzcsapi.h* header file and *Wzcsapi.lib* import library file are not available in the Windows SDK.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP with SP2 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| End of client support<br> | Windows XP with SP3<br> |
| End of server support<br> | Windows Server 2003<br> |
| Header<br> | Wzcsapi.h |
| Library<br> | Wzcsapi.lib |
| DLL<br> | Wzcsapi.dll |

## See also

[**WZCEnumInterfaces**](https://learn.microsoft.com/windows/win32/nativewifi/wzcenuminterfaces)

[**WZCQueryInterface**](https://learn.microsoft.com/windows/win32/nativewifi/wzcqueryinterface)

[**WZCRefreshInterface**](https://learn.microsoft.com/windows/win32/nativewifi/wzcrefreshinterface)

