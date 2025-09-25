# MFCalculateBitmapImageSize function

## Description

Retrieves the image size for a video format. Given a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure, this function calculates the correct value of the **biSizeImage** member.

## Parameters

### `pBMIH` [in]

Pointer to a **BITMAPINFOHEADER** structure that describes the format.

### `cbBufSize` [in]

Size of the *pBMIH* buffer, in bytes. The size includes any color masks or palette entries that follow the **BITMAPINFOHEADER** structure.

### `pcbImageSize` [out]

Receives the image size, in bytes.

### `pbKnown` [out]

Receives the value **TRUE** if the function recognizes the video format. Otherwise, receives the value **FALSE**. This parameter can be **NULL**.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |
| **E_INVALIDARG** | The **BITMAPINFOHEADER** structure is not valid, or the value of *cbBufSize* is too small. |

## Remarks

Before calling this function, you must set at least the following members of the **BITMAPINFOHEADER** structure:

* **biCompression**
* **biBitCount**
* **biWidth**
* **biHeight**

Also, if **biCompression** is **BI_BITFIELDS**, the **BITMAPINFOHEADER** structure must be followed by an array of color masks.

This function fails if the **BITMAPINFOHEADER** structure describes a format that is not a video format. For example, it fails if **biCompresson** is **BI_JPEG** or **BI_PNG** .

This function is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)