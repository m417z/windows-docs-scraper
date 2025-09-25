## Description

The **IWiaMiniDrv::drvGetWiaFormatInfo** method finds the image formats and media types that the WIA hardware device supports.

## Parameters

### `__MIDL__IWiaMiniDrv0059`

*lFlags* [in]

Reserved.

### `__MIDL__IWiaMiniDrv0060`

pWiasContext [in]

Pointer to a WIA item context.

### `__MIDL__IWiaMiniDrv0061`

*pcelt* [out]

Points to a memory location that will receive the number of items in the array pointed to by *ppwfi*.

### `__MIDL__IWiaMiniDrv0062`

*plDevErrVal* [out]

Points to a memory location that will receive a status code for this method. If this method returns S_OK, the value stored will be zero. Otherwise, a minidriver-specific error code will be stored at the location pointed to by this parameter.

### `__MIDL__IWiaMiniDrv0063`

*ppwfi* [out, optional]

Points to a memory location that will receive the address of the first element of an array of [WIA_FORMAT_INFO](https://learn.microsoft.com/windows/win32/api/wia_xp/ns-wia_xp-wia_format_info) structures.

## Return value

On success, the method should return **S_OK** and clear the device error value pointed to by *plDevErrVal*. If this method is called for items that do not contain any data, it should return **E_INVALIDARG**. If the method fails, it should return a standard COM error code and place a minidriver-specific error code value in the memory pointed to by *plDevErrVal*.

The value pointed to by *plDevErrVal* can be converted to a string by calling [IWiaMiniDrv::drvGetDeviceErrorStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetdeviceerrorstr).

## Remarks

This method creates an array of [WIA_FORMAT_INFO](https://learn.microsoft.com/windows/win32/api/wia_xp/ns-wia_xp-wia_format_info) structures that describe the media types and image formats that the WIA hardware device supports. For each element in the array, the media type can be one of **TYMED_CALLBACK**, **TYMED_MULTIPAGE_CALLBACK**, **TYMED_FILE**, or **TYMED_MULTIPAGE_FILE**. Typical values for the image format include WiaImgFmt_JPEG, and WiaImgFmt_BMP, among others. For more information, see [Understanding TYMED](https://learn.microsoft.com/windows-hardware/drivers/image/understanding-tymed) and [WIA_IPA_FILENAME_EXTENSION](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ipa-filename-extension).

The minidriver can define a global array to hold the **WIA_FORMAT_INFO** structures, or it can allocate memory for the array. The WIA service will not free the allocated memory, so the minidriver should store a pointer to that memory in the driver item context. The minidriver can then free this memory in a call to [IWiaMiniDrv::drvFreeDrvItemContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvfreedrvitemcontext).

## See also

[IWiaMiniDrv](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiaminidrv)

[IWiaMiniDrv::drvFreeDrvItemContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvfreedrvitemcontext)

[IWiaMiniDrv::drvGetDeviceErrorStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetdeviceerrorstr)