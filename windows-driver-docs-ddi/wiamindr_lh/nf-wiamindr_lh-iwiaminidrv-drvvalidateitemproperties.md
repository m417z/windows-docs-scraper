## Description

The **IWiaMiniDrv::drvValidateItemProperties** method validates an item's properties against the set of valid values for each property and will update those properties if necessary.

## Parameters

### `__MIDL__IWiaMiniDrv0016`

*lFlags* [in]

Reserved. Set to zero.

### `__MIDL__IWiaMiniDrv0017`

*nPropSpec* [in]

Indicates the number of items n the *pPropSpec* array.

### `__MIDL__IWiaMiniDrv0018`

*pPropSpec* [in]

Points to the first element of an array of **PROPSPEC** structures.

### `__MIDL__IWiaMiniDrv0019`

*pWiasContext* [in]

Pointer to a WIA item context.

### `__MIDL__IWiaMiniDrv0020`

*plDevErrVal* [out]

Points to a memory location that will receive a status code for this method. If this method returns **S_OK**, the value stored will be zero. Otherwise, a minidriver-specific error code will be stored at the location pointed to by this parameter.

## Return value

On success, the method should return **S_OK** and clear the device error value pointed to by *plDevErrVal*. If the method fails, it should return a standard COM error code and place a minidriver-specific error code value in the memory pointed to by *plDevErrVal*.

The value pointed to by *plDevErrVal* can be converted to a string by calling [IWiaMiniDrv::drvGetDeviceErrorStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetdeviceerrorstr).

## See also

[IWiaMiniDrv](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiaminidrv)

[IWiaMiniDrv::drvGetDeviceErrorStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetdeviceerrorstr)

[wiasGetItemType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasgetitemtype)

[wiasValidateItemProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasvalidateitemproperties)