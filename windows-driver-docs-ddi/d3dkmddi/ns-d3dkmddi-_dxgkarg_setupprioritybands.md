# _DXGKARG_SETUPPRIORITYBANDS structure

## Description

Arguments used in a call to [DxgkddiSetupPriorityBands](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setupprioritybands).

## Members

### `gracePeriodForBand`

Grace period, in 100ns units when preempting another priority band for this priority band. This value is ignored for IDLE band, since it never preempts other bands. For realtime band this will be typically set to 0, because realtime processes need to use the GPU right away.

### `processQuantumForBand`

Default quantum in 100ns units for scheduling across processes within a priority band.

### `processGracePeriodForBand`

Default grace period in 100ns units for processes that preempt each other within a priority band.

### `targetNormalBandPercentage`

For normal priority band, specifies the target GPU percentage in situations when it's starved by the focus band. Valid values are between 0 and 50, with the default value on desktop systems being 10.

## See also

[DxgkddiSetupPriorityBands](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setupprioritybands)