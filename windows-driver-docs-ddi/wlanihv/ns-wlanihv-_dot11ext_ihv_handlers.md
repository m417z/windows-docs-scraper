# _DOT11EXT_IHV_HANDLERS structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11EXT_IHV_HANDLERS structure specifies a list of pointers to the IHV handler functions supported by the IHV Extensions DLL.

## Members

### `Dot11ExtIhvDeinitService`

A pointer to the
[Dot11ExtIhvDeinitService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_deinit_service) function.

### `Dot11ExtIhvInitAdapter`

A pointer to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) function.

### `Dot11ExtIhvDeinitAdapter`

A pointer to the
[Dot11ExtIhvDeinitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_deinit_adapter) function.

### `Dot11ExtIhvPerformPreAssociate`

A pointer to the
[Dot11ExtIhvPerformPreAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_pre_associate) function.

### `Dot11ExtIhvAdapterReset`

A pointer to the
[Dot11ExtIhvAdapterReset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_adapter_reset) function.

### `Dot11ExtIhvPerformPostAssociate`

A pointer to the
[Dot11ExtIhvPerformPostAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_post_associate) function.

### `Dot11ExtIhvStopPostAssociate`

A pointer to the
[Dot11ExtIhvStopPostAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_stop_post_associate) function.

### `Dot11ExtIhvValidateProfile`

A pointer to the
[Dot11ExtIhvValidateProfile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_validate_profile) function.

### `Dot11ExtIhvPerformCapabilityMatch`

A pointer to the
[Dot11ExtIhvPerformCapabilityMatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_capability_match) function.

### `Dot11ExtIhvCreateDiscoveryProfiles`

A pointer to the
[Dot11ExtIhvCreateDiscoveryProfiles](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_create_discovery_profiles) function.

### `Dot11ExtIhvProcessSessionChange`

A pointer to the
[Dot11ExtIhvProcessSessionChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_process_session_change) function.

### `Dot11ExtIhvReceiveIndication`

A pointer to the
[Dot11ExtIhvReceiveIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_receive_indication) function.

### `Dot11ExtIhvReceivePacket`

A pointer to the
[Dot11ExtIhvReceivePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_receive_packet) function.

### `Dot11ExtIhvSendPacketCompletion`

A pointer to the
[Dot11ExtIhvSendPacketCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_send_packet_completion) function.

### `Dot11ExtIhvIsUIRequestPending`

A pointer to the
[Dot11ExtIhvIsUIRequestPending](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_is_ui_request_pending) function.

### `Dot11ExtIhvProcessUIResponse`

A pointer to the
[Dot11ExtIhvProcessUIResponse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_process_ui_response) function.

### `Dot11ExtIhvQueryUIRequest`

A pointer to the
[Dot11ExtIhvQueryUIRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_query_ui_request) function.

### `Dot11ExtIhvOnexIndicateResult`

A pointer to the
[Dot11ExtIhvOneXIndicateResult](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_onex_indicate_result) function.

### `Dot11ExtIhvControl`

A pointer to the
[Dot11ExtIhvControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_control) function.

## Syntax

```cpp
typedef struct _DOT11EXT_IHV_HANDLERS {
  DOT11EXTIHV_DEINIT_SERVICE            Dot11ExtIhvDeinitService;
  DOT11EXTIHV_INIT_ADAPTER              Dot11ExtIhvInitAdapter;
  DOT11EXTIHV_DEINIT_ADAPTER            Dot11ExtIhvDeinitAdapter;
  DOT11EXTIHV_PERFORM_PRE_ASSOCIATE     Dot11ExtIhvPerformPreAssociate;
  DOT11EXTIHV_ADAPTER_RESET             Dot11ExtIhvAdapterReset;
  DOT11EXTIHV_PERFORM_POST_ASSOCIATE    Dot11ExtIhvPerformPostAssociate;
  DOT11EXTIHV_STOP_POST_ASSOCIATE       Dot11ExtIhvStopPostAssociate;
  DOT11EXTIHV_VALIDATE_PROFILE          Dot11ExtIhvValidateProfile;
  DOT11EXTIHV_PERFORM_CAPABILITY_MATCH  Dot11ExtIhvPerformCapabilityMatch;
  DOT11EXTIHV_CREATE_DISCOVERY_PROFILES Dot11ExtIhvCreateDiscoveryProfiles;
  DOT11EXTIHV_PROCESS_SESSION_CHANGE    Dot11ExtIhvProcessSessionChange;
  DOT11EXTIHV_RECEIVE_INDICATION        Dot11ExtIhvReceiveIndication;
  DOT11EXTIHV_RECEIVE_PACKET            Dot11ExtIhvReceivePacket;
  DOT11EXTIHV_SEND_PACKET_COMPLETION    Dot11ExtIhvSendPacketCompletion;
  DOT11EXTIHV_IS_UI_REQUEST_PENDING     Dot11ExtIhvIsUIRequestPending;
  DOT11EXTIHV_PROCESS_UI_RESPONSE       Dot11ExtIhvProcessUIResponse;
  DOT11EXTIHV_QUERY_UI_REQUEST          Dot11ExtIhvQueryUIRequest;
  DOT11EXTIHV_ONEX_INDICATE_RESULT      Dot11ExtIhvOnexIndicateResult;
  DOT11EXTIHV_CONTROL                   Dot11ExtIhvControl;
} DOT11EXT_IHV_HANDLERS, *PDOT11EXT_IHV_HANDLERS;
```

## Remarks

The IHV handler functions are a set of callback functions supported by the IHV Extensions DLL. When
the operating system calls the
[Dot11ExtIhvInitService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_service) IHV
handler function, the IHV Extensions DLL returns the list of pointers to the IHV handler functions
through the
*pDot11IHVHandlers* parameter.

**Note** The operating system resolves the addresses of the
[Dot11ExtIhvGetVersionInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_get_version_info) and
[Dot11ExtIhvInitService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_service) IHV
handler functions through
**GetProcAddress**. For more information about
**GetProcAddress**, refer to the Microsoft Windows SDK documentation.

All of the function pointers are required and must not be set to **NULL**.

## See also

[Dot11ExtIhvAdapterReset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_adapter_reset)

[Dot11ExtIhvDeinitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_deinit_adapter)

[Dot11ExtIhvValidateProfile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_validate_profile)

[Dot11ExtIhvReceiveIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_receive_indication)

[Native 802.11 IHV Handler
Functions](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-ihv-handler-functions)

[Dot11ExtIhvOneXIndicateResult](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_onex_indicate_result)

[Dot11ExtIhvStopPostAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_stop_post_associate)

[Dot11ExtIhvPerformPostAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_post_associate)

[Dot11ExtIhvProcessSessionChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_process_session_change)

[Dot11ExtIhvGetVersionInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_get_version_info)

[Native 802.11 IHV
Extensibility Functions](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-ihv-extensibility-functions)

[Dot11ExtIhvCreateDiscoveryProfiles](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_create_discovery_profiles)

[Dot11ExtIhvQueryUIRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_query_ui_request)

[Dot11ExtIhvProcessUIResponse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_process_ui_response)

[Dot11ExtIhvReceivePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_receive_packet)

[Dot11ExtIhvControl Function](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_control)

[Dot11ExtIhvInitService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_service)

[Dot11ExtIhvPerformCapabilityMatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_capability_match)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)

[Dot11ExtIhvIsUIRequestPending](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_is_ui_request_pending)

[Dot11ExtIhvDeinitService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_deinit_service)

[Dot11ExtIhvPerformPreAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_pre_associate)

[Dot11ExtIhvSendPacketCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_send_packet_completion)