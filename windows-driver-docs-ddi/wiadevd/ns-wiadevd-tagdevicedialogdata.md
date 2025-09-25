# tagDEVICEDIALOGDATA structure

## Description

The DEVICEDIALOGDATA structure contains all the data needed to implement a custom device dialog.

## Members

### `cbSize`

Specifies the size of this structure in bytes.

### `hwndParent`

Specifies the handle to the parent window of the dialog.

### `pIWiaItemRoot`

Points to an **IWiaItem** interface that represents the valid root item in the application item tree. For more information about this interface, see the Windows SDK documentation.

### `dwFlags`

Specifies the flags passed to **IWiaItem::DeviceDlg** and **IWiaDevMgr::GetImageDlg** by the calling program. These methods are described in the Windows SDK documentation. The possible values for this member are WIA_DEVICE_DIALOG_SINGLE_IMAGE and WIA_DEVICE_DIALOG_USE_COMMON_UI (defined in *Wiadef.h*).

### `lIntent`

Specifies the intents passed to **IWiaItem::DeviceDlg** and **IWiaDevMgr::GetImageDlg** by the calling program (see the Windows SDK documentation).

### `lItemCount`

Specifies the number of items in the array to which **ppIWiaItems** points.

### `ppWiaItems`

Array of IWiaItem interface pointers. Array must

## Remarks

The DEVICEDIALOGDATA structure is used by the [IWiaUIExtension::DeviceDialog](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff545069(v=vs.85)) method.

The array specified in *ppIWiaItems* must be allocated using **CoTaskMemAlloc**. All interface pointers indicated in the array must be initialized using the **AddRef** COM method. See the Windows SDK documentation for descriptions of these functions.

The **IWiaPropertyStorage** interface is used to access information about the **IWiaItem** object's properties. Applications must query an item to obtain its **IWiaPropertyStorage** interface. See the Windows SDK documentation for descriptions of this interface.

## See also

[IWiaUIExtension::DeviceDialog](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff545069(v=vs.85))