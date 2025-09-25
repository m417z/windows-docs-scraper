# IWiaDevMgr::SelectDeviceDlg

## Description

The **IWiaDevMgr::SelectDeviceDlg** displays a dialog box that enables the user to select a hardware device for image acquisition.

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

### `pbstrDeviceID` [in, out]

Type: **BSTR***

On output, receives a string which contains the device's identifier string. On input, pass the address of a pointer if this information is needed, or **NULL** if it is not needed.

### `ppItemRoot` [out, retval]

Type: **[IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem)****

Receives the address of a pointer to the [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) interface of the root item of the tree that represents the selected WIA device. If no devices are found, it contains the value **NULL**.

## Return value

Type: **HRESULT**

This method returns the following values:

| Return Value | Meaning |
| --- | --- |
| S_OK | A device was successfully selected. |
| S_FALSE | The user canceled the dialog box. |
| WIA_S_NO_DEVICE_AVAILABLE | There are no WIA hardware devices that match the specifications given in the *lDeviceType* parameter. |

## Remarks

This method creates and displays the **Select Device** dialog box so the user can select a WIA device for image acquisition. If a device is successfully selected, the **IWiaDevMgr::SelectDeviceDlg** method creates a hierarchical tree of [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) objects for the device. It stores a pointer to the **IWiaItem** interface of the root item in the parameter *ppItemRoot*.

Particular types of devices may be displayed to the user by specifying the device types through the *lDeviceType* parameter. If only one device meets the specification, **IWiaDevMgr::SelectDeviceDlg** does not display the **Select Device** dialog box. Instead it creates the [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) tree for the device and store a pointer to the **IWiaItem** interface of the root item in the parameter *ppItemRoot*. You can override this behavior and force **IWiaDevMgr::SelectDeviceDlg** to display the **Select Device** dialog box by passing WIA_SELECT_DEVICE_NODEFAULT as the value for the *lFlags* parameter.

If more than one WIA device matches the specification, all matching devices are displayed in the **Select Device** dialog box so the user may choose one.

Applications must call the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on the interface pointers they receive through the *ppItemRoot* parameter.

It is recommended that applications make device and image selection available through a menu item named **From scanner or camera** on the **File** menu.