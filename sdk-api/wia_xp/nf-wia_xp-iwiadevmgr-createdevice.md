# IWiaDevMgr::CreateDevice

## Description

The **IWiaDevMgr::CreateDevice** creates a hierarchical tree of [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) objects for a Windows Image Acquisition (WIA) device.

## Parameters

### `bstrDeviceID` [in]

Type: **BSTR**

Specifies the unique identifier of the WIA device.

### `ppWiaItemRoot` [out]

Type: **[IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem)****

Pointer to a pointer to the [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) interface of the root item in the hierarchical tree for the WIA device.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Applications use the **IWiaDevMgr::CreateDevice** method to create a device object for the WIA devices specified by the *bstrDeviceID* parameter.

When it returns, the **IWiaDevMgr::CreateDevice** method stores an address of a pointer in the parameter *ppWiaItemRoot*. The pointer points to the root item of the tree of [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) objects created by **IWiaDevMgr::CreateDevice**. Applications can use this tree of objects to control and retrieve data from the WIA device.

Note that applications must call the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on the pointers they receive through the *ppWiaItemRoot* parameter.