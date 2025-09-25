# _NDIS_FILTER_DRIVER_CHARACTERISTICS structure

## Description

To specify its driver characteristics, a filter driver initializes an
NDIS_FILTER_DRIVER_CHARACTERISTICS structure and passes it to NDIS.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
filter driver characteristics structure (NDIS_FILTER_DRIVER_CHARACTERISTICS). Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_FILTER_DRIVER_CHARACTERISTICS.

To indicate the version of the NDIS_FILTER_DRIVER_CHARACTERISTICS structure, set the
**Revision** member to one of the following values:

#### NDIS_FILTER_CHARACTERISTICS_REVISION_3

Added the
**SynchronousOidRequestHandler** and **SynchronousOidRequestCompleteHandler** members for NDIS 6.80.

Set the
**Size** member to NDIS_SIZEOF_FILTER_DRIVER_CHARACTERISTICS_REVISION_3.

#### NDIS_FILTER_CHARACTERISTICS_REVISION_2

Added the
**DirectOidRequestHandler**,
**DirectOidRequestCompleteHandler**, and
**CancelDirectOidRequestHandler** members for NDIS 6.1.

Set the
**Size** member to NDIS_SIZEOF_FILTER_DRIVER_CHARACTERISTICS_REVISION_2.

#### NDIS_FILTER_CHARACTERISTICS_REVISION_1

Original version.

Set the
**Size** member to NDIS_SIZEOF_FILTER_DRIVER_CHARACTERISTICS_REVISION_1.

### `MajorNdisVersion`

The major version of NDIS that the driver is using. The current value is
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

Reserved for the major version number of the filter driver. Filter drivers can specify any value
that they require.

### `MinorDriverVersion`

Reserved for the minor version number of the filter driver. Filter drivers can specify any value
that they require.

### `Flags`

The following flag is supported in NDIS 6.89 and higher:

|Value|Meaning|
|--- |--- |
|NDIS_FILTER_DRIVER_UDP_RSC_NOT_SUPPORTED 0x00000008| The driver opt-outs of URO support. |

In NDIS 6.88 and below, **Flags** is reserved for NDIS.

### `FriendlyName`

A Unicode string that represents the user-readable description of the filter driver.

### `UniqueName`

A Unicode string that represents the unique name for the filter driver. This string must be a GUID, enclosed in curly braces, for example "{5cbf81bd-5055-47cd-9055-a76b2b4e3697}". This GUID must match the one in the **NetCfgInstanceId** INF file entry in the filter driver's INF file. For more information, see [INF File Settings for Filter Drivers](https://learn.microsoft.com/windows-hardware/drivers/network/inf-file-settings-for-filter-drivers).

### `ServiceName`

A Unicode string that represents the service name of the filter driver. This string must be the service name
from the AddService directive in the filter driver's INF file. For more information, see [INF File Settings for Filter Drivers](https://learn.microsoft.com/windows-hardware/drivers/network/inf-file-settings-for-filter-drivers).

### `SetOptionsHandler`

Specifies the entry point of the caller's
[FilterSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options) function.

### `SetFilterModuleOptionsHandler`

The entry point of the caller's
[FilterSetModuleOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_set_module_options) function.

### `AttachHandler`

The entry point of the caller's
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `DetachHandler`

The entry point of the caller's
[FilterDetach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_detach) function.

### `RestartHandler`

The entry point of the caller's
[FilterRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_restart) function.

### `PauseHandler`

The entry point of the caller's
[FilterPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_pause) function.

### `SendNetBufferListsHandler`

The entry point of the caller's
[FilterSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists) function. To bypass this function, set this member to **NULL**.

### `SendNetBufferListsCompleteHandler`

The entry point of the caller's
[FilterSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists_complete) function. To bypass this function, set this member to
**NULL**.

### `CancelSendNetBufferListsHandler`

The entry point of the caller's
[FilterCancelSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_cancel_send_net_buffer_lists) function. To bypass this function, set this member to **NULL**.

### `ReceiveNetBufferListsHandler`

The entry point of the caller's
[FilterReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_receive_net_buffer_lists) function. To bypass this function, set this member to **NULL**.

### `ReturnNetBufferListsHandler`

The entry point of the caller's
[FilterReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_return_net_buffer_lists) function. To bypass this function, set this member to **NULL**.

### `OidRequestHandler`

The entry point of the caller's
[FilterOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request) function. To bypass
this function, set this member to **NULL**.

### `OidRequestCompleteHandler`

The entry point of the caller's
[FilterOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request_complete) function. To bypass this function, set this member to **NULL**.

### `CancelOidRequestHandler`

The entry point of the caller's
[FilterCancelOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_cancel_oid_request) function. To bypass this function, set this member to **NULL**.

### `DevicePnPEventNotifyHandler`

The entry point of the caller's
[FilterDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_device_pnp_event_notify) function. To bypass this function, set this member to **NULL**.

### `NetPnPEventHandler`

The entry point of the caller's
[FilterNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_net_pnp_event) function. To
bypass this function, set this member to **NULL**.

### `StatusHandler`

The entry point of the caller's
[FilterStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_status) function. To bypass this
function, set this member to **NULL**.

### `DirectOidRequestHandler`

The entry point of the caller's
[FilterDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_direct_oid_request) function. To bypass this function, set this member to **NULL**.

### `DirectOidRequestCompleteHandler`

The entry point of the caller's
[FilterDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_direct_oid_request_complete) function. To bypass this function, set this member to **NULL**.

### `CancelDirectOidRequestHandler`

The entry point of the caller's
[FilterCancelDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_cancel_direct_oid_request) function. To bypass this function, set this member to **NULL**.

### `SynchronousOidRequestHandler`

The entry point of the caller's [*FilterSynchronousOidRequest*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-filter_synchronous_oid_request) function. To bypass this function, set this member to **NULL**.

### `SynchronousOidRequestCompleteHandler`

The entry point of the caller's [*FilterSynchronousOidRequestComplete*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-filter_synchronous_oid_request_complete) function. To bypass this function, set this member to **NULL**.

## Remarks

A filter driver calls the
[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver) function to register its characteristics, including the default entry
points for its filter driver functions (*FilterXxx*). The filter driver initializes an NDIS_FILTER_DRIVER_CHARACTERISTICS structure and
passes a pointer to this structure in the
*FilterCharacteristics* parameter of
**NdisFRegisterFilterDriver**.

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterCancelDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_cancel_direct_oid_request)

[FilterCancelOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_cancel_oid_request)

[FilterCancelSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_cancel_send_net_buffer_lists)

[FilterDetach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_detach)

[FilterDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_device_pnp_event_notify)

[FilterDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_direct_oid_request)

[FilterDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_direct_oid_request_complete)

[FilterNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_net_pnp_event)

[FilterOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request)

[FilterOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request_complete)

[FilterPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_pause)

[FilterReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_receive_net_buffer_lists)

[FilterRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_restart)

[FilterReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_return_net_buffer_lists)

[FilterSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists)

[FilterSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists_complete)

[FilterSetModuleOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_set_module_options)

[FilterSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options)

[FilterStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_status)

[INF File Settings for Filter Drivers](https://learn.microsoft.com/windows-hardware/drivers/network/inf-file-settings-for-filter-drivers)

[Initializing a Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/network/initializing-a-filter-driver)

[NDIS_FILTER_PARTIAL_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_partial_characteristics)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)