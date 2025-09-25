# WDF_DPC_CONFIG_INIT function

## Description

[Applies to KMDF only]

The **WDF_DPC_CONFIG_INIT** function initializes a driver's [WDF_DPC_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/ns-wdfdpc-_wdf_dpc_config) structure.

## Parameters

### `Config` [out]

A pointer to a driver-allocated [WDF_DPC_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/ns-wdfdpc-_wdf_dpc_config) structure.

### `EvtDpcFunc` [in]

A pointer to a driver-supplied [EvtDpcFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nc-wdfdpc-evt_wdf_dpc) callback function.

## Remarks

The **WDF_DPC_CONFIG_INIT** function stores the specified [EvtDpcFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nc-wdfdpc-evt_wdf_dpc) pointer and sets the **AutomaticSerialization** member of the WDF_DPC_CONFIG structure to **TRUE**.

#### Examples

For a code example that uses the **WDF_DPC_CONFIG_INIT** function, see [WdfDpcCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdfdpccreate).

## See also

[EvtDpcFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nc-wdfdpc-evt_wdf_dpc)

[WDF_DPC_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/ns-wdfdpc-_wdf_dpc_config)