# SHGetImageList function

## Description

Retrieves an image list.

## Parameters

### `iImageList` [in]

Type: **int**

The image type contained in the list. One of the following values:

| Value | Description |

|---|---|

| **SHIL_LARGE** (0x0) | 32x32 pixels at 96 DPI; scales with DPI via **SM_CXICON** / **SM_CYICON**. |

| **SHIL_SMALL** (0x1) | 16x16 pixels at 96 DPI; scales with DPI via **SM_CXSMICON** / **SM_CYSMICON**. |

| **SHIL_EXTRALARGE** (0x2) | 48x48 pixels at 96 DPI; scales with DPI (48 logical pixels). |

| **SHIL_SYSSMALL** (0x3) | Tracks the caption button size (**SM_CXSMSIZE** / **SM_CYSMSIZE**). Typically matches **SHIL_SMALL** but may differ when the user customizes window border and caption size in Display Settings. |

| **SHIL_JUMBO** (0x4) | Windows Vista and later. Fixed at 256x256 physical pixels regardless of DPI. |

| **SHIL_LAST** | The largest valid flag value, for validation purposes. |

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