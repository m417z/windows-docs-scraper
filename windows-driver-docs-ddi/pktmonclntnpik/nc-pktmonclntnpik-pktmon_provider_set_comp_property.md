## Description

The **PKTMON_PROVIDER_SET_COMP_PROPERTY** callback function is invoked by the PktMonClnt application to set a property on a registered component. This callback allows dynamic configuration of component behavior through property updates.

## Parameters

### `ProviderBindingContext`

An opaque context pointer representing the provider binding. This context identifies the specific provider instance handling this operation.

### `CompHandle`

A handle to the component whose property is being set. This handle was returned from a previous **[PKTMON_PROVIDER_REGISTER_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_provider_register_component)** callback invocation.

### `Property`

A pointer to a **[PKTMON_COMP_PROPERTY_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_comp_property_in)** structure containing the property identifier, value, and size information.

## Return value

Returns `STATUS_SUCCESS` if the property is successfully set. Otherwise, returns an appropriate `NTSTATUS` error code indicating the failure reason.

## Remarks

This callback is part of the **[PKTMON_PROVIDER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_provider_dispatch)** structure and is invoked by the PktMonClnt application.

## See also

- [PKTMON_COMP_PROPERTY_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_comp_property_in)
- [PKTMON_PROVIDER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_provider_dispatch)
- [PktMonClntSetComponentProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntsetcomponentproperty)