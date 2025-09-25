# IoSizeOfIrp macro (wdm.h)

## Description

The **IoSizeOfIrp** routine determines the size in bytes for an IRP, given the number of stack locations in the IRP.

## Parameters

### `StackSize` [in]

Specifies the number of stack locations for the IRP.

## Remarks

**IoSizeOfIrp** returns the size, in bytes, of the IRP.

The input *StackSize* value is either that of the next-lower driver's device object or one more than that value.

## See also

[IoAllocateIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirp)

[IoMakeAssociatedIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iomakeassociatedirp)