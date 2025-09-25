# IWiaItem::DeleteItem

## Description

The **IWiaItem::DeleteItem** method removes the current [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) object from the object tree of the device.

## Parameters

### `lFlags` [in]

Type: **LONG**

Currently unused. Should be set to zero.

## Return value

Type: **HRESULT**

This method returns S_OK regardless of how many items were deleted. If the method fails, it returns a standard COM error code.

## Remarks

The Windows Image Acquisition (WIA) run-time system represents each WIA hardware device connected to the user's computer as a hierarchical tree of [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) objects. A given WIA device may or may not allow applications to delete **IWiaItem** objects from its tree. Use the [IEnumWIA_DEV_CAPS](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwia_dev_caps) interface to query the device for item deletion capability.

If the device supports item deletion in its [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) tree, invoke the **IWiaItem::DeleteItem** method to remove the **IWiaItem** object. Note that this method will only delete an object after all references to the object have been released.