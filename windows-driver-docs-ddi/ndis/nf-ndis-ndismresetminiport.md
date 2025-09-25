# NdisMResetMiniport function

## Description

A miniport driver calls the **NdisMResetMiniport** function to trigger a later reset operation from NDIS.

## Parameters

### `MiniportAdapterHandle` [in]

The miniport adapter handle that NDIS passed to the *MiniportAdapterHandle* parameter of [MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize).

## Remarks

A miniport driver calls **NdisMResetMiniport** when it determines that the device requires a hardware reset.

As a result, NDIS schedules a work item for calling the miniport driver's [MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset) function asynchronously.

**NdisMResetMiniport** must be called at IRQL <= DISPATCH_LEVEL.