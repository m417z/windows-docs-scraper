# SHDefExtractIconW function

## Description

Provides a default handler to extract an icon from a file.

## Parameters

### `pszIconFile` [in]

Type: **LPCTSTR**

A pointer to a null-terminated buffer that contains the path and name of the file from which the icon is extracted.

### `iIndex`

Type: **int**

The location of the icon within the file named in *pszIconFile*. If this is a positive number, it refers to the zero-based position of the icon in the file. For instance, 0 refers to the 1st icon in the resource file and 2 refers to the 3rd. If this is a negative number, it refers to the icon's resource ID.

### `uFlags` [in]

Type: **UINT**

A flag that controls the icon extraction.

#### GIL_SIMULATEDOC

Overlays the extracted icon on the default document icon to create the final icon. This icon can be used when no more appropriate icon can be found or retrieved.

### `phiconLarge` [out, optional]

Type: **HICON***

A pointer to an HICON that, when this function returns successfully, receives the handle of the large version of the icon specified in the [LOWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632659(v=vs.85)) of *nIconSize*. This value can be **NULL**.

### `phiconSmall` [out, optional]

Type: **HICON***

A pointer to an HICON that, when this function returns successfully, receives the handle of the small version of the icon specified in the [HIWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632657(v=vs.85)) of *nIconSize*.

### `nIconSize`

Type: **UINT**

A value that contains the large icon size in its [LOWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632659(v=vs.85)) and the small icon size in its [HIWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632657(v=vs.85)). Size is measured in pixels. Pass 0 to specify default large and small sizes.

##### - uFlags.GIL_SIMULATEDOC

Overlays the extracted icon on the default document icon to create the final icon. This icon can be used when no more appropriate icon can be found or retrieved.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **S_FALSE** | The requested icon is not present. |
| **E_FAIL** | The file cannot be accessed, or is being accessed through a slow link. |

## Remarks

It is the responsibility of the caller to free the icon resources created through this function when they are no longer needed. This can be done through the [DestroyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyicon) function.

> [!NOTE]
> The shlobj_core.h header defines SHDefExtractIcon as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).