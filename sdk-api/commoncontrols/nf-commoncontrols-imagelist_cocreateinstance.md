# ImageList_CoCreateInstance function

## Description

Creates a single instance of an imagelist and returns an interface pointer to it.

## Parameters

### `rclsid` [in]

Type: **REFCLSID**

A reference to the CLSID—a GUID that identifies the COM object to be created. This should be **CLSID_ImageList**.

### `punkOuter` [in, optional]

Type: **const [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the outer [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface that aggregates the object created by this function, or **NULL** if no aggregation is desired.

### `riid` [in]

Type: **REFIID**

Reference to the desired interface ID.

### `ppv` [out]

Type: **void****

When this method returns, contains the interface pointer requested in *riid*. This is normally [IImageList2](https://learn.microsoft.com/windows/desktop/api/commoncontrols/nn-commoncontrols-iimagelist2), which provides the [Initialize](https://learn.microsoft.com/windows/desktop/api/commoncontrols/nf-commoncontrols-iimagelist2-initialize) method.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Before calling this function, COM must be initialized by calling [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) or [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex).

Call **ImageList_CoCreateInstance** for a customized image list; otherwise, call [SHGetImageList](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shgetimagelist) to load the system image list. Call [SHGetFileInfo](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shgetfileinfoa) with the *uflag* parameter set to **SHGFI_SYSICONINDEX** to retrieve a handle to the system image list.