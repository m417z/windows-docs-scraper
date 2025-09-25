## Description

The **IWiaMiniDrv::drvUnLockWiaDevice** method unlocks the WIA hardware device so that any minidriver can access it.

## Parameters

### `__MIDL__IWiaMiniDrv0033`

*lFlags* [in]

Reserved.

### `__MIDL__IWiaMiniDrv0034`

*pWiasContext* [in]

Pointer to a WIA item context.

### `__MIDL__IWiaMiniDrv0035`

*plDevErrVal* [out]

Points to a memory location that will receive a status code for this method. If this method returns **S_OK**, the value stored will be zero. Otherwise, a minidriver-specific error code will be stored at the location pointed to by this parameter.

## Return value

On success, the method should return **S_OK** and clear the device error value pointed to by *plDevErrVal*. If the method fails, it should return a standard COM error code and place a minidriver-specific error code value in the memory pointed to by *plDevErrVal*.

The value pointed to by *plDevErrVal* can be converted to a string by calling [IWiaMiniDrv::drvGetDeviceErrorStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetdeviceerrorstr).

## Remarks

The method **IWiaMiniDrv::drvUnLockWiaDevice** is used to allow access to the device after the lock is no longer needed. It is typically called by the WIA service after properties are written to the device or after a data transfer.

The minidriver's implementation of the **IWiaMiniDrv::drvUnLockWiaDevice** method should use the STI unlock device method [IStiDevice::UnLockDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-unlockdevice).

## See also

[IWiaMiniDrv](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiaminidrv)

[IWiaMiniDrv::drvGetDeviceErrorStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetdeviceerrorstr)

[IWiaMiniDrv::drvLockWiaDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvlockwiadevice)