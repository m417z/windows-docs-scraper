# DXGKARG_COMMITVIDPN structure

## Description

The **DXGKARG_COMMITVIDPN** structure holds arguments for the [**DxgkDdiCommitVidPn**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_commitvidpn) function.

## Members

### `hFunctionalVidPn`

A handle to a functional VidPN object that is to be made active on the display adapter.

### `AffectedVidPnSourceId`

The constant D3DDDI_ID_ALL or the identifier of a particular video present source in the VidPN:

* If this member is a source identifier, **DxgkDdiCommitVidPn** updates only the modes of the video present paths that originate at that source. **DxgkDdiCommitVidPn** doesn't need to inspect paths that originate from other sources because those paths are the same in the new VidPN as they are in the currently active VidPN.
* If this member is equal to D3DDDI_ID_ALL, **DxgkDdiCommitVidPn** must inspect and update the entire VidPN as a single transaction; that is, the entire new VidPN must be made active or the entire current VidPN must remain active.

### `MonitorConnectivityChecks`

A [**D3DKMDT_MONITOR_CONNECTIVITY_CHECKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_monitor_connectivity_checks) enumerator (**D3DKMDT_MCC_IGNORE** or **D3DKMDT_MCC_ENFORCE**) that specifies whether to verify that video outputs in the new topology have monitors connected:

* If this member is equal to **D3DKMDT_MCC_ENFORCE** and one of the video outputs in the new VidPN's topology doesn't have a monitor connected, **DxgkDdiCommitVidPn** must leave the currently active VidPN in place and return STATUS_GRAPHICS_INVALID_VIDPN_TOPOLOGY.
* If this member is equal to **D3DKMDT_MCC_IGNORE**, **DxgkDdiCommitVidPn** can make the new VidPN active without checking to see whether any video outputs have monitors connected.

### `hPrimaryAllocation`

A handle to the primary allocation associated with the video present source identified by **AffectedVidPnSourceId**.

### `Flags` [in]

A [**DXGKARG_COMMITVIDPN_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_commitvidpn_flags) structure that identifies details about a call to the [**DxgkDdiCommitVidPn**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_commitvidpn) function.

## Remarks

The D3DDDI_ID_ALL constant is defined in *D3dukmddi.h*.

## See also

[**D3DKMDT_MONITOR_CONNECTIVITY_CHECKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_monitor_connectivity_checks)

[**DxgkDdiCommitVidPn**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_commitvidpn)