# _D3DKMDT_MONITOR_CONNECTIVITY_CHECKS enumeration

## Description

The D3DKMDT_MONITOR_CONNECTIVITY_CHECKS enumerated type indicates whether the [DxgkDdiCommitVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_commitvidpn) function should verify that certain video outputs have connected monitors.

## Constants

### `D3DKMDT_MCC_UNINITIALIZED`

Indicates that a variable of type D3DKMDT_MONITOR_CONNECTIVITY_CHECKS has not yet been assigned a meaningful value.

### `D3DKMDT_MCC_IGNORE`

Indicates that **DxgkDdiCommitVidPn** does not need to verify that monitors are connected.

### `D3DKMDT_MCC_ENFORCE`

Indicates that **DxgkDdiCommitVidPn** must verify that monitors are connected.

## Remarks

The **MonitorConnectivityChecks** member of the [DXGKARG_COMMITVIDPN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_commitvidpn) structure is a D3DKMDT_MONITOR_CONNECTIVITY_CHECKS value.

## See also

[DxgkDdiCommitVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_commitvidpn)