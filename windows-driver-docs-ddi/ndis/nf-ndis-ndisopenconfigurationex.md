# NdisOpenConfigurationEx function

## Description

NDIS drivers call the
**NdisOpenConfigurationEx** function to get a configuration handle that allows access to configuration
parameters in the registry.

## Parameters

### `ConfigObject` [in]

A pointer to a caller-supplied and initialized
[NDIS_CONFIGURATION_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_configuration_object) structure.

### `ConfigurationHandle` [out]

A pointer to a caller-supplied variable in which
**NdisOpenConfigurationEx** returns a handle to a registry key. The registry key identifies the
configuration parameters.

## Return value

**NdisOpenConfigurationEx** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | **NdisOpenConfigurationEx** successfully opened the registry key where the driver's configuration parameters are stored. |
| **NDIS_STATUS_RESOURCES** | **NdisOpenConfigurationEx** failed due to insufficient resources. |
| **NDIS_STATUS_FAILURE** | **NdisOpenConfigurationEx** returns NDIS_STATUS_FAILURE if none of the preceding values applies. |

## Remarks

**NdisOpenConfigurationEx** returns a configuration handle at the
*ConfigurationHandle* parameter. The configuration handle is associated with a registry key that
identifies the location of the configuration parameters. The caller can pass the configuration handle to
other NDIS configuration functions to read or write information in the registry.

To access the configuration information, use the configuration handle with the following
functions:

[NdisReadConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadconfiguration)

[NdisWriteConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteconfiguration)

[NdisOpenConfigurationKeyByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenconfigurationkeybyname)

[NdisOpenConfigurationKeyByIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenconfigurationkeybyindex)

The type of registry data that is associated with the configuration handle depends on the type of
handle that the caller passes to
**NdisOpenConfigurationEx** in the
**NdisHandle** member of the
[NDIS_CONFIGURATION_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_configuration_object) structure that is referenced by the
*ConfigObject* parameter. The handle can identify parameters that are associated with the driver or
with an instance of the driver.

If the driver obtained the handle in
**NdisHandle** by calling the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function,
**NdisOpenConfigurationEx** provides a handle to the registry location where the miniport driver's
configuration parameters are stored. The miniport driver can use the configuration handle until it calls
the
[NdisMDeregisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismderegisterminiportdriver) function.

If the driver obtained the handle in
**NdisHandle** from the
*MiniportAdapterHandle* parameter of the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function,
**NdisOpenConfigurationEx** provides a handle to the registry location where a miniport adapter's
configuration parameters are stored. A miniport driver can pass the configuration handle to the
[NdisReadNetworkAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadnetworkaddress) function to
retrieve network address information that can be configured by software and administered locally.
Miniport drivers can use the configuration handle until NDIS halts the miniport adapter and the
[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) function returns.

If the driver obtained the handle in
**NdisHandle** by calling the
[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver) function,
**NdisOpenConfigurationEx** provides a handle to the registry location where the protocol driver's
configuration parameters are stored. The protocol driver can use the configuration handle until it calls
the
[NdisDeregisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisderegisterprotocoldriver) function.

If the handle in
**NdisHandle** is a pointer to an
[NDIS_BIND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_parameters) structure that
NDIS passed at the
*BindParameters* parameter of the
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function,
**NdisOpenConfigurationEx** provides a handle to the registry location where configuration parameters
for a protocol binding are stored. Protocol drivers can use the configuration handle until the bind
operation is complete.

If the driver obtained the handle in
**NdisHandle** by calling the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function,
**NdisOpenConfigurationEx** provides a handle to the registry location where the configuration
parameters for a protocol binding are stored. The protocol driver can use the configuration handle until
it calls the
[NdisCloseAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscloseadapterex) function.

If a filter driver obtained the handle in
**NdisHandle** by calling the
[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver) function,
**NdisOpenConfigurationEx** provides a handle to the registry location where the filter driver's
configuration parameters are stored. Filter drivers can use the configuration handle until they call the
[NdisFDeregisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfderegisterfilterdriver) function.

If a filter driver obtained the handle in
**NdisHandle** from the
*NdisFilterHandle* parameter of the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function,
**NdisOpenConfigurationEx** provides a handle to the registry location where a filter modules
configuration parameters are stored. The filter driver can use the configuration handle until NDIS
detaches the filter module and the
[FilterDetach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_detach) function returns. If a
monitoring filter driver specifies the NDIS_CONFIG_FLAG_FILTER_INSTANCE_CONFIGURATION flag in the
**Flags** member of the
[NDIS_CONFIGURATION_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_configuration_object) structure, the driver can access the filter module configuration for a
specific filter module when there are multiple filter modules configured over the same miniport adapter.
Modifying filter drivers must not use this flag.

After a driver is done accessing the configuration information, the driver must call the
[NdisCloseConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscloseconfiguration) function to
release the configuration handle and related resources.

**Note** To be sure that this function runs at IRQL = PASSIVE_LEVEL, a driver can schedule
an NDIS work item and call this and other configuration functions in the context of the work item
callback.

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterDetach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_detach)

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_BIND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_parameters)

[NDIS_CONFIGURATION_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_configuration_object)

[NdisCloseAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscloseadapterex)

[NdisCloseConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscloseconfiguration)

[NdisDeregisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisderegisterprotocoldriver)

[NdisFDeregisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfderegisterfilterdriver)

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)

[NdisMDeregisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismderegisterminiportdriver)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[NdisOpenConfigurationKeyByIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenconfigurationkeybyindex)

[NdisOpenConfigurationKeyByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenconfigurationkeybyname)

[NdisReadConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadconfiguration)

[NdisReadNetworkAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadnetworkaddress)

[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver)

[NdisWriteConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteconfiguration)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)