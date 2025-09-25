# IStiDeviceControl::Release

## Description

The **IStiDeviceControl::Release** method closes the instance of the COM object that was created when a minidriver client called [IStiUSD::Initialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-initialize).

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *Stierr.h*.

## Remarks

The **IStiDeviceControl::Release** method should be called from within the destructor function of a user-mode still image minidriver's **IStiUSD** interface. (For more information, see [Creating a User-Mode Still Image Minidriver](https://learn.microsoft.com/windows-hardware/drivers/image/creating-a-user-mode-still-image-minidriver).)

A still image minidriver receives an **IStiDeviceControl** interface pointer as input to its [IStiUSD::Initialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-initialize) method.

## See also

[IStiDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)

[IStiDeviceControl::AddRef](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istidevicecontrol-addref)