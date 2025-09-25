# PoStartNextPowerIrp function (wdm.h)

## Description

The **PoStartNextPowerIrp** routine signals the [power manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/power-manager) that the driver is ready to handle the next power [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp). (Windows Server 2003, Windows XP, and Windows 2000 only.)

## Parameters

### `Irp` [in, out]

A pointer to an IRP in which the major function code is [IRP_MJ_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-power).

## Remarks

Starting with Windows Vista, the driver is not required to call **PoStartNextPowerIrp** and a call to this routine does not perform a power management operation. However, on Windows Server 2003, Windows XP, and Windows 2000, **PoStartNextPowerIrp** must be called by every driver in a device stack after the driver is finished with the previous power IRP, if any, and is ready to handle the next power IRP. It must be called once by each driver for every [IRP_MN_QUERY_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-power) or [IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power) request.

Although power IRPs are completed only once, typically by the bus driver for a device, each driver in the device stack must call **PoStartNextPowerIrp** as the IRP travels down or back up the stack. Even if a driver fails the IRP, the driver must nevertheless call **PoStartNextPowerIrp** to signal the power manager that it is ready to handle another power IRP.

The driver must call **PoStartNextPowerIrp** while the current IRP stack location points to the current driver. Therefore, this routine must be called before [IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest), [IoSkipCurrentIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioskipcurrentirpstacklocation), and [PoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-pocalldriver). As a general rule, a driver should call **PoStartNextPowerIrp** from its *IoCompletion* routine associated with the IRP or from the callback routine it passed to [PoRequestPowerIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-porequestpowerirp).

Bus drivers must call **PoStartNextPowerIrp** before completing each IRP.

## See also

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[IRP_MJ_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-power)

[IRP_MN_QUERY_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-power)

[IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power)

[IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest)

[IoSkipCurrentIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioskipcurrentirpstacklocation)

[PoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-pocalldriver)

[PoRequestPowerIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-porequestpowerirp)