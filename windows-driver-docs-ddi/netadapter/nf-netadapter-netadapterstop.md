# NetAdapterStop function

## Description

The **NetAdapterStop** function stops a NETADAPTER object.

## Parameters

### `Adapter` [_In_]

The **NETADAPTER** object created by a prior call to [NetAdapterCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

## Remarks

If the **NETADAPTER** object is already stopped, this function does nothing.

The system will bugcheck if supplied an invalid handle, such as if the **NETADAPTER** object has not been initialized and created yet.

## See also

[NetAdapterCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate)

[NetAdapterStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart)