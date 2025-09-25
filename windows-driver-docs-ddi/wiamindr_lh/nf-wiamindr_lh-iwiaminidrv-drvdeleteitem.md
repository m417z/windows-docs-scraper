## Description

The **IWiaMiniDrv::drvDeleteItem** method deletes the current driver item.

## Parameters

### `__MIDL__IWiaMiniDrv0053`

*lFlags* [in]

Reserved.

### `__MIDL__IWiaMiniDrv0054`

*pWiasContext* [in]

Pointer to a WIA item context.

### `__MIDL__IWiaMiniDrv0055`

*plDevErrVal* [out]

Points to a memory location that will receive a status code for this method. If this method returns S_OK, the value stored will be zero. Otherwise, a minidriver-specific error code will be stored at the location pointed to by this parameter.

## Return value

On success, the method should return **S_OK** and clear the device error value pointed to by *plDevErrVal*. If the method fails, it should return a standard COM error code and place a minidriver-specific error code value in the memory pointed to by *plDevErrVal*. The value pointed to by *plDevErrVal* can be converted to a string by calling [IWiaMiniDrv::drvGetDeviceErrorStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetdeviceerrorstr).

## Remarks

In order to delete a driver item, the WIA service will call the minidriver method **IWiaMiniDrv::drvDeleteItem**. In this method, the minidriver will attempt to delete the item pointed to by the WIA service context parameter *pWiasContext*. If the item is successfully deleted, the method returns **S_OK** and sets the device error value parameter *plDevErrVal* to zero. If a device error occurs, the method returns **E_FAIL** and a device-specific error value in the device error value parameter *plDevErrVal*.

Before the WIA service calls this method, it verifies the following:

- The item is not the root item.

- If the item is a folder, it does not have any children.

- The item's access rights allow deletion.

Since the WIA service verifies these conditions, it is not necessary for the minidriver to also verify them.

## See also

[IWiaMiniDrv](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiaminidrv)

[IWiaMiniDrv::drvGetDeviceErrorStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetdeviceerrorstr)