# DAD_AutoScroll function

## Description

[**DAD_AutoScroll** is available in Windows 2000 and Windows XP. It might be altered or unavailable in subsequent versions.]

Scrolls the window while an image is being dragged.

## Parameters

### `hwnd` [in]

Type: **HWND**

A handle to the window being scrolled.

### `pad` [in]

Type: **[AUTO_SCROLL_DATA](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-auto_scroll_data)***

A pointer to the [AUTO_SCROLL_DATA](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-auto_scroll_data) structure.

### `pptNow` [in]

Type: **const [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

A pointer to the current scroll coordinates.

## Return value

Type: **BOOL**

Returns nonzero if successful, or zero otherwise.

## Remarks

The function is successful and the window scrolls only when the **bFull** parameter of the [AUTO_SCROLL_DATA](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-auto_scroll_data) structure is **TRUE**. Each time this function is called, as long as **bFull** is **FALSE**, the **iNextSample** parameter is incremented by 1 and the current scroll coordinates and time are returned in the **AUTO_SCROLL_DATA** structure. When **iNextSample** is equal to NUM_POINTS, **bFull** is set to **TRUE**, the function succeeds, and the window scrolls.

## See also

[AUTO_SCROLL_DATA](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-auto_scroll_data)