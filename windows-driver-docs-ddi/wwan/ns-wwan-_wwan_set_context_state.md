# _WWAN_SET_CONTEXT_STATE structure

## Description

The WWAN_SET_CONTEXT_STATE structure represents the command to set the Packet Data Protocol (PDP)
context state of the MB device.

## Members

### `ConnectionId`

MB Service specifies this member to uniquely identify the PDP Context and its corresponding state.

The MB Service uses the value in this member to uniquely identify the current active context across
MB network adapters.

The miniport driver must use the value in this member when completing
*set* requests. The MB Service uses the value in this member in subsequent
*query* requests as well as disconnect requests to the miniport driver.

### `ActivationCommand`

Activate or deactivate a PDP context that is referenced in the
**ConnectionId** member. The following table shows the possible values a miniport driver can specify.

| Value | Meaning |
| --- | --- |
| WwanActivationCommandActivate | Activate PDP context referred to by **ConnectionId** . |
| WwanActivationCommandDeactivate | Deactivate a currently activated PDP context referred by **ConnectionId** . |

### `AccessString`

A NULL-terminated string to access the network. For GSM-based networks, this would be an Access
Point Name (APN) string such as "data.thephone-company.com". For CDMA-based networks, this might be a
special dial code such as "#777" or a Network Access Identifier (NAI) such as
"foo@thephone-company.com". This member can be **NULL**.

The size of the string should not exceed 100 bytes.

### `UserName`

A NULL-terminated string that represents the username to authenticate. This member can be
**NULL**.

### `Password`

A NULL-terminated string that represents the username's password. This member can be **NULL**.

### `Compression`

A value from the WWAN_COMPRESSION enumeration that specifies whether compression should be used in
the data connection for header and data. This member applies only to GSM-based devices. The MB Service
sets this member to
**WwanCompressionNone** for CDMA-based devices.

| Value | Meaning |
| --- | --- |
| WwanCompressionNone | No compression is applied. |
| WwanCompressionEnable | Enable header and data compression. |

### `AuthType`

A value from the WWAN_AUTH_PROTOCOL enumeration that specifies the authentication type to use for
the PDP activation. This member applies only to GSM-based devices. The MB Service sets this member to
**WwanAuthProtocolNone** for CDMA-based devices.

| Value | Meaning |
| --- | --- |
| WwanAuthProtocolNone | No authentication protocol. |
| WwanAuthProtocolPap | Unencrypted password authentication. |
| WwanAuthProtocolChap | Use the Challenge Handshake Authentication Protocol (CHAP). |
| WwanAuthProtocolMsChapV2 | Use the Microsoft Challenge Handshake Authentication Protocol (CHAP) v2.0. |

### `IPType`

A value from the WWAN_IP_TYPE enumeration that specifies the type of IP.

### `MediaPreference`

### `ConnectionMediaSource`

### `ActivationOption`

A value from the [**WWAN_ACTIVATION_OPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-wwan_activation_option) enumeration that represents the Packet Data Protocol (PDP) activation options that the MB device supports.

### `Snssai`

A [**WWAN_SINGLE_NSSAI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_single_nssai) structure representing a single Network Slice Selection Assistance Information (NSSAI).

### `TrafficParameters`

A [**WWAN_OFFSET_SIZE_ELEMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_offset_size_element) structure. The first 4 bytes are the offset to the DataBuffer containing the raw data of MBIM_TLV_TYPE_TRAFFIC_PARAMETERS data field, in bytes, calculated from the beginning of WWAN_SET_CONTEXT_STATE.
The second 4 bytes are size of the raw data of MBIM_TLV_TYPE_TRAFFIC_PARAMETERS data field, in bytes.

## See also

[NDIS_WWAN_SET_CONTEXT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_set_context_state)

[WWAN_ACTIVATION_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_activation_command)

[WWAN_AUTH_PROTOCOL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_auth_protocol)

[WWAN_COMPRESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_compression)