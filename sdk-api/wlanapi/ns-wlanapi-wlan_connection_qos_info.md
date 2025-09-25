## Description

Contains information about the QoS features outlined by the [WFA Wi-Fi QoS Management Specification](https://www.wi-fi.org/news-events/newsroom/wi-fi-alliance-improves-quality-of-service-for-real-time-wi-fi-applications) pertaining to the current connection.

## Members

### `peerCapabilities`

Type: **[WLAN_QOS_CAPABILITIES](https://learn.microsoft.com/windows/win32/api/wlanapi/ns-wlanapi-wlan_qos_capabilities)**

The QoS capabilities of the current peer.

### `bMSCSConfigured`

Type: **[BOOL](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Represents whether Mirrored Stream Classification Service (MSCS) is enabled on the current connection.

### `bDSCPToUPMappingConfigured`

Type: **[BOOL](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Represents whether Differentiated Service Code Point (DSCP) to User Priority (UP) mapping is enabled on the current connection.

### `ulNumConfiguredSCSStreams`

Type: **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Represents the number of Stream Classification Service (SCS) streams configured on the current connection.

### `ulNumConfiguredDSCPPolicies`

Type: **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Represents the number of DSCP Policies configured on the current connection.

## Remarks

## See also