# IWiaDevMgr::EnumDeviceInfo

## Description

Applications use the **IWiaDevMgr::EnumDeviceInfo** method to enumerate property information for each available Windows Image Acquisition (WIA) device.

## Parameters

### `lFlag` [in]

Type: **LONG**

Specifies the types of WIA devices to enumerate. Should be set to WIA_DEVINFO_ENUM_LOCAL.

### `ppIEnum` [out, retval]

Type: **[IEnumWIA_DEV_INFO](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwia_dev_info)****

Receives the address of a pointer to the [IEnumWIA_DEV_INFO](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwia_dev_info) interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **IWiaDevMgr::EnumDeviceInfo** method creates an enumerator object, that supports the [IEnumWIA_DEV_INFO](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwia_dev_info) interface. **IWiaDevMgr::EnumDeviceInfo** stores a pointer to the **IEnumWIA_DEV_INFO** interface in the parameter *ppIEnum*. Applications can use the **IEnumWIA_DEV_INFO** interface pointer to enumerate the properties of each WIA device attached to the user's computer.

Applications must call the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on the interface pointers they receive through the *ppIEnum* parameter.