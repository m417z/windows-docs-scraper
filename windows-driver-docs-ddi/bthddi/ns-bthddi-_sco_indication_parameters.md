# _SCO_INDICATION_PARAMETERS structure

## Description

The SCO_INDICATION_PARAMETERS structure describes indication parameters about a SCO connect or disconnect notification.

## Members

### `ConnectionHandle`

A connection handle to the remote device. This handle is only valid for notifications that arrive over an established SCO connection.

### `BtAddress`

The Bluetooth address of the remote device.

### `Parameters`

Union of the following fields.

### `Parameters.Connect`

The structure that contains parameters for the **ScoIndicationRemoteConnectSCO_INDICATION_CODE** event.

### `Parameters.Connect.Request`

The structure that contains the parameters for the SCO connection request.

### `Parameters.Connect.Request.LinkType`

A value from the [SCO\_LINK\_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_sco_link_type) enumeration that indicates the type of incoming connection.

### `Parameters.Disconnect`

The structure that contains parameters for the **ScoIndicationRemoteDisconnectSCO_INDICATION_CODE** event.

### `Parameters.Disconnect.Reason`

A [SCO\_DISCONNECT\_REASON](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_sco_disconnect_reason) value that indicates why the SCO connection was terminated.

### `Parameters.Disconnect.CloseNow`

A Boolean value that a profile driver can set to indicate whether the SCO connection to the remote device will be closed. If the connection is to be closed, the value is **TRUE**. Otherwise, the value is **FALSE**.

## Remarks

A profile driver's [SCO Callback Function](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnsco_indication_callback) should process a notification differently depending upon the value that the Bluetooth driver stack passes in the *Indication* parameter of the callback function.

When the Bluetooth driver stack passes **ScoIndicationRemoteConnect**, the callback function should use the **Connect** member of the **Parameters** union.

When the Bluetooth driver stack passes **ScoIndicationRemoteDisconnect**, the callback function should use the **Disconnect** member of the **Parameters** union.

## See also

[SCO Callback Function](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnsco_indication_callback)

[SCO\_DISCONNECT\_REASON](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_sco_disconnect_reason)