## Description

The **IWiaMiniDrv::drvLockWiaDevice** method locks the WIA hardware device so that only the current minidriver can access it.

## Parameters

### `__MIDL__IWiaMiniDrv0030`

*lFlags* [in]

Reserved.

### `__MIDL__IWiaMiniDrv0031`

*pWiasContext* [in]

Pointer to a WIA item context.

### `__MIDL__IWiaMiniDrv0032`

*plDevErrVal* [out]

Points to a memory location that will receive a status code for this method. If this method returns *S_OK*, the value stored will be zero. Otherwise, a minidriver-specific error code will be stored at the location pointed to by this parameter.

## Return value

On success, the method should return **S_OK** and clear the device error value pointed to by *plDevErrVal*. If the method fails, it should return a standard COM error code and place a minidriver-specific error code value in the memory pointed to by *plDevErrVal*.

The value pointed to by *plDevErrVal* can be converted to a string by calling [IWiaMiniDrv::drvGetDeviceErrorStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetdeviceerrorstr).

## Remarks

The **IWiaMiniDrv::drvLockWiaDevice** method is used to lock access to the device. This is typically done before properties are written to the device or before a data transfer. The **IWiaMiniDrv::drvLockWiaDevice** method should be implemented using the **IStiDevice** interface's lock device method, [IStiDevice::LockDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-lockdevice).

## See also

[IWiaMiniDrv](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiaminidrv)

[IWiaMiniDrv::drvGetDeviceErrorStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetdeviceerrorstr)

[IWiaMiniDrv::drvUnLockWiaDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvunlockwiadevice)