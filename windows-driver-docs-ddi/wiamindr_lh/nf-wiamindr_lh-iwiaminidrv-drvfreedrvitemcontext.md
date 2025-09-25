## Description

The **IWiaMiniDrv::drvFreeDrvItemContext** method frees a device-specific context.

## Parameters

### `__MIDL__IWiaMiniDrv0056`

*lFlags* [in]

Reserved.

### `__MIDL__IWiaMiniDrv0057`

*pSpecContext* [in]

Points to a device-specific context.

### `__MIDL__IWiaMiniDrv0058`

*plDevErrVal* [out]

Points to a memory location that will receive a status code for this method. If this method returns **S_OK**, the value stored will be zero. Otherwise, a minidriver-specific error code will be stored at the location pointed to by this parameter.

## Return value

On success, the method should return **S_OK** and clear the device error value pointed to by *plDevErrVal*. If the method fails, it should return a standard COM error code and place a minidriver-specific error code in the memory pointed to by *plDevErrVal*.

The value pointed to by *plDevErrVal* can be converted to a string by calling [IWiaMiniDrv::drvGetDeviceErrorStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetdeviceerrorstr).

## Remarks

When a driver item is deleted, the WIA service frees the driver item context. This method informs the minidriver that the context is ready to be freed. The minidriver should free any memory that it allocated for the context. For example, in [IWiaMiniDrv::drvReadItemProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvreaditemproperties), a camera minidriver might allocate a cache to store the thumbnail for an item, and store a pointer to this cache in the driver item context. The minidriver would then free the cache in this method.

## See also

 [IWiaMiniDrv](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiaminidrv)

 [IWiaMiniDrv::drvGetDeviceErrorStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetdeviceerrorstr)

 [IWiaMiniDrv::drvReadItemProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvreaditemproperties)