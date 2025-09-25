# NdisSetOptionalHandlers function

## Description

NDIS drivers can call the
**NdisSetOptionalHandlers** function to set or change the entry points of driver functions.

## Parameters

### `NdisHandle`

An NDIS handle that identifies a driver or driver instance.

For a protocol driver, this is the
*NdisDriverHandle* value passed to the
[ProtocolSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options) function or the
*NdisBindingHandle* value obtained by calling the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function.

For a miniport driver, this is the
*NdisDriverHandle* value passed to the
[MiniportSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options) function

For a filter driver, this is the
*NdisDriverHandle* value passed to the
[FilterSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options) function or the
*NdisFilterHandle* value passed to the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `OptionalHandlers`

A pointer to one of the following NDIS structures:

[NDIS_CLIENT_CHIMNEY_OFFLOAD_GENERIC_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_client_chimney_offload_generic_characteristics)

[NDIS_CLIENT_CHIMNEY_OFFLOAD_TCP_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_client_chimney_offload_tcp_characteristics)

[NDIS_CO_CALL_MANAGER_OPTIONAL_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_co_call_manager_optional_handlers)

[NDIS_CO_CLIENT_OPTIONAL_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_co_client_optional_handlers)

[NDIS_FILTER_PARTIAL_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_partial_characteristics)

[NDIS_MINIPORT_CO_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_co_characteristics)

[NDIS_MINIPORT_PNP_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_pnp_characteristics)

[NDIS_MINIPORT_SS_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_ss_characteristics)

[NDIS_NDK_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndisndk/ns-ndisndk-_ndis_ndk_provider_characteristics)

[NDIS_PROTOCOL_CO_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_protocol_co_characteristics)

[NDIS_PROVIDER_CHIMNEY_OFFLOAD_GENERIC_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_provider_chimney_offload_generic_characteristics)

[NDIS_PROVIDER_CHIMNEY_OFFLOAD_TCP_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_provider_chimney_offload_tcp_characteristics)

[NDIS_SHARED_MEMORY_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_shared_memory_provider_characteristics)

## Return value

**NdisSetOptionalHandlers** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | [NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) returns **NDIS_STATUS_SUCCESS** if it set the driver entry points. |
| **NDIS_STATUS_RESOURCES** | [NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) failed due to insufficient resources. |
| **NDIS_STATUS_NOT_SUPPORTED** | [NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) failed because the miniport driver did not specify that it supports NDIS 6.0 or later. A miniport driver specifies its NDIS version when it calls the [NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function. |
| **NDIS_STATUS_FAILURE** | [NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) returns **NDIS_STATUS_FAILURE** if none of the preceding values applies. |

## Remarks

An NDIS driver can call
**NdisSetOptionalHandlers** to overwrite its default entry points. The structure types passed at
*OptionalHandlers* vary according to the type of driver.

Protocol drivers can call
**NdisSetOptionalHandlers** in the context of the
[ProtocolSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options) function. As an option, protocol drivers can call
**NdisSetOptionalHandlers** from the
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function or
the
[ProtocolOpenAdapterCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_open_adapter_complete_ex) function after the protocol driver has a valid handle from the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function.

In this case, the valid structures are:

[NDIS_PROTOCOL_CO_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_protocol_co_characteristics)

[NDIS_CO_CLIENT_OPTIONAL_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_co_client_optional_handlers)

[NDIS_CO_CALL_MANAGER_OPTIONAL_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_co_call_manager_optional_handlers)

[NDIS_SHARED_MEMORY_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_shared_memory_provider_characteristics)

[NDIS_CLIENT_CHIMNEY_OFFLOAD_GENERIC_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_client_chimney_offload_generic_characteristics)

[NDIS_CLIENT_CHIMNEY_OFFLOAD_TCP_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_client_chimney_offload_tcp_characteristics)

For more information on the 2 chimney offload structures, see
[NDIS 6.0 TCP chimney offload
documentation](https://learn.microsoft.com/windows-hardware/drivers/network/full-tcp-offload).

Miniport drivers call
**NdisSetOptionalHandlers** in the context of the
[MiniportSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options) function.

In this case, the valid structures are:

[NDIS_MINIPORT_CO_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_co_characteristics)

[NDIS_MINIPORT_PNP_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_pnp_characteristics)

[NDIS_MINIPORT_SS_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_ss_characteristics)

[NDIS_NDK_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndisndk/ns-ndisndk-_ndis_ndk_provider_characteristics)

[NDIS_CO_CALL_MANAGER_OPTIONAL_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_co_call_manager_optional_handlers)

[NDIS_SHARED_MEMORY_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_shared_memory_provider_characteristics)

[NDIS_CLIENT_CHIMNEY_OFFLOAD_GENERIC_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_client_chimney_offload_generic_characteristics)

[NDIS_CLIENT_CHIMNEY_OFFLOAD_TCP_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_client_chimney_offload_tcp_characteristics)

For more information on the 2 chimney offload structures, see
[NDIS 6.0 TCP chimney offload
documentation](https://learn.microsoft.com/windows-hardware/drivers/network/full-tcp-offload).

Filter drivers call
**NdisSetOptionalHandlers** in the context of the
[FilterSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options) function.

There are no optional filter driver services in the current Windows version.

Filter drivers can call
**NdisSetOptionalHandlers** for a filter module. Filter drivers call
**NdisSetOptionalHandlers** in the context of the
[FilterSetModuleOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_set_module_options) function.

In this case, the valid structures are:

[NDIS_FILTER_PARTIAL_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_partial_characteristics)

[NDIS_CLIENT_CHIMNEY_OFFLOAD_GENERIC_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_client_chimney_offload_generic_characteristics)

[NDIS_CLIENT_CHIMNEY_OFFLOAD_TCP_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_client_chimney_offload_tcp_characteristics)

[NDIS_PROVIDER_CHIMNEY_OFFLOAD_GENERIC_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_provider_chimney_offload_generic_characteristics)

[NDIS_PROVIDER_CHIMNEY_OFFLOAD_TCP_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_provider_chimney_offload_tcp_characteristics)

For more information on the 4 chimney offload structures, see
[NDIS 6.0 TCP chimney offload
documentation](https://learn.microsoft.com/windows-hardware/drivers/network/full-tcp-offload).

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_restart)

[FilterSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options)

[MiniportSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options)

[NDIS_CO_CALL_MANAGER_OPTIONAL_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_co_call_manager_optional_handlers)

[NDIS_CO_CLIENT_OPTIONAL_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_co_client_optional_handlers)

[NDIS_FILTER_PARTIAL_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_partial_characteristics)

[NDIS_MINIPORT_CO_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_co_characteristics)

[NDIS_MINIPORT_PNP_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_pnp_characteristics)

[NDIS_PROTOCOL_CO_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_protocol_co_characteristics)

[NDIS_SHARED_MEMORY_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_shared_memory_provider_characteristics)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)

[ProtocolOpenAdapterCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_open_adapter_complete_ex)

[ProtocolSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options)