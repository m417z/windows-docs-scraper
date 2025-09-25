# IoGetNextIrpStackLocation function

## Description

The **IoGetNextIrpStackLocation** routine gives a higher level driver access to the next-lower driver's I/O stack location in an IRP so the caller can set it up for the lower driver.

## Parameters

### `Irp` [in]

A pointer to the IRP.

## Return value

**IoGetNextIrpStackLocation** returns a pointer to the next-lower-level driver's [I/O stack location](https://learn.microsoft.com/windows-hardware/drivers/kernel/i-o-stack-locations) in the given IRP.

## Remarks

Each driver that passes IRPs on to lower drivers must set up the stack location for the next lower driver. A driver calls **IoGetNextIrpStackLocation** to get a pointer to the next-lower driver's I/O stack location.

If a driver is passing the same parameters that it received to the next-lower driver, it should call [IoCopyCurrentIrpStackLocationToNext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocopycurrentirpstacklocationtonext) or [IoSkipCurrentIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioskipcurrentirpstacklocation) instead of getting a pointer to the next-lower stack location and copying the parameters manually.

The return value is a pointer to an [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structure. For more information, see [I/O Stack Locations](https://learn.microsoft.com/windows-hardware/drivers/kernel/i-o-stack-locations).

## See also

[IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)

[IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver)

[IoCopyCurrentIrpStackLocationToNext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocopycurrentirpstacklocationtonext)

[IoGetCurrentIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetcurrentirpstacklocation)

[IoSetNextIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetnextirpstacklocation)

[IoSkipCurrentIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioskipcurrentirpstacklocation)