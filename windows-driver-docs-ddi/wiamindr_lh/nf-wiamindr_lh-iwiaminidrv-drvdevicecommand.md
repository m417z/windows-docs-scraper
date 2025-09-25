## Description

The **IWiaMiniDrv::drvDeviceCommand** method issues a command to a WIA device.

## Parameters

### `__MIDL__IWiaMiniDrv0043`

*lFlags* [in]

Reserved.

### `__MIDL__IWiaMiniDrv0044`

*pWiasContext* [in]

Pointer to a WIA item context.

### `__MIDL__IWiaMiniDrv0045`

*plCommand* [in]

Points to a WIA command GUID.

### `__MIDL__IWiaMiniDrv0046`

*plDevErrVal* [out]

Points to a memory location that will receive a status code for this method. If this method returns **S_OK**, the value stored will be zero. Otherwise, a minidriver-specific error code will be stored at the location pointed to by this parameter.

### `__MIDL__IWiaMiniDrv0047`

ppWiaDrvItem [out, optional]

Points to a memory location that can receive a pointer to an [IWiaDrvItem Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiadrvitem). See remarks below.

## Return value

On success, the method should return **S_OK** and clear the device error value pointed to by *plDevErrVal*. If the method fails, it should return a standard COM error code and place a minidriver-specific error code value in the memory pointed to by *plDevErrVal*.

The value pointed to by *plDevErrVal* can be converted to a string by calling [IWiaMiniDrv::drvGetDeviceErrorStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetdeviceerrorstr).

## Remarks

The method **IWiaMiniDrv::drvDeviceCommand** is called by the WIA service to issue a WIA service or application generated command to the device. The WIA service only calls the **IWiaMiniDrv::drvDeviceCommand** method for a command that the device can support in the method [IWiaMiniDrv::drvGetCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetcapabilities).

The *ppWiaDrvItem* parameter should be considered to be optional, since the minidriver does not normally set the memory location it points to. For certain commands, however, the minidriver places the address of a newly created item in the location pointed to by this parameter. For example, if the command to take a picture is issued (*plCommand* is set to WIA_CMD_TAKE_PICTURE), the device produces a new image, causing the minidriver to create a new item in the driver item tree, and sets **ppWiaDrvItem* to the address of the new item. This informs the WIA service that a new item was created.

The minidriver may include a list of custom commands the device can support in the method [IWiaMiniDrv::drvGetCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetcapabilities).

The WIA service does not write any properties before calling this method. If the command relies on property settings, the minidriver should call [IWiaMiniDrv::drvWriteItemProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvwriteitemproperties) before issuing the command. For example, the command to take a picture, **WIA_CMD_TAKE_PICTURE**, might rely on shutter speed and aperture settings, which need to be written to the device before the command is issued.

## See also

[IWiaMiniDrv](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiaminidrv)

[IWiaMiniDrv::drvGetCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetcapabilities)

[IWiaMiniDrv::drvWriteItemProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvwriteitemproperties)