# ITfMenu::AddMenuItem

## Description

Adds an item to the menu that the language bar will display for the button.

## Parameters

### `uId` [in]

Contains the menu item identifier.

### `dwFlags` [in]

Contains zero or a combination of one or more of the [TF_LBMENUF_*](https://learn.microsoft.com/windows/desktop/TSF/tf-lbmenuf--constants) values that specify the type and state of the menu item.

### `hbmp` [in]

Contains the handle of the bitmap drawn for the menu item. If this is **NULL**, no bitmap is displayed for the menu item.

### `hbmpMask` [in]

Contains the handle of the mask bitmap. This is a monochrome bitmap that functions as a mask for *hbmp*. Each black pixel in this bitmap will cause the corresponding pixel in *hbmp* to be displayed in its normal color. Each white pixel in this bitmap will cause the corresponding pixel in *hbmp* to be displayed in the inverse of its normal color.

To have the bitmap displayed without any color conversion, create a monochrome bitmap the same size as *hbmp* and set each pixel to black (RGB(0, 0, 0)).

If *hbmp* is **NULL**, this parameter is ignored.

### `pch` [in]

Pointer to a **WCHAR** buffer that contains the text to be displayed for the menu item. The length of the text is specified by *cch*.

### `cch` [in]

Specifies the length, in **WCHAR**, of the menu item text in *pch*.

### `ppMenu`

[in, out] Pointer to an [ITfMenu](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itfmenu) interface pointer that receives the submenu object. This parameter is not used and must be **NULL** if *dwFlags* does not contain **TF_LBMENUF_SUBMENU**.

If the submenu item is successfully created, this parameter receives an [ITfMenu](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itfmenu) object that the caller uses to add items to the submenu.

If *dwFlags* contains **TF_LBMENUF_SUBMENU**, this value must be initialized to **NULL** prior to calling this method because, in most cases, this is a marshalled call. Not initializing this variable results in the marshaller attempting to access random memory.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## See also

[ITfMenu](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itfmenu)

[TF_LBMENUF_* Constants](https://learn.microsoft.com/windows/desktop/TSF/tf-lbmenuf--constants)