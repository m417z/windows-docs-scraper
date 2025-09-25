# NetConfigurationQueryLinkLayerAddress function

## Description

The **NetConfigurationQueryLinkLayerAddress** function retrieves the software-configurable link layer address that was stored in the registry for a NIC.

## Parameters

### `Configuration` [_In_]

Handle to a NETCONFIGURATION object that represents an opened registry key.

### `LinkLayerAddress` [_Out_]

A pointer to a NET_ADAPTER_LINK_LAYER_ADDRESS object that represents the link layer address stored in the registry key.

## Return value

The function returns STATUS_SUCCESS if the operation succeeds. Otherwise, this function may return an appropriate NTSTATUS error code.

## Remarks

The client driver obtains a handle to a NETCONFIGURATION object by calling [NetAdapterOpenConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapteropenconfiguration) or [NetConfigurationOpenSubConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/netconfiguration/nf-netconfiguration-netconfigurationopensubconfiguration).

## See also