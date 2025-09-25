# WLAN_HOSTED_NETWORK_REASON enumeration

## Description

The **WLAN_HOSTED_NETWORK_REASON** enumerated type specifies the possible values for the result of a wireless Hosted Network function call.

## Constants

### `wlan_hosted_network_reason_success:0`

The operation was successful.

### `wlan_hosted_network_reason_unspecified`

Unknown error.

### `wlan_hosted_network_reason_bad_parameters`

Bad parameters.

For example, this reason code is returned if an application failed to reference the client context from the correct handle (the handle returned by the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function).

### `wlan_hosted_network_reason_service_shutting_down`

Service is shutting down.

### `wlan_hosted_network_reason_insufficient_resources`

Service is out of resources.

### `wlan_hosted_network_reason_elevation_required`

This operation requires elevation.

### `wlan_hosted_network_reason_read_only`

An attempt was made to write read-only data.

### `wlan_hosted_network_reason_persistence_failed`

Data persistence failed.

### `wlan_hosted_network_reason_crypt_error`

A cryptographic error occurred.

### `wlan_hosted_network_reason_impersonation`

User impersonation failed.

### `wlan_hosted_network_reason_stop_before_start`

An incorrect function call sequence was made.

### `wlan_hosted_network_reason_interface_available`

A wireless interface has become available.

### `wlan_hosted_network_reason_interface_unavailable`

A wireless interface has become unavailable.

This reason code is returned by the wireless Hosted Network functions any time the network state of the wireless Hosted Network is **wlan_hosted_network_unavailable**. For example if the wireless Hosted Network is disabled by group policy on a domain, then the network state of the wireless Hosted Network is **wlan_hosted_network_unavailable**. In this case, any calls to the [WlanHostedNetworkStartUsing](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkstartusing) or [WlanHostedNetworkForceStart](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkforcestart) function would return this reason code.

### `wlan_hosted_network_reason_miniport_stopped`

The wireless miniport driver stopped the Hosted Network.

### `wlan_hosted_network_reason_miniport_started`

The wireless miniport driver status changed.

### `wlan_hosted_network_reason_incompatible_connection_started`

An incompatible connection started.

An incompatible connection refers to one of the following cases:

* An ad hoc wireless connection is started on the primary station adapter.
* Network monitoring is started on the primary station adapter by an application (Network Monitor, for example) that calls the [WlanSetInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetinterface) function with the *OpCode* parameter set to **wlan_intf_opcode_current_operation_mode** and the *pData* parameter points to a ULONG that contains **DOT11_OPERATION_MODE_NETWORK_MONITOR**.
* A wireless connection is started in FIPS safe mode on the primary station adapter. FIPS safe mode is specified in the profile of the wireless connection. For more information, see the [FIPSMode Element](https://learn.microsoft.com/windows/win32/nativewifi/wlan-profileschema-authencryption-security-element#fipsmode).

Windows will stop the wireless Hosted Network on the software-based wireless access point (AP) adapter when an incompatible connection starts on the primary station adapter. The network state of the wireless Hosted Network state would become **wlan_hosted_network_unavailable**.

### `wlan_hosted_network_reason_incompatible_connection_stopped`

An incompatible connection stopped.

An incompatible connection previously started on the primary station adapter (wlan_hosted_network_reason_incompatible_connection_started), but the incompatible connection has stopped. If the wireless Hosted Network was previously stopped as a result of an incompatible connection being started, Windows will not automatically restart the wireless Hosted Network. Applications can restart the wireless Hosted Network on the AP adapter by calling the [WlanHostedNetworkStartUsing](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkstartusing) or [WlanHostedNetworkForceStart](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkforcestart) function.

### `wlan_hosted_network_reason_user_action`

A state change occurred that was caused by explicit user action.

### `wlan_hosted_network_reason_client_abort`

A state change occurred that was caused by client abort.

### `wlan_hosted_network_reason_ap_start_failed`

The driver for the wireless Hosted Network failed to start.

### `wlan_hosted_network_reason_peer_arrived`

A peer connected to the wireless Hosted Network.

### `wlan_hosted_network_reason_peer_departed`

A peer disconnected from the wireless Hosted Network.

### `wlan_hosted_network_reason_peer_timeout`

A peer timed out.

### `wlan_hosted_network_reason_gp_denied`

The operation was denied by group policy.

### `wlan_hosted_network_reason_service_unavailable`

The Wireless LAN service is not running.

### `wlan_hosted_network_reason_device_change`

The wireless adapter used by the wireless Hosted Network changed.

### `wlan_hosted_network_reason_properties_change`

The properties of the wireless Hosted Network changed.

### `wlan_hosted_network_reason_virtual_station_blocking_use`

A virtual station is active and blocking operation.

### `wlan_hosted_network_reason_service_available_on_virtual_station`

An identical service is available on a virtual station.

### `v1_enum`

## Remarks

The **WLAN_HOSTED_NETWORK_REASON** enumerated type is an extension to native wireless APIs added to support the wireless Hosted Network on Windows 7 and later.

The **WLAN_HOSTED_NETWORK_REASON** enumerates the possible reasons that a wireless Hosted Network function call failed or the reasons why a particular wireless Hosted Network notification was generated.

On Windows 7 and later, the operating system installs a virtual device if a Hosted Network capable wireless adapter is present on the machine. This virtual device normally shows up in the “Network Connections Folder” as ‘Wireless Network Connection 2’ with a Device Name of ‘Microsoft Virtual WiFi Miniport adapter’ if the computer has a single wireless network adapter. This virtual device is used exclusively for performing software access point (SoftAP) connections and is not present in the list returned by the [WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces) function. The lifetime of this virtual device is tied to the physical wireless adapter. If the physical wireless adapter is disabled, this virtual device will be removed as well.

## See also

[WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces)

[WlanHostedNetworkForceStart](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkforcestart)

[WlanHostedNetworkForceStop](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkforcestop)

[WlanHostedNetworkInitSettings](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkinitsettings)

[WlanHostedNetworkQuerySecondaryKey](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkquerysecondarykey)

[WlanHostedNetworkRefreshSecuritySettings](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkrefreshsecuritysettings)

[WlanHostedNetworkSetProperty](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworksetproperty)

[WlanHostedNetworkSetSecondaryKey](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworksetsecondarykey)

[WlanHostedNetworkStartUsing](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkstartusing)

[WlanHostedNetworkStopUsing](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkstopusing)