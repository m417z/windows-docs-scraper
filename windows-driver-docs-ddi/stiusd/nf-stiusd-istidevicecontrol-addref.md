# IStiDeviceControl::AddRef

## Description

The **IStiDeviceControl::AddRef** method increments the reference count for the **IStiDeviceControl** interface.

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

The **IStiDeviceControl::AddRef** method should be called from within a user-mode still image minidriver's [IStiUSD::Initialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-initialize) method.

A still image minidriver receives an **IStiDeviceControl** interface pointer as an input argument to its [IStiUSD::Initialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-initialize) method.

## See also

[IStiDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)

[IStiDeviceControl::Release](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istidevicecontrol-release)