# WZCRefreshInterface function

\[**WZCRefreshInterface** is not supported as of Windows Vista and Windows Server 2008. Instead, use the [Native Wifi API](https://learn.microsoft.com/windows/win32/nativewifi/native-wifi-reference), which provides similar functionality. For more information, see [About the Native Wifi API](https://learn.microsoft.com/windows/win32/nativewifi/about-the-native-wifi-api).\]

The **WZCRefreshInterface** function refreshes interface information for a specific wireless LAN interface.

## Parameters

*pSrvAddr* \[in\]

A pointer to a string containing the name of the computer on which to execute this function. If this parameter is **NULL**, then the Wireless Zero Configuration service is called on the local computer.

If the *pSrvAddr* parameter specified is a remote computer, then the remote computer must support remote RPC calls.

*dwInFlags* \[in\]

A set of fields to be refreshed along with specific refresh actions to be taken. This is a bitmask that can contain any combination of the following flags.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**INTF\_DESCR**

0x00010000

| Refresh the interface description for a wireless LAN interface.<br> The refreshed interface description can be retrieved by calling the [**WZCQueryInterface**](https://learn.microsoft.com/windows/win32/nativewifi/wzcqueryinterface) function with the **INTF\_DESCR** bit set in the *dwInFlags* parameter. The interface description is returned in the **wszDescr** member of the [**INTF\_ENTRY**](https://learn.microsoft.com/windows/win32/nativewifi/intf-entry) structure pointed to by the *pIntf* parameter that is returned by the **WZCQueryInterface** function.<br> |
|

**INTF\_NDISMEDIA**

0x00020000

| Refresh the NDIS media information for a wireless LAN interface.<br> The refreshed NDIS media information can be retrieved by calling the [**WZCQueryInterface**](https://learn.microsoft.com/windows/win32/nativewifi/wzcqueryinterface) function with the **INTF\_NDISMEDIA** bit set in the *dwInFlags* parameter. The NDIS media information is returned in the **ulMediaState**, **ulMediaType**, and **ulPhysicalMediaType** members of the [**INTF\_ENTRY**](https://learn.microsoft.com/windows/win32/nativewifi/intf-entry) structure pointed to by the *pIntf* parameter that is returned by the **WZCQueryInterface** function.<br> |
|

**INTF\_ALL\_OIDS**

0xFFF00000

| Refresh all of the NDIS OIDs for a wireless LAN interface. This option refreshes most of the data for a wireless LAN interface.<br> The refreshed information can be retrieved by calling the [**WZCQueryInterface**](https://learn.microsoft.com/windows/win32/nativewifi/wzcqueryinterface) function.<br> |

*pIntf* \[in\]

A pointer to an [**INTF\_ENTRY**](https://learn.microsoft.com/windows/win32/nativewifi/intf-entry) structure that contains the key of the interface to be refreshed.

*pdwOutFlags* \[out\]

A set of fields that were successfully refreshed.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
|----------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **ERROR\_ARENA\_TRASHED** | The storage control blocks were destroyed. This error is returned if the Wireless Zero Configuration service has not initialized internal objects.<br> |
| **ERROR\_FILE\_NOT\_FOUND** | The system cannot find the file specified. This error is returned if the GUID in the **wszGuid** member of the [**INTF\_ENTRY**](https://learn.microsoft.com/windows/win32/nativewifi/intf-entry) structure pointed to by the *pIntf* parameter did not match any of the wireless LAN interfaces on the local computer. <br> |
| **ERROR\_INVALID\_PARAMETER** | A parameter is incorrect. This error is returned if the *pIntf* parameter is **NULL**. This error is returned if the **wszGuid** member of the [**INTF\_ENTRY**](https://learn.microsoft.com/windows/win32/nativewifi/intf-entry) structure pointed to by the *pIntf* parameter is **NULL**. <br> |
| **RPC\_STATUS** | Various error codes.<br> |

## Remarks

The **wszGuid** member of the [**INTF\_ENTRY**](https://learn.microsoft.com/windows/win32/nativewifi/intf-entry) structure pointed to by the *pIntf* parameter must contain an interface GUID for a wireless LAN interface. A list of wireless LAN interfaces can be retrieved by calling the [**WZCEnumInterfaces**](https://learn.microsoft.com/windows/win32/nativewifi/wzcenuminterfaces) function.

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

[**WZCEapolGetInterfaceParams**](https://learn.microsoft.com/windows/win32/nativewifi/wzceapolgetinterfaceparams)

[**WZCEnumInterfaces**](https://learn.microsoft.com/windows/win32/nativewifi/wzcenuminterfaces)

[**WZCQueryInterface**](https://learn.microsoft.com/windows/win32/nativewifi/wzcqueryinterface)

[**INTF\_ENTRY**](https://learn.microsoft.com/windows/win32/nativewifi/intf-entry)

