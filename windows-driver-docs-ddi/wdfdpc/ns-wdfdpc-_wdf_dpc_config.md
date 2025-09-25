# _WDF_DPC_CONFIG structure

## Description

[Applies to KMDF only]

The **WDF_DPC_CONFIG** structure contains configuration information for a DPC object.

## Members

### `Size`

The size, in bytes, of this structure.

### `EvtDpcFunc`

A pointer to the driver's [EvtDpcFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nc-wdfdpc-evt_wdf_dpc) callback function.

### `AutomaticSerialization`

A Boolean value that, if **TRUE**, indicates that the framework will synchronize execution of the DPC object's [EvtDpcFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nc-wdfdpc-evt_wdf_dpc) callback function with callback functions from other objects that are underneath the DPC object's parent. For more information, see the following Remarks section.

## Remarks

The **WDF_DPC_CONFIG** structure is used as input to [WdfDpcCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdfdpccreate).

To initialize a **WDF_DPC_CONFIG** structure, your driver should first call [WDF_DPC_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdf_dpc_config_init) and then fill in structure members that **WDF_DPC_CONFIG_INIT** does not initialize.

Setting **AutomaticSerialization** to **TRUE** has no effect if the parent device object's [synchronization scope](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ne-wdfobject-_wdf_synchronization_scope) is set to **WdfSynchronizationScopeNone**.

Setting **AutomaticSerialization** to **TRUE** causes [WdfDpcCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdfdpccreate) to fail if the parent device object's [execution level](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ne-wdfobject-_wdf_execution_level) is set to **WdfExecutionLevelPassive**.

For more information about **AutomaticSerialization** and synchronizing driver callback functions, see [Synchronization Techniques for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/synchronization-techniques-for-wdf-drivers).

For more information about handling interrupts in framework-based drivers, see [Handling Hardware Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-hardware-interrupts).

## See also

[EvtDpcFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nc-wdfdpc-evt_wdf_dpc)

[KDPC](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[WDF_DPC_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdf_dpc_config_init)

[WdfDpcCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdfdpccreate)