## Description

The **PKTMON_CLIENT_DISPATCH** structure contains callback function pointers that the PktMonClnt application provides to handle monitoring events and state changes. This dispatch table defines the client's interface for responding to monitoring control operations.

## Members

### `Size`

The size of this structure in bytes, used for version validation and compatibility checking.

### `ClientEnable`

A pointer to a **[PKTMON_CLIENT_ENABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_client_enable)** callback function that enables or disables the entire client monitoring infrastructure.

### `CompEnable`

A pointer to a **[PKTMON_CLIENT_COMP_ENABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_client_comp_enable)** callback function that enables or disables monitoring for a specific component.

### `CompClose`

A pointer to a **[PKTMON_CLIENT_COMP_CLOSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_client_comp_close)** callback function that notifies the component to clean up when monitoring is disabled.

## Remarks

Clients must initialize this structure with their callback implementations and pass it during client registration to establish the monitoring infrastructure.

## See also

- [PKTMON_CLIENT_ENABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_client_enable)
- [PKTMON_CLIENT_COMP_ENABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_client_comp_enable)
- [PKTMON_CLIENT_COMP_CLOSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_client_comp_close)