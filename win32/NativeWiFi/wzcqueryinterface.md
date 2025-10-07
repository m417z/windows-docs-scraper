# WZCQueryInterface function

\[**WZCQueryInterface** is no longer supported as of Windows Vista and Windows Server 2008. Use the [**WlanQueryInterface**](https://learn.microsoft.com/windows/desktop/api/Wlanapi/nf-wlanapi-wlanqueryinterface) function instead. For more information, see [About the Native Wifi API](https://learn.microsoft.com/windows/win32/nativewifi/about-the-native-wifi-api). \]

The **WZCQueryInterface** function provides detailed information for a wireless LAN interface managed by the Wireless Zero Configuration service.

Provides detailed information for a given interface.

## Parameters

*pSrvAddr* \[in\]

A pointer to a string containing the name of the computer on which to execute this function. If this parameter is **NULL**, then the Wireless Zero Configuration service is queried on the local computer.

If the *pSrvAddr* parameter specified is a remote computer, then the remote computer must support remote RPC calls.

*dwInFlags* \[in\]

The fields to be queried. This is a bitmask that can contain any combination of the following flags.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**INTF\_DYNFLAGS**

0x00000010

| Return the value for the **dwDynFlags** member in the [**INTF\_ENTRY**](https://learn.microsoft.com/windows/win32/nativewifi/intf-entry) structure pointed to by the *pIntf* parameter.<br> |
|

**INTF\_DESCR**

0x00010000

| Return the value for the **wszDescr** member in the [**INTF\_ENTRY**](https://learn.microsoft.com/windows/win32/nativewifi/intf-entry) structure pointed to by the *pIntf* parameter.<br> |
|

**INTF\_NDISMEDIA**

0x00020000

| Return the values for the **ulMediaState**, **ulMediaType**, and **ulPhysicalMediaType** members in the [**INTF\_ENTRY**](https://learn.microsoft.com/windows/win32/nativewifi/intf-entry) structure pointed to by the *pIntf* parameter.<br> |
|

**INTF\_PREFLIST**

0x00040000

| Return the preferred list of networks in the **rdStSSIDList** member of the [**INTF\_ENTRY**](https://learn.microsoft.com/windows/win32/nativewifi/intf-entry) structure pointed to by the *pIntf* parameter.<br> |
|

**INTF\_CAPABILITIES**

0x00080000

| Return the values for the **dwCapabilities** and the **rdNicCapabilities** members in the [**INTF\_ENTRY**](https://learn.microsoft.com/windows/win32/nativewifi/intf-entry) structure pointed to by the *pIntf* parameter.<br> |
|

**INTF\_INFRAMODE**

0x00200000

| Return the value for the **nInfraMode** member in the [**INTF\_ENTRY**](https://learn.microsoft.com/windows/win32/nativewifi/intf-entry) structure pointed to by the *pIntf* parameter.<br> The **nInfraMode** member is valid only in some interface context states.<br> |
|

**INTF\_AUTHMODE**

0x00400000

| Return the value for the **nAuthMode** member in the [**INTF\_ENTRY**](https://learn.microsoft.com/windows/win32/nativewifi/intf-entry) structure pointed to by the *pIntf* parameter. <br> The **nAuthMode** member is valid only in some interface context states.<br> |
|

**INTF\_WEPSTATUS**

0x00800000

| Return the value for the **nWepStatus** member in the [**INTF\_ENTRY**](https://learn.microsoft.com/windows/win32/nativewifi/intf-entry) structure pointed to by the *pIntf* parameter. <br> The **nWepStatus** member is valid only in some interface context states.<br> |
|

**INTF\_SSID**

0x01000000

| Return the value for the **rdSSID** member in the [**INTF\_ENTRY**](https://learn.microsoft.com/windows/win32/nativewifi/intf-entry) structure pointed to by the *pIntf* parameter.<br> The **rdSSID** member is valid only in some interface context states.<br> |
|

**INTF\_BSSID**

0x02000000

| Return the value for the **rdBSSID** member in the [**INTF\_ENTRY**](https://learn.microsoft.com/windows/win32/nativewifi/intf-entry) structure pointed to by the *pIntf* parameter.<br> The **rdBSSID** member is valid only in some interface context states.<br> |
|

**INTF\_BSSIDLIST**

0x04000000

| Return the visible list of networks in the **rdBSSIDList** member of the [**INTF\_ENTRY**](https://learn.microsoft.com/windows/win32/nativewifi/intf-entry) structure pointed to by the *pIntf* parameter.<br> The **rdBSSIDList** member is valid only in some interface context states.<br> |

*pIntf* \[in, out\]

On input, a pointer to the key of the interface to query. On output, a pointer to the requested interface data. This parameter is a pointer to an [**INTF\_ENTRY**](https://learn.microsoft.com/windows/win32/nativewifi/intf-entry) structure.

*pdwOutFlags* \[out\]

A set of fields successfully retrieved.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
|-----------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **ERROR\_ARENA\_TRASHED** | The storage control blocks were destroyed. This error is returned if the Wireless Zero Configuration service has not initialized internal objects.<br> |
| **ERROR\_FILE\_NOT\_FOUND** | The system cannot find the file specified. This error is returned if the GUID in the **wszGuid** member of the [**INTF\_ENTRY**](https://learn.microsoft.com/windows/win32/nativewifi/intf-entry) structure pointed to by the *pIntf* parameter did not match any of the wireless LAN interfaces on the local computer. <br> |
| **ERROR\_INVALID\_PARAMETER** | A parameter is incorrect. This error is returned if the *pIntf* parameter is **NULL**. This error is returned if the **wszGuid** member of the [**INTF\_ENTRY**](https://learn.microsoft.com/windows/win32/nativewifi/intf-entry) structure pointed to by the *pIntf* parameter is **NULL**. <br> |
| **ERROR\_NOT\_ENOUGH\_MEMORY** | Not enough memory is available to process this request and allocate memory for the query results.<br> |
| **RPC\_STATUS** | Various error codes.<br> |

## Remarks

The **wszGuid** member of the [**INTF\_ENTRY**](https://learn.microsoft.com/windows/win32/nativewifi/intf-entry) structure pointed to by the *pIntf* parameter must contain an interface GUID for a wireless LAN interface. A list of wireless LAN interfaces can be retrieved by calling the [**WZCEnumInterfaces**](https://learn.microsoft.com/windows/win32/nativewifi/wzcenuminterfaces) function.

The following members of the [**INTF\_ENTRY**](https://learn.microsoft.com/windows/win32/nativewifi/intf-entry) structure pointed to by *pIntf* must be set to 0 before a call to the **WZCQueryInterface** function: **rdSSID**, **rdBSSID**, **rdBSSIDList**, **rdStSSIDList**, and **rdCtrlData**.

The Wireless Zero Configuration service does not automatically update media state, even when media connected and disconnected events are received. An application should force a media state refresh by calling the [**WZCRefreshInterface**](https://learn.microsoft.com/windows/win32/nativewifi/wzcrefreshinterface) function before calling the **WZCQueryInterface** function if the NDIS media state is to be requested (the INTF\_NDISMEDIA bit will be set in the *dwInFlags* parameter).

When the *dwInFlags* parameter contains **INTF\_BSSIDLIST**, the **WZCQueryInterface** function does not set the *dwOutFlags* with **INTF\_BSSIDLIST** if the visible list of networks is empty. When the *dwInFlags* parameter contains **INTF\_SSID**, the **WZCQueryInterface** function does not set the *dwOutFlags* with **INTF\_SSID** if no SSID is available.

If the **WZCQueryInterface** function returns ERROR\_SUCCESS, the caller should call the [**LocalFree**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-localfree) function with the *pIntf* parameter to release the internal buffers allocated for the data returned once this information is no longer needed. This releases the buffers used by the **rdSSID**, **rdBSSID**, **rdBSSIDList**, **rdStSSIDList**, and **rdCtrlData** members of the [**INTF\_ENTRY**](https://learn.microsoft.com/windows/win32/nativewifi/intf-entry) structure pointed to by *pIntf* parameter.

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

[**INTF\_ENTRY**](https://learn.microsoft.com/windows/win32/nativewifi/intf-entry)

[**WZCEapolGetInterfaceParams**](https://learn.microsoft.com/windows/win32/nativewifi/wzceapolgetinterfaceparams)

[**WZCEnumInterfaces**](https://learn.microsoft.com/windows/win32/nativewifi/wzcenuminterfaces)

[**WZCRefreshInterface**](https://learn.microsoft.com/windows/win32/nativewifi/wzcrefreshinterface)

