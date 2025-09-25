# IWiaDevMgr::SelectDeviceDlgID

## Description

The **IWiaDevMgr::SelectDeviceDlgID** method displays a dialog box that enables the user to select a hardware device for image acquisition.

## Parameters

### `hwndParent` [in]

Type: **HWND**

Handle of the window that owns the **Select Device** dialog box.

### `lDeviceType` [in]

Type: **LONG**

Specifies which type of WIA device to use. Can be set to **StiDeviceTypeDefault**, **StiDeviceTypeScanner**, or **StiDeviceTypeDigitalCamera**.

### `lFlags` [in]

Type: **LONG**

Specifies dialog box behavior. Can be set to any of the following values:

| Constant | Meaning |
| --- | --- |
| 0 | Use the default behavior. |
| WIA_SELECT_DEVICE_NODEFAULT | Display the dialog box even if there is only one matching device. For more information, see the **Remarks** section of this reference page. |

### `pbstrDeviceID` [out, retval]

Type: **BSTR***

Pointer to a string that receives the identifier string of the device.

## Return value

Type: **HRESULT**

This method returns the following values:

| Return Value | Meaning |
| --- | --- |
| S_OK | A device was successfully selected. |
| S_FALSE | The user canceled the dialog box. |
| WIA_S_NO_DEVICE_AVAILABLE | There are no WIA hardware devices attached to the user's computer that match the specifications. |

## Remarks

This method works in a similar manner to [IWiaDevMgr::SelectDeviceDlg](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiadevmgr-selectdevicedlg). The primary difference is that if it finds a matching device, it does not create the hierarchical tree of [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) objects for the device.

Like [IWiaDevMgr::SelectDeviceDlg](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiadevmgr-selectdevicedlg), the **IWiaDevMgr::SelectDeviceDlgID** method creates and displays the **Select Device** dialog box. This enables the user to select a WIA device for image acquisition. If a device is successfully selected, the **IWiaDevMgr::SelectDeviceDlgID** method passes its identifier string to the application through its *pbstrDeviceID* parameter.

Particular types of devices may be displayed to the user by specifying the device types through the *lDeviceType* parameter. If only one device meets the specification, **IWiaDevMgr::SelectDeviceDlgID** does not display the **Select Device** dialog box. Instead it passes the device's identifier string to the application without displaying the dialog box. You can override this behavior and force **IWiaDevMgr::SelectDeviceDlgID** to display the **Select Device** dialog box by passing WIA_SELECT_DEVICE_NODEFAULT as the value for the *lFlags* parameter.

If more than one WIA device matches the specification, all matching devices are displayed in the **Select Device** dialog box so the user may choose one.

It is recommended that applications make device and image selection available through a menu item named **From scanner or camera** on the **File** menu.