# DOT11EXT_POST_ASSOCIATE_COMPLETION callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The IHV Extensions DLL calls the
**Dot11ExtPostAssociateCompletion** function to asynchronously complete a
post-association operation initiated through a call to the
[Dot11ExtIhvPerformPostAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_post_associate) IHV Handler function.

## Parameters

### `hDot11SvcHandle` [in, optional]

The handle used by the operating system to reference the wireless LAN (WLAN) adapter. This handle
value was specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `hSecuritySessionID` [in, optional]

The handle of the security session identifier (ID) returned through a previous call to the
[Dot11ExtIhvPerformPostAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_post_associate) IHV Handler function.

### `pPeer` [in, optional]

The media access control (MAC) address of the access point (AP) with which the IHV Extensions DLL
performed a security operation. This parameter is formatted as a
[DOT11_MAC_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_mac_address) structure.

**Note** For Windows Vista, the IHV Extensions DLL supports only infrastructure basic
service set (BSS) networks.

### `dwReasonCode` [in]

A value that provides additional information for the completion status of the post-association
operation. The IHV Extensions DLL must set
*dwReasonCode* to an L2_REASON_CODE_xxxx value, which are defined in
L2cmn.h.

The IHV Extensions DLL returns the general completion status of the post-association operation
through the
*dwWin32Error* parameter. Typically, the IHV Extensions DLL sets
*dwReasonCode* to a value within the range from L2_REASON_CODE_IHV_BASE to (L2_REASON_CODE_IHV_BASE+
L2_REASON_CODE_GROUP_SIZE-1).

### `dwWin32Error` [in]

The completion status of the post-association operation as defined by an error code within
Winerror.h. If the operation completes successfully, the IHV Extensions DLL must set
*dwWin32Error* to ERROR_SUCCESS.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DWORD WINAPI * Dot11ExtPostAssociateCompletion(
  _In_opt_ HANDLE             hDot11SvcHandle,
  _In_opt_ HANDLE             hSecuritySessionID,
  _In_opt_ PDOT11_MAC_ADDRESS pPeer,
  _In_     DWORD              dwReasonCode,
  _In_     DWORD              dwWin32Error
);
```

## Remarks

The IHV Extensions DLL calls the
*Dot11ExtPostAssociateCompletion* function to do any of the following:

* Complete the post-association operation initiated by a call to the
  [Dot11ExtIhvPerformPostAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_post_associate) IHV Handler function.
* After completing the post-association operation, indicate a change in the port state for the
  security session referenced by the
  *hSecuritySessionID* parameter.

  For example, if the authorization state of the port changes, the IHV Extensions DLL can notify the
  operating system by calling
  *Dot11ExtPostAssociateCompletion*.

The IHV Extensions DLL must follow these guidelines when calling the
**Dot11ExtPostAssociateCompletion** function.

* If the post-association operation completed successfully, the IHV Extensions DLL must set
  *dwReasonCode* to one of the following:

  + L2_REASON_CODE_SUCCESS.
  + An IHV-defined value in the range from L2_REASON_CODE_IHV_BASE to (L2_REASON_CODE_IHV_BASE+
    L2_REASON_CODE_GROUP_SIZE-1).In this situation, the IHV Extensions DLL must set
  *dwWin32Error* to ERROR_SUCCESS.

  **Note** If the IHV Extensions DLL sets
  *dwWin32Error* to ERROR_SUCCESS, the operating system will assume that the port state for the
  security session is in an authorized state. After the port is in an authorized state, the operating
  system allows all data packets to be sent through the WLAN adapter.
* If the post-association operation completed with a failure, the IHV Extensions DLL must not set
  *dwReasonCode* to L2_REASON_CODE_SUCCESS. Instead, the DLL must set
  *dwReasonCode* to one of the following:

  + An appropriate L2_REASON_CODE_xxxx error value.
  + An IHV-defined value in the range from L2_REASON_CODE_IHV_BASE to (L2_REASON_CODE_IHV_BASE+
    L2_REASON_CODE_GROUP_SIZE-1).In this situation, the IHV Extensions DLL must not set
  *dwWin32Error* to ERROR_SUCCESS. Instead, the DLL must set
  *dwWin32Error* to an appropriate error code defined in
  Winerror.h.

  **Note** If the IHV Extensions DLL does not set
  *dwWin32Error* to ERROR_SUCCESS, the operating system will assume the port state for the security
  session is in an unauthorized state. After the port is in an unauthorized state, the operating system
  allows security packets, including packets sent through the
  [Dot11ExtSendPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_send_packet) IHV Extensions
  function, to be sent through the WLAN adapter.
* The IHV Extensions DLL must call
  **Dot11ExtPostAssociateCompletion** to cancel all pending post-association operation whenever the
  [Dot11ExtIhvAdapterReset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_adapter_reset) or
  [Dot11ExtIhvDeinitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_deinit_adapter) IHV
  Handler functions are called. In this situation, the DLL must set the
  *dwStatus* parameter to ERROR_CANCELLED.

## See also

[Dot11ExtIhvAdapterReset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_adapter_reset)

[Dot11ExtIhvDeinitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_deinit_adapter)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)

[Native 802.11 IHV Handler
Functions](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-ihv-handler-functions)

[Dot11ExtIhvPerformPostAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_post_associate)

[DOT11_MAC_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_mac_address)

[Dot11ExtSendPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_send_packet)