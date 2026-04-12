## Description

The **PKTMON_CLIENT_ENABLE** callback function is invoked by the PktMonClnt provider to enable or disable the entire client monitoring infrastructure. This callback is called at a global level before individual components are enabled or disabled.

## Parameters

### `Enable`

A BOOLEAN value indicating whether to enable (TRUE) or disable (FALSE) packet monitoring for the client. When TRUE, the client should prepare for monitoring operations; when FALSE, the client should clean up monitoring resources.

## Remarks

This callback is part of the **[PKTMON_CLIENT_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_client_dispatch)** structure. It is invoked before component-specific enable callbacks to allow global initialization or cleanup.

## See also

- [PKTMON_CLIENT_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_client_dispatch)
- [PKTMON_CLIENT_COMP_ENABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_client_comp_enable)
- [PktMonClntInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntinitialize)