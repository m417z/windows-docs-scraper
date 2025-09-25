# IWiaItem::EnumDeviceCapabilities

## Description

The **IWiaItem::EnumDeviceCapabilities** method creates an enumerator that is used to ascertain the commands and events a Windows Image Acquisition (WIA) device supports.

## Parameters

### `lFlags` [in]

Type: **LONG**

Specifies a flag that selects the type of capabilities to enumerate. Can be set to one or more of the following values:

| Flag | Meaning |
| --- | --- |
| WIA_DEVICE_COMMANDS | Enumerate device commands. |
| WIA_DEVICE_EVENTS | Enumerate device events. |

### `ppIEnumWIA_DEV_CAPS` [out]

Type: **[IEnumWIA_DEV_CAPS](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwia_dev_caps)****

Pointer to [IEnumWIA_DEV_CAPS](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwia_dev_caps) interface created by **IWiaItem::EnumDeviceCapabilities**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Use this method to create an enumerator object to obtain the set of commands and events that a WIA device supports. You can use the *lFlags* parameter to specify which kinds of device capabilities to enumerate. The **IWiaItem::EnumDeviceCapabilities** method stores the address of the interface of the enumerator object in the *ppIEnumWIA_DEV_CAPS* parameter.

Applications must call the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on the interface pointers they receive through the *ppIEnumWIA_DEV_CAPS* parameter.