# DOT11EXTIHV_PERFORM_PRE_ASSOCIATE callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The operating system calls the
*Dot11ExtIhvPerformPreAssociate* function to request that the IHV Extensions DLL initiate a
pre-association operation with the basic service set (BSS) network.

## Parameters

### `hIhvExtAdapter` [in, optional]

The handle used by the IHV Extensions DLL to reference the wireless LAN (WLAN) adapter. This
handle value was specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `hConnectSession` [in, optional]

The handle used by the operating system to reference the connection session with the basic service
set (BSS) network.

### `pIhvProfileParams` [in, optional]

A pointer to a
[DOT11EXT_IHV_PROFILE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihvtypes/ns-wlanihvtypes-_dot11ext_ihv_profile_params) structure. This structure defines the attributes of the basic service
set (BSS) network to which the profile extensions will be applied.

### `pIhvConnProfile` [in]

A pointer to a
[DOT11EXT_IHV_CONNECTIVITY_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_connectivity_profile) structure that contains connectivity settings for the IHV
profile.

### `pIhvSecProfile` [in]

A pointer to a
[DOT11EXT_IHV_SECURITY_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_security_profile) structure that specifies security settings for the IHV
profile.

### `pConnectableBssid` [in]

A pointer to a
[DOT11_BSS_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlclient/ns-wlclient-_dot11_bss_list) structure, which contains one
or more 802.11 Beacon or Probe Response frames for the service set identifier (SSID) of the BSS network
with which the DLL will perform the pre-association operation.

### `pdwReasonCode` [out]

A pointer to a DWORD value, which provides additional information for the return value of the
*Dot11ExtIhvPerformPreAssociate* function. The IHV Extensions DLL must set *
*pdwReasonCode* to an L2_REASON_CODE_xxxx value, which are defined in
L2cmn.h.

## Return value

If the IHV Extension DLL can initiate the pre-association operation, it must complete the operation
asynchronously. In this situation, the function returns ERROR_SUCCESS.

If the IHV Extensions DLL cannot initiate the pre-association operation, it returns an error code
defined in
*Winerror.h*.

## Prototype

```cpp
DOT11EXTIHV_PERFORM_PRE_ASSOCIATE Dot11ExtIhvPerformPreAssociate;

DWORD APIENTRY Dot11ExtIhvPerformPreAssociate(
  _In_opt_ HANDLE                             hIhvExtAdapter,
  _In_opt_ HANDLE                             hConnectSession,
  _In_opt_ PDOT11EXT_IHV_PROFILE_PARAMS       pIhvProfileParams,
  _In_     PDOT11EXT_IHV_CONNECTIVITY_PROFILE pIhvConnProfile,
  _In_     PDOT11EXT_IHV_SECURITY_PROFILE     pIhvSecProfile,
  _In_     PDOT11_BSS_LIST                    pConnectableBssid,
  _Out_    PDWORD                             pdwReasonCode
)
{ ... }
```

## Remarks

The operating system calls the
*Dot11ExtIhvPerformPreAssociate* function to initiate a pre-association operation with the IHV
Extensions DLL. The operating system initiates this operation before it initiates a connection operation
with a basic service set (BSS) network through the WLAN adapter. For more information about the
connection operation, see
[Connection Operations](https://learn.microsoft.com/windows-hardware/drivers/network/connection-operations).

The pre-association operation must be completed asynchronously from the call to
*Dot11ExtIhvPerformPreAssociate*. After the pre-association operation completes, the IHV Extensions
DLL must call
[Dot11ExtPreAssociateCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_pre_associate_completion).

When the
*Dot11ExtIhvPerformPreAssociate* function is called, the IHV Extensions DLL must follow these
guidelines.

* If the IHV Extensions DLL can initiate the pre-association operation, the
  *Dot11ExtIhvPerformPreAssociate* function must return ERROR_SUCCESS and complete the operation
  asynchronously.
* The IHV Extensions DLL provides more information regarding the initiation of the pre-association
  operation through the
  *pdwReasonCode* parameter. The DLL must set *
  *pdwReasonCode* to one of the following:

  + L2_REASON_CODE_SUCCESS, if the pre-association operation can initiated successfully.
  + An appropriate L2_REASON_CODE_xxxx error value, if the pre-association operation could not be
    initiated.
  + An IHV-defined value in the range from L2_REASON_CODE_IHV_BASE to (L2_REASON_CODE_IHV_BASE+
    L2_REASON_CODE_GROUP_SIZE-1), regardless of whether the pre-association operation could be initiated
    or not.

For more information about the pre-association operation, see
[Pre-Association Operation](https://learn.microsoft.com/windows-hardware/drivers/network/pre-association-operation-overview).

## See also

[DOT11EXT_IHV_CONNECTIVITY_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_connectivity_profile)

[DOT11EXT_IHV_SECURITY_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_security_profile)

[DOT11_BSS_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlclient/ns-wlclient-_dot11_bss_list)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)

[Dot11ExtPreAssociateCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_pre_associate_completion)

[OID_DOT11_CONNECT_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-connect-request)

[Native 802.11 IHV
Extensibility Functions](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-ihv-extensibility-functions)

[DOT11EXT_IHV_PROFILE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihvtypes/ns-wlanihvtypes-_dot11ext_ihv_profile_params)