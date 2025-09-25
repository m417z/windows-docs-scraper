## Description

The **IWiaMiniDrv::drvInitializeWia** method initializes the minidriver and builds the driver item tree representing the device.

## Parameters

### `__MIDL__IWiaMiniDrv0000`

*bstrDeviceID* [in]

Specifies a string containing the device's unique identifier.

### `__MIDL__IWiaMiniDrv0001`

*bstrRootFullItemName* [in]

Specifies a string containing the full name of the root item.

### `__MIDL__IWiaMiniDrv0002`

*lFlags* [in]

Reserved. Set to zero.

### `__MIDL__IWiaMiniDrv0003`

*pIUnknownOuter* [in, optional]

(Optional) Points to a memory location that can receive the address of an **IUnknown** interface.

### `__MIDL__IWiaMiniDrv0004`

*pStiDevice* [in, optional]

Points to an [IStiDevice COM Interface](https://learn.microsoft.com/windows-hardware/drivers/image/istidevice-com-interface).

### `__MIDL__IWiaMiniDrv0005`

*pWiasContext* [in]

Pointer to a WIA item context.

### `__MIDL__IWiaMiniDrv0006`

*plDevErrVal* [out]

Points to a memory location that will receive a status code for this method. If this method returns **S_OK**, the value stored will be zero. Otherwise, a minidriver-specific error code will be stored at the location pointed to by this parameter.

### `__MIDL__IWiaMiniDrv0007`

*ppIDrvItemRoot* [out, optional]

Points to a memory location that will receive the address of a [IWiaDrvItem Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiadrvitem), the interface of the root item.

### `__MIDL__IWiaMiniDrv0008`

*ppIUnknownInner* [out, optional]

(Optional) Points to a memory location that can receive the address of an **IUnknown** interface. If the minidriver has functionality that is not accessible through the **IWiaMiniDrv** interface, the vendor can create a separate interface on the minidriver. This parameter provides access to that functionality.

## Return value

On success, the method should return **S_OK** and clear the device error value pointed to by *plDevErrVal*. If the method fails, it should return a standard COM error code and place a minidriver-specific error code value in the memory pointed to by *plDevErrVal*.

The value pointed to by *plDevErrVal* can be converted to a string by calling [IWiaMiniDrv::drvGetDeviceErrorStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetdeviceerrorstr).

## Remarks

This method should initialize any private structures and create the driver item tree. For detailed information about the steps that minidrivers typically perform in this method, see [Initializing the WIA Minidriver](https://learn.microsoft.com/windows-hardware/drivers/image/initializing-the-wia-minidriver) and [Creating the WIA Driver Item Tree](https://learn.microsoft.com/windows-hardware/drivers/image/creating-the-wia-driver-item-tree).

The WIA service calls the **IWiaMiniDrv::drvInitializeWia** method in response to a client's call to the [**CreateDevice**](https://learn.microsoft.com/windows/win32/api/wia_xp/nf-wia_xp-iwiadevmgr-createdevice) function, which means that this method is called once for each new client connection.

For example, if the user right-clicks a WIA scanner icon in **My Computer**, the shell calls **CreateDevice**, which generates a call to the minidriver's **IWiaMiniDrv::drvInitializeWia** method. If the user then runs the WIA **Acquisition Wizard**, it also calls **CreateDevice**. Each time that **CreateDevice** is called, there is a corresponding call to the **IWiaMiniDrv::drvInitializeWia** method on the minidriver.

## See also

[IWiaDrvItem::AddItemToFolder](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiadrvitem-additemtofolder)

[IWiaMiniDrv](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiaminidrv)

[IWiaMiniDrv::drvGetDeviceErrorStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetdeviceerrorstr)

[IWiaMiniDrv::drvUnInitializeWia](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvuninitializewia)

[wiasCreateDrvItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiascreatedrvitem)