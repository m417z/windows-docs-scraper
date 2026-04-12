## Description

The **PKTMON_CLIENT_COMP_ENABLE** callback function is invoked by the PktMonClnt provider to enable or disable packet monitoring for a specific component. This callback allows components to respond to monitoring state changes by starting or stopping packet capture operations.

## Parameters

### `Enable`

A pointer to a **[PKTMON_CLIENT_COMP_ENABLE_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_client_comp_enable_in)** structure that contains the component context and flags indicating whether flow logging and drop logging should be enabled or disabled.

## Remarks

This callback is part of the **[PKTMON_CLIENT_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_client_dispatch)** structure. Components can use the `FlowEnabled` and `DropEnabled` fields to determine what type of monitoring to perform.

## See also

- [PKTMON_CLIENT_COMP_ENABLE_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_client_comp_enable_in)
- [PKTMON_CLIENT_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_client_dispatch)
- [PKTMON_CLIENT_COMP_CLOSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_client_comp_close)