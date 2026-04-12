## Description

The **PKTMON_PROVIDER_UNREGISTER_COMPONENT** callback function is invoked by the PktMonClnt application to unregister a monitoring component and free its resources. This callback is called when a component is no longer needed for packet monitoring.

## Parameters

### `ProviderBindingContext`

An opaque context pointer representing the provider binding. This context identifies the specific provider instance handling this operation.

### `CompHandle`

A handle to the component being unregistered. This handle was returned from a previous **[PKTMON_PROVIDER_REGISTER_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_provider_register_component)** callback invocation.

## Remarks

This callback is part of the **[PKTMON_PROVIDER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_provider_dispatch)** structure and is invoked by the PktMonClnt application. The provider should release all resources associated with this component, including any edges that were added to it.

## See also

- [PKTMON_PROVIDER_REGISTER_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_provider_register_component)
- [PKTMON_PROVIDER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_provider_dispatch)
- [PktMonClntComponentUnregister](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntcomponentunregister)