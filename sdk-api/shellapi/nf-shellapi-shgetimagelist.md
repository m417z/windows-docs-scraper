# SHGetImageList function

## Description

Retrieves an image list.

## Parameters

### `iImageList` [in]

Type: **int**

The image type contained in the list. One of the following values:

#### SHIL_LARGE (0x0)

0x0. The image size is normally 32x32 pixels. However, if the **Use large icons** option is selected from the **Effects** section of the **Appearance** tab in **Display Properties**, the image is 48x48 pixels.

#### SHIL_SMALL (0x1)

0x1. These images are the Shell standard small icon size of 16x16, but the size can be customized by the user.

#### SHIL_EXTRALARGE (0x2)

0x2. These images are the Shell standard extra-large icon size. This is typically 48x48, but the size can be customized by the user.

#### SHIL_SYSSMALL (0x3)

0x3. These images are the size specified by [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics) called with **SM_CXSMICON** and **GetSystemMetrics** called with **SM_CYSMICON**.

#### SHIL_JUMBO (0x4)

0x4. **Windows Vista and later.** The image is normally 256x256 pixels.

#### SHIL_LAST

The largest valid flag value, for validation purposes.

### `riid` [in]

Type: **REFIID**

Reference to the image list interface identifier, normally IID_IImageList.

### `ppvObj` [out]

Type: **void****

When this method returns, contains the interface pointer requested in *riid*. This is typically [IImageList](https://learn.microsoft.com/windows/desktop/api/commoncontrols/nn-commoncontrols-iimagelist).

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The [IImageList](https://learn.microsoft.com/windows/desktop/api/commoncontrols/nn-commoncontrols-iimagelist) pointer type, such as that returned in the *ppv* parameter, can be cast as an **HIMAGELIST** as needed; for example, for use in a list view. Conversely, an **HIMAGELIST** can be cast as a pointer to an **IImageList**.

As of Windows Vista, **SHIL_SMALL**, **SHIL_LARGE**, and **SHIL_EXTRALARGE** scale with dots per inch (dpi) if the process is marked as dpi-aware. To set these types to be dpi-aware, call [SetProcessDPIAware](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setprocessdpiaware). **SHIL_JUMBO** is fixed at 256 pixels regardless of the dpi-aware setting.

## See also

[FileIconInit](https://learn.microsoft.com/windows/desktop/shell/fileiconinit)