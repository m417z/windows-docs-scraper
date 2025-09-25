# _

## Description

The AV_61883_REQUEST structure is used to pass requests to the IEC-61883 protocol driver.

## Members

### `Function`

Determines the type of request. Each request type is documented under the value of **Function** in [IEC-61883 Protocol I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

### `Version`

The device driver interface (DDI) version for the request. The [INIT_61883_HEADER](https://learn.microsoft.com/previous-versions/ff537219(v=vs.85)) macro initializes **Version** to CURRENT_61883_DDI_VERSION.

### `Flags`

Flags specific to the request. For details, see the reference page for the request. Drivers must set this member to zero for requests that do not use flags.

### `GetUnitInfo`

A [GET_UNIT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_get_unit_info) structure, used if the **Function** member is [Av61883_GetUnitInfo](https://learn.microsoft.com/previous-versions/ff536983(v=vs.85)).

### `SetUnitInfo`

A [SET_UNIT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_set_unit_info) structure, used if the **Function** member is **Av61883_SetUnitInfo**.

### `GetPlugHandle`

A [CMP_GET_PLUG_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_cmp_get_plug_handle) structure, used if the **Function** member is **Av61883_GetPlugHandle**.

### `GetPlugState`

A [CMP_GET_PLUG_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_cmp_get_plug_state) structure, used if the **Function** member is [Av61883_GetPlugState](https://learn.microsoft.com/previous-versions/ff536980(v=vs.85)).

### `Connect`

A CMP_CONNECT structure, used if the **Function** member is **Av61883_Connect**.

### `Disconnect`

A [CMP_DISCONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_cmp_disconnect) structure, used if the **Function** member is **Av61883_Disconnect**.

### `AttachFrame`

A [CIP_ATTACH_FRAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_cip_attach_frame) structure, used if the **Function** member is **Av61883_AttachFrame**.

### `CancelFrame`

A [CIP_CANCEL_FRAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_cip_cancel_frame) structure, used if the **Function** member is **Av61883_CancelFrame**.

### `Talk`

A [CIP_TALK](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_cip_talk) structure, used if the **Function** member is **Av61883_Talk**.

### `Listen`

A [CIP_LISTEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_cip_listen) structure, used if the **Function** member is **Av61883_Listen**.

### `Stop`

A [CIP_STOP](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_cip_stop) structure, used if the **Function** member is **Av61883_Stop**.

### `Request`

An [FCP_SEND_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_fcp_send_request) structure, used if the **Function** member is **Av61883_SendFcpResponse**.

### `Response`

An [FCP_GET_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_fcp_get_response) structure, used if the **Function** member is **Av61883_GetFcpResponse**.

### `SendRequest`

An [FCP_SEND_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_fcp_send_request) structure, used if the **Function** member is **Av61883_SendFcpResponse**.

### `GetResponse`

An [FCP_GET_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_fcp_get_response) structure, used if the **Function** member is **Av61883_GetFcpResponse**.

### `GetRequest`

An [FCP_GET_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_fcp_get_request) structure, used if the **Function** member is **Av61883_GetFcpRequest**.

### `SendResponse`

An [FCP_SEND_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_fcp_send_response) structure, used if the **Function** member is **Av61883_SendFcpResponse**.

### `SetFcpNotify`

A [SET_FCP_NOTIFY](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_set_fcp_notify) structure, used if the **Function** member is **Av61883_SetFcpNotify**.

### `CreatePlug`

A [CMP_CREATE_PLUG](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_cmp_create_plug) structure, used if the **Function** member is **Av61883_CreatePlug**.

### `DeletePlug`

A [CMP_DELETE_PLUG](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_cmp_delete_plug) structure, used if the **Function** member is **Av61883_DeletePlug**.

### `SetPlug`

A [CMP_SET_PLUG](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_cmp_set_plug) structure, used if the **Function** member is **Av61883_SetPlug**.

### `BusResetNotify`

A [BUS_RESET_NOTIFY](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_bus_reset_notify) structure, used if the **Function** member is **Av61883_BusResetNotify**.

### `SetUnitDirectory`

A [SET_UNIT_DIRECTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_set_unit_directory) structure, used if the **Function** member is **Av61883_SetUnitDirectory**.

### `MonitorPlugs`

A [CMP_MONITOR_PLUGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_cmp_monitor_plugs) structure, used if the **Function** member is **Av61883_MonitorPlugs**.

## Remarks

The **Parameters->****Others.Arguments1** member of an [IOCTL_61883_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ni-61883-ioctl_61883_class) IRP points to an AV_61883_REQUEST structure. The IEC-61883 protocol driver uses the request structure to determine the type of request made by the client driver, and also to return the results of the operation. See [IEC-61883 Protocol I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/ddi/) for a description of the behavior of each request.

## See also

[INIT_61883_HEADER](https://learn.microsoft.com/previous-versions/ff537219(v=vs.85))

[IOCTL_61883_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ni-61883-ioctl_61883_class)