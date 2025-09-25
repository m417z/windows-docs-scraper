## Description

The **IWiaMiniDrv::drvGetCapabilities** method returns an array of events and commands that a device supports.

## Parameters

### `__MIDL__IWiaMiniDrv0048`

lFlags [in]

Specifies whether the array pointed to by *ppCapabilites* consists of commands, or events, or both. This parameter can be either of the following flags or of both of them combined by an OR operator.

| Flag | Description |
|--|--|
| WIA_DEVICE_COMMANDS | The array consists of device commands. |
| WIA_DEVICE_EVENTS | The array consists of device events. |

### `__MIDL__IWiaMiniDrv0049`

*pWiasContext* [in]

Pointer to a WIA item context.

### `__MIDL__IWiaMiniDrv0050`

*pcelt* [out]

Points to a memory location that will receive the number of elements in the array pointed to by the *ppCapabilities* parameter.

### `__MIDL__IWiaMiniDrv0051`

*plDevErrVal* [out]

Points to a memory location that will receive a status code for this method. If this method returns **S_OK**, the value stored will be zero. Otherwise, a minidriver-specific error code will be stored at the location pointed to by this parameter.

### `__MIDL__IWiaMiniDrv0052`

*ppCapabilities* [out, optional]

Points to a memory location that will receive the address of the first element of an array of [WIA_DEV_CAP_DRV](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_wia_dev_cap_drv) structures that contain the GUIDs of events and commands that the device supports.

## Return value

On success, the method should return **S_OK** and clear the device error value pointed to by *plDevErrVal*. If the method fails, it should return a standard COM error code and place a minidriver-specific error code value in the memory pointed to by *plDevErrVal*.

The value pointed to by *plDevErrVal* can be converted to a string by calling [IWiaMiniDrv::drvGetDeviceErrorStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetdeviceerrorstr).

## Remarks

The WIA service calls the minidriver method **IWiaMiniDrv::drvGetCapabilities** to obtain a list of hardware command capabilities and/or device events. In response to this call, a minidriver sets *ppCapabilities* with the address of an array of pointers to GUID data. Each GUID corresponds to an event notification or a device command supported by the imaging device. When the *lFlags* parameter is set to WIA_DEVICE_COMMANDS, the array of GUIDs contains device commands. When *lFlags* is set to WIA_DEVICE_EVENTS, the array of GUIDs contains events. If *lFlags* is set to WIA_DEVICE_COMMANDS | WIA_DEVICE_EVENTS, the array of GUIDs contains both events and commands, listed in that order.

The *Wiadef.h* header lists several predefined commands and events.

## See also

[IWiaMiniDrv](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiaminidrv)

[IWiaMiniDrv::drvGetDeviceErrorStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetdeviceerrorstr)

[WIA_DEV_CAP_DRV](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_wia_dev_cap_drv)