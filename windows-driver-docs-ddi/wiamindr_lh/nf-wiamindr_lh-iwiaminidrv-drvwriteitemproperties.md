## Description

The **IWiaMiniDrv::drvWriteItemProperties** method writes driver item properties to a WIA hardware device.

## Parameters

### `__MIDL__IWiaMiniDrv0021`

*lFlags* [in]

Reserved.

### `__MIDL__IWiaMiniDrv0022`

*pWiasContext* [in]

Pointer to a WIA item context.

### `__MIDL__IWiaMiniDrv0023`

*plDevErrVal* [out]

Points to a memory location that will receive a status code for this method. If this method returns S_OK, the value stored will be zero. Otherwise, a minidriver-specific error code will be stored at the location pointed to by this parameter.

### `__MIDL__IWiaMiniDrv0024`

*pmdtc* [in]

Points to a [MINIDRV_TRANSFER_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_minidrv_transfer_context) structure containing the device transfer context.

## Return value

On success, the method should return S_OK and clear the device error value pointed to by *plDevErrVal*. If the method fails, it should return a standard COM error code and place a minidriver-specific error code value in the memory pointed to by *plDevErrVal*.

The value pointed to by *plDevErrVal* can be converted to a string by calling [IWiaMiniDrv::drvGetDeviceErrorStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetdeviceerrorstr).

## See also

[IWiaMiniDrv](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiaminidrv)

[IWiaMiniDrv::drvGetDeviceErrorStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetdeviceerrorstr)

[IWiaMiniDrv::drvReadItemProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvreaditemproperties)

[MINIDRV_TRANSFER_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_minidrv_transfer_context)

[wiasGetRootItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasgetrootitem)

[wiasReadMultiple](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasreadmultiple)

[wiasReadPropBin](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasreadpropbin)

[wiasReadPropFloat](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasreadpropfloat)

[wiasReadPropGuid](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasreadpropguid)

[wiasReadPropLong](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasreadproplong)

[wiasReadPropStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasreadpropstr)