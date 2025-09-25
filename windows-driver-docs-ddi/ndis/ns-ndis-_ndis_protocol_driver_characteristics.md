# _NDIS_PROTOCOL_DRIVER_CHARACTERISTICS structure

## Description

To specify its driver characteristics, a protocol driver initializes an
**NDIS_PROTOCOL_DRIVER_CHARACTERISTICS** structure and passes it to NDIS.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
**NDIS_PROTOCOL_DRIVER_CHARACTERISTICS** structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_PROTOCOL_DRIVER_CHARACTERISTICS.

To indicate the version of the **NDIS_PROTOCOL_DRIVER_CHARACTERISTICS** structure, set the
**Revision** member to one of the following values:

#### NDIS_PROTOCOL_DRIVER_CHARACTERISTICS_REVISION_2

Added the
**DirectOidRequestCompleteHandler** member for NDIS 6.1.

Set the
**Size** member to
NDIS_SIZEOF_PROTOCOL_DRIVER_CHARACTERISTICS_REVISION_2.

#### NDIS_PROTOCOL_DRIVER_CHARACTERISTICS_REVISION_1

Original version for NDIS 6.0.

Set the
**Size** member to
NDIS_SIZEOF_PROTOCOL_DRIVER_CHARACTERISTICS_REVISION_1.

### `MajorNdisVersion`

The major version of the NDIS library the protocol driver is using. The current value is
0x06.

### `MinorNdisVersion`

The minor NDIS version. The following are the available minor version value settings.

|Value|Meaning|
|--- |--- |
|0|NDIS 6|
|20|NDIS 6.20|
|30|NDIS 6.30|
|40|NDIS 6.40|
|50|NDIS 6.50|
|51|NDIS 6.51|
|60|NDIS 6.60|
|70|NDIS 6.70|
|80|NDIS 6.80|
|81|NDIS 6.81|
|82|NDIS 6.82|
|83|NDIS 6.83|
|84|NDIS 6.84|
|85|NDIS 6.85|
|86|NDIS 6.86|
|87|NDIS 6.87|
|88|NDIS 6.88|
|89|NDIS 6.89|

### `MajorDriverVersion`

Reserved for the major version number of the protocol driver. Protocol drivers can specify any
value that they require.

### `MinorDriverVersion`

Reserved for the minor version number of the protocol driver. Protocol drivers can specify any
value that they require.

### `Flags`

The following flag is supported in NDIS 6.89 and higher:

|Value|Meaning|
|--- |--- |
|NDIS_PROTOCOL_DRIVER_UDP_RSC_NOT_SUPPORTED 0x00000008| The driver opt-outs of URO support. |

In NDIS 6.88 and below, **Flags** is reserved for NDIS. Protocol drivers should set this member to zero.

### `Name`

A Unicode string that is the service name of the protocol driver.

### `SetOptionsHandler`

The entry point for the
[ProtocolSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options) function.

### `BindAdapterHandlerEx`

The entry point for the
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function.

### `UnbindAdapterHandlerEx`

The entry point for the
[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex) function.

### `OpenAdapterCompleteHandlerEx`

The entry point for the
[ProtocolOpenAdapterCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_open_adapter_complete_ex) function.

### `CloseAdapterCompleteHandlerEx`

The entry point for the
[ProtocolCloseAdapterCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_close_adapter_complete_ex) function.

### `NetPnPEventHandler`

The entry point of the caller's
[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event) function.

### `UninstallHandler`

The entry point of the caller's
[ProtocolUninstall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_uninstall) function, if any,
or **NULL**.

### `OidRequestCompleteHandler`

The entry point of the caller's
[ProtocolOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_oid_request_complete) function.

### `StatusHandlerEx`

The entry point of the caller's
[ProtocolStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_status_ex) function, if any, or
**NULL**.

### `ReceiveNetBufferListsHandler`

The entry point for the
[ProtocolReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_receive_net_buffer_lists) function.

### `SendNetBufferListsCompleteHandler`

The entry point for the
[ProtocolSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_send_net_buffer_lists_complete) function.

### `DirectOidRequestCompleteHandler`

The entry point of the caller's
[ProtocolDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_direct_oid_request_complete) function. This is an optional function. Set this entry point to
**NULL** if the protocol driver does not support the direct OID request interface.

## Remarks

A protocol driver calls the
[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver) function to register its characteristics, including the default entry
points for its protocol driver functions (*ProtocolXxx*). The protocol driver initializes an **NDIS_PROTOCOL_DRIVER_CHARACTERISTICS** structure
and passes a pointer to this structure in the
*ProtocolCharacteristics* parameter of
**NdisRegisterProtocolDriver**.

## See also

[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)

[ProtocolCloseAdapterCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_close_adapter_complete_ex)

[ProtocolDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_direct_oid_request_complete)

[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event)

[ProtocolOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_oid_request_complete)

[ProtocolOpenAdapterCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_open_adapter_complete_ex)

[ProtocolReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_receive_net_buffer_lists)

[ProtocolSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_send_net_buffer_lists_complete)

[ProtocolSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options)

[ProtocolStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_status_ex)

[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex)

[ProtocolUninstall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_uninstall)