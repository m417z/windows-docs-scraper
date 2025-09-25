# _INDICATION_PARAMETERS_ENHANCED structure

## Description

The INDICATION_PARAMETERS_ENHANCED structure is passed as the Parameters parameter to a profile driver's [enhanced L2CAP Callback Function](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbthport_indication_callback_enhanced)

## Members

### `ConnectionHandle`

The L2CAP connection handle to the remote device. This handle is only valid for notifications that arrive over an established L2CAP connection.

### `BtAddress`

The Bluetooth address of the remote device.

### `Parameters`

### `Parameters.Connect`

The structure that contains parameters for the *IndicationRemoteConnect* callback function.

### `Parameters.Connect.Request`

The structure that contains the parameters for a connection request.

### `Parameters.Connect.Request.PSM`

The Protocol/Service Multiplexer (PSM) that is passed to the calling function when the *IndicationRemoteConnect* INDICATION_CODE value is specified in the enhanced callback function's *Indication* parameter.

### `Parameters.ConfigRequest`

The structure that contains parameters for the *IndicationRemoteConfigRequest* INDICATION_CODE value.

### `Parameters.ConfigRequest.CurrentParams`

A [CHANNEL_CONFIG_PARAMETERS_ENHANCED](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_channel_config_parameters_enhanced) structure that contains the parameters for the current channel. This value is only valid if the channel was previously open and is now in the process of being configured. This member is used when the callback function specifies the *IndicationRemoteConfigRequest* INDICATION_CODE value.

### `Parameters.ConfigRequest.RequestedParams`

A CHANNEL_CONFIG_PARAMETERS_ENHANCED structure that contains the parameters that are passed from the remote host for configuration requests. This member is used when the callback function specifies the *IndicationRemoteConfigRequest* INDICATION_CODE value.

### `Parameters.ConfigRequest.ResponseParams`

A CHANNEL_CONFIG_PARAMETERS_ENHANCED structure that contains the parameters that the profile driver responds to the configuration request with.

### `Parameters.ConfigRequest.Response`

A flag that indicates the status of the configuration request. Valid flag values are listed in the following table.

| Flag | Description |
| --- | --- |
| CONFIG_STATUS_SUCCESS | The configuration request was successful. |
| CONFIG_STATUS_DISCONNECT | The configuration request failed because the enhanced L2CAP connection was disconnected. |
| CONFIG_STATUS_INVALID_PARAMETER | The configuration request failed because an invalid parameter was passed to the profile driver. |
| CONFIG_STATUS_REJECT | The profile driver rejected the configuration request. |
| CONFIG_STATUS_UNKNOWN_OPTION | The configuration request failed because one of the specified configuration options was not recognized by the profile driver. |

### `Parameters.ConfigResponse`

The structure that contains parameters for the *IndicationRemoteConfigResponse* INDICATION_CODE value.

### `Parameters.ConfigResponse.CurrentParams`

A [CHANNEL_CONFIG_PARAMETERS_ENHANCED](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_channel_config_parameters_enhanced) structure that contains the parameters for the current channel.

This value is only valid if the channel was previously open and is now in the process of being configured. This member is used when the callback function specifies the *IndicationRemoteConfigRequest* INDICATION_CODE value.

### `Parameters.ConfigResponse.RequestedParams`

A CHANNEL_CONFIG_PARAMETERS_ENHANCED structure that contains the parameters that are passed from the remote host for configuration requests. This member is used when the callback function specifies the *IndicationRemoteConfigRequest* INDICATION_CODE value.

### `Parameters.ConfigResponse.RejectedParams`

A CHANNEL_CONFIG_PARAMETERS_ENHANCED structure that contains the configuration parameter settings that were rejected by the remote device.

### `Parameters.ConfigResponse.UnknownTypes`

An array of types that were not recognized by the responding device.

### `Parameters.ConfigResponse.NumUnknownTypes`

The number of unrecognized types in the **UnknownTypes** member.

### `Parameters.ConfigResponse.NewRequestParams`

A CHANNEL_CONFIG_PARAMETERS_ENHANCED structure that contains the parameter settings for the enhanced callback function to resubmit after the response has returned from the remote device.

### `Parameters.ConfigResponse.Response`

A flag that indicates the status of the configuration request. Valid flag values are listed in the following table:

| Flag | Description |
| --- | --- |
| CONFIG_STATUS_SUCCESS |The configuration request was successful. |
| CONFIG_STATUS_DISCONNECT | The configuration request failed because the enhanced L2CAP connection was disconnected. |
| CONFIG_STATUS_INVALID_PARAMETER |The configuration request failed because an invalid parameter was passed to the profile driver. |
| CONFIG_STATUS_REJECT | The profile driver rejected the configuration request. |
| CONFIG_STATUS_UNKNOWN_OPTION | The configuration request failed because one of the specified configuration options was not recognized by the profile driver. |

### `Parameters.FreeExtraOptions`

The structure that contains parameters for the *IndicationFreeExtraOptions* INDICATION_CODE value.

### `Parameters.FreeExtraOptions.NumExtraOptions`

The number of extra options contained in the **ExtraOptions** member.

### `Parameters.FreeExtraOptions.ExtraOptions`

Extra options.

### `Parameters.Disconnect`

The structure that contains the parameters for the *IndicationRemoteDisconnect* INDICATION_CODE value.

### `Parameters.Disconnect.Reason`

An [L2CAP_DISCONNECT_REASON](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_l2cap_disconnect_reason) value that indicates why the L2CAP connection to the remote device was terminated.

### `Parameters.Disconnect.CloseNow`

A Boolean value that a profile driver uses to notify the Bluetooth driver stack to close the L2CAP connection. Set this member to **TRUE** to notify the Bluetooth driver stack to close the connection. Otherwise, set it to **FALSE** to keep the connection open.

### `Parameters.RecvPacket`

The structure that contains the parameters for the *IndicationRecvPacket* INDICATION_CODE value.

### `Parameters.RecvPacket.PacketLength`

The size, in bytes, of the packet that the callback function sent over the L2CAP connection.

### `Parameters.RecvPacket.TotalQueueLength`

The number of packets to be processed over the L2CAP connection.

### `Parameters.Reserved`

Reserved member. Do not use.