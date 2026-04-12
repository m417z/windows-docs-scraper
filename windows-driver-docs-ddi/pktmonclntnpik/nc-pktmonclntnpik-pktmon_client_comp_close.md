## Description

The **PKTMON_CLIENT_COMP_CLOSE** callback function is invoked by the PktMonClnt provider to notify a component that monitoring has been disabled and the component should clean up its resources. This callback is called when a monitoring session ends or when the component is being shut down.

## Parameters

### `CompContext`

A pointer to the component-specific context that was provided during component registration. This context allows the component to identify which instance is being closed and perform appropriate cleanup.

## Remarks

This callback is part of the **[PKTMON_CLIENT_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_client_dispatch)** structure. Components should use this callback to release any resources allocated during monitoring, such as memory buffers or tracking structures.

## See also

- [PKTMON_CLIENT_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_client_dispatch)
- [PKTMON_CLIENT_COMP_ENABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_client_comp_enable)
- [PktMonClntComponentUnregister](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntcomponentunregister)