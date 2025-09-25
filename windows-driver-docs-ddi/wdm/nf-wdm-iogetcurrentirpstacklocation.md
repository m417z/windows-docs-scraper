# IoGetCurrentIrpStackLocation function

## Description

The **IoGetCurrentIrpStackLocation** routine returns a pointer to the caller's I/O stack location in the specified IRP.

## Parameters

### `Irp` [in]

A pointer to the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp).

## Return value

**IoGetCurrentIrpStackLocation** returns a pointer to an [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structure that contains the I/O stack location for the driver.

## Remarks

Every driver must call **IoGetCurrentIrpStackLocation** with each IRP it is sent in order to get any parameters for the current request. Unless a driver supplies a dispatch routine for each **IRP_MJ_*XXX*** code that the driver handles, the driver also must check its I/O stack location in the IRP to determine what operation is being requested.

If a driver is passing the same parameters that it received to the next-lower driver, it should call [IoCopyCurrentIrpStackLocationToNext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocopycurrentirpstacklocationtonext) or [IoSkipCurrentIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioskipcurrentirpstacklocation) instead of getting a pointer to the next-lower stack location and copying the parameters manually.

## See also

[IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver)

[IoGetNextIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetnextirpstacklocation)

[IoSetNextIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetnextirpstacklocation)