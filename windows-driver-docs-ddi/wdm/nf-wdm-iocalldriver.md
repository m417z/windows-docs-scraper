## Description

The **IoCallDriver** routine, wraps **IofCallDriver** that sends an IRP to the driver associated with a specified device object.

Do not call **IofCallDriver**. Call **IoCallDriver** instead. For more information, see [**IofCallDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofcalldriver).

## Parameters

### `a` [in]

See [**IofCallDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofcalldriver).

### `b` [in, out]

See [**IofCallDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofcalldriver).

## Syntax

```cpp
#define IoCallDriver(a,b)   \
        IofCallDriver(a,b)
);
```

## See also

See [**IofCallDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofcalldriver).

[IoAllocateIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirp)

[IoBuildAsynchronousFsdRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildasynchronousfsdrequest)

[IoBuildDeviceIoControlRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuilddeviceiocontrolrequest)

[IoBuildSynchronousFsdRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildsynchronousfsdrequest)

[IoSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutine)

[PoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-pocalldriver)