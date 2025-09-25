## Description

The **IWiaMiniDrv::drvInitItemProperties** method initializes WIA driver item properties for each item in an application item tree.

## Parameters

### `__MIDL__IWiaMiniDrv0013`

*lFlags* [in]

Reserved. Set to zero.

### `__MIDL__IWiaMiniDrv0014`

*pWiasContext* [in]

Pointer to a WIA item context.

### `__MIDL__IWiaMiniDrv0015`

*plDevErrVal* [out]

Points to a memory location that will receive a status code for this method. If this method returns **S_OK**, the value stored will be zero. Otherwise, a minidriver-specific error code will be stored at the location pointed to by this parameter.

## Return value

On success, the method should return **S_OK** and clear the device error value pointed to by *plDevErrVal*. If the method fails, it should return a standard COM error code and place a minidriver-specific error code value in the memory pointed to by *plDevErrVal*.

The value pointed to by *plDevErrVal* can be converted to a string by calling [IWiaMiniDrv::drvGetDeviceErrorStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetdeviceerrorstr).

## Remarks

The **IWiaMiniDrv::drvInitItemProperties** method is called once per application for each item in the item tree.

## See also

[IWiaMiniDrv](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiaminidrv)

[IWiaMiniDrv::drvGetDeviceErrorStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetdeviceerrorstr)

[wiasGetDrvItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasgetdrvitem)

[wiasSetItemPropAttribs](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiassetitempropattribs)

[wiasSetItemPropNames](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiassetitempropnames)

[wiasWriteMultiple](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiaswritemultiple)