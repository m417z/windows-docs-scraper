# HIMAGELIST_QueryInterface function

## Description

Retrieves a pointer to an [IImageList](https://learn.microsoft.com/windows/desktop/api/commoncontrols/nn-commoncontrols-iimagelist) or [IImageList2](https://learn.microsoft.com/windows/desktop/api/commoncontrols/nn-commoncontrols-iimagelist2) object that corresponds to the image list's HIMAGELIST handle.

## Parameters

### `himl` [in]

Type: **HIMAGELIST**

The handle to the image list.

### `riid` [in]

Type: **REFIID**

The identifier of the interface being requested. Normally IID_IImageList or IID_IImageList2.

### `ppv` [out]

Type: **void****

When this method returns, contains the address of the interface pointer requested in *riid*. If the object does not support the interface specified in *riid*, *ppv* is **NULL**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.