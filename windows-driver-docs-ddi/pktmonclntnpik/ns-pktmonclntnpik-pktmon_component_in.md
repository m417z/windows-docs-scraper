## Description

The **PKTMON_COMPONENT_IN** structure contains information about a monitoring component being registered with the Packet Monitor infrastructure. This structure is passed to the **[PKTMON_PROVIDER_REGISTER_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_provider_register_component)** callback during component registration.

## Members

### `Header`

A [PKTMON_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ns-pktmonnpik-pktmon_header) structure used for versioning and size validation.

### `CompContext`

A pointer to component-specific context data that will be passed back to the component in subsequent callback invocations. This allows components to maintain state information.

### `Name`

A Unicode string containing the name of the component. This name is used for identification and diagnostic purposes.

### `Description`

A Unicode string containing a human-readable description of the component's purpose and functionality.

### `Type`

A **[PKTMON_COMPONENT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmondefk/ne-pktmondefk-pktmon_component_type)** enumeration value that specifies the type of the component (e.g., network adapter, filter, protocol).

### `DirTagIn`

A Unicode string tag for inbound packet direction. This tag appears in packet logs to identify packets entering the component.

### `DirTagOut`

A Unicode string tag for outbound packet direction. This tag appears in packet logs to identify packets leaving the component.

## Remarks

Components must populate this structure when calling [PKTMON_PROVIDER_REGISTER_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_provider_register_component) to register with the monitoring infrastructure.

## See also

- [PKTMON_PROVIDER_REGISTER_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_provider_register_component)
- [PKTMON_COMPONENT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmondefk/ne-pktmondefk-pktmon_component_type)
- [PktMonClntComponentRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntcomponentregister)