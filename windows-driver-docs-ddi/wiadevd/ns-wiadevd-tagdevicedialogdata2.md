# tagDEVICEDIALOGDATA2 structure

## Description

The DEVICEDIALOGDATA2 structure contains all the data needed to implement a custom device dialog.

## Members

### `cbSize`

Specifies the size, in bytes, of this structure.

### `pIWiaItemRoot`

Points to an [IWiaItem2](https://learn.microsoft.com/windows/win32/wia/-wia-iwiaitem2) interface that represents the valid root item in the application item tree.

### `dwFlags`

Specifies the flags passed to [IWiaItem2::DeviceDlg](https://learn.microsoft.com/windows/win32/wia/-wia-iwiaitem2-devicedlg) and [IWiaDevMgr2::GetImageDlg](https://learn.microsoft.com/windows/win32/wia/-wia-iwiadevmgr2-getimagedlg) by the calling program. The possible values for this member are WIA_DEVICE_DIALOG_SINGLE_IMAGE and WIA_DEVICE_DIALOG_USE_COMMON_UI (defined in header file *Wiadef.h*).

### `hwndParent`

Specifies the handle to the parent window of the dialog.

### `bstrFolderName`

A string of type **BSTR** that contains the name of the destination folder to which the files obtained from WIA items are transferred.

### `bstrFilename`

A string of type **BSTR** that contains the file name template to be used for files transferred from WIA items to the destination folder designated by **bstrFolderName**. An arbitrary number of unique file names can be created by appending additional characters to the file name template. For more information about file name templates, see [PathMakeUniqueName](https://learn.microsoft.com/windows/win32/api/shlobj_core/nf-shlobj_core-pathmakeuniquename) and [PathYetAnotherMakeUniqueName](https://learn.microsoft.com/windows/win32/api/shlobj_core/nf-shlobj_core-pathyetanothermakeuniquename).

### `lNumFiles`

The number of strings written to the *pbstrFilePaths* array.

### `pbstrFilePaths`

Pointer to an array of **BSTR** pointers. Each array element points to a **BSTR** that contains the destination name of a file that was successfully transferred to the folder identified by **bstrFolderName**. The method must allocate the storage for this member. For more information, see the following **Remarks** section.

### `pWiaItem`

Pointer to the **IWiaItem2** interface of the WIA item that transfers data to the file or files named in the **bstrFilePaths** array.

## Remarks

The DEVICEDIALOGDATA2 structure is used by the [IWiaUIExtension2::DeviceDialog](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff545053(v=vs.85)) method.

The **DeviceDialog** method must allocate the **BSTR** pointer array specified in *pbstrFilePaths* by calling the [CoTaskMemAlloc](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemalloc) function, and it must allocate each string pointed to by the array by calling the [SysAllocString](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-sysallocstring) function. The calling program is responsible for freeing the storage for the pointer array and strings.

To retain a reference to an **IWiaItem2** interface, the **DeviceDialog** method must call the [IUnknown::AddRef](https://learn.microsoft.com/windows/win32/api/unknwn/nf-unknwn-iunknown-addref) method on the interface before returning from the call.

To access information about an **IWiaItem2** object's properties, the **DeviceDialog** method must query the object to obtain its [IWiaPropertyStorage](https://learn.microsoft.com/windows/win32/api/wia_xp/nn-wia_xp-iwiapropertystorage) interface. To transfer data from an **IWiaItem2** object, the **DeviceDialog** method must query the object to obtain its [IWiaTransfer](https://learn.microsoft.com/windows/win32/wia/-wia-iwiatransfer) interface.

## See also

[CoTaskMemAlloc](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemalloc)

[IUnknown::AddRef](https://learn.microsoft.com/windows/win32/api/unknwn/nf-unknwn-iunknown-addref)

[IWiaDevMgr2::GetImageDlg](https://learn.microsoft.com/windows/win32/wia/-wia-iwiadevmgr2-getimagedlg)

[IWiaItem2](https://learn.microsoft.com/windows/win32/wia/-wia-iwiaitem2)

[IWiaItem2::DeviceDlg](https://learn.microsoft.com/windows/win32/wia/-wia-iwiaitem2-devicedlg)

[IWiaPropertyStorage](https://learn.microsoft.com/windows/win32/api/wia_xp/nn-wia_xp-iwiapropertystorage)

[IWiaTransfer](https://learn.microsoft.com/windows/win32/wia/-wia-iwiatransfer)

[IWiaUIExtension2::DeviceDialog](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff545053(v=vs.85))

[PathMakeUniqueName](https://learn.microsoft.com/windows/win32/api/shlobj_core/nf-shlobj_core-pathmakeuniquename)

[PathYetAnotherMakeUniqueName Function](https://learn.microsoft.com/windows/win32/api/shlobj_core/nf-shlobj_core-pathyetanothermakeuniquename)

[SysAllocString](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-sysallocstring)