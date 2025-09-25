# IWiaItem::DeviceCommand

## Description

The **IWiaItem::DeviceCommand** issues a command to a Windows Image Acquisition (WIA) hardware device.

## Parameters

### `lFlags` [in]

Type: **LONG**

Currently unused. Should be set to zero.

### `pCmdGUID` [in]

Type: **const GUID***

Specifies a unique identifier that specifies the command to send to the WIA hardware device. For a list of valid device commands, see [WIA Device Commands](https://learn.microsoft.com/windows/desktop/wia/-wia-wia-device-commands).

### `pIWiaItem` [in, out]

Type: **[IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem)****

On output, this pointer points to the item created by the command, if any.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Applications use this method to send WIA commands to hardware devices.

When the application sends the WIA_CMD_TAKE_PICTURE command to the device, **IWiaItem::DeviceCommand**, the WIA run-time system creates the [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) object to represent the image. The **IWiaItem::DeviceCommand** method stores the address of the interface in the *pIWiaItem* parameter.

Applications must call the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on the interface pointers they receive through the *pIWiaItem* parameter.