# Button_GetIdealSize macro

## Syntax

```cpp
BOOL Button_GetIdealSize(
   HWND hwnd,
   SIZE *psize
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the macro succeeds, it returns **TRUE**. Otherwise it returns **FALSE**.

## Description

Gets the size of the button that best fits the text and image, if an image list is present. You can use this macro or send the [BCM_GETIDEALSIZE](https://learn.microsoft.com/windows/desktop/Controls/bcm-getidealsize) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the button control.

### `psize`

Type: **[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)***

A pointer to a [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure that receives the desired size of the button including the text and image list if present.

## Remarks

This macro is most applicable to PushButtons. When sent to a PushButton, the macro retrieves the bounding rectangle required to display the button's text. And, if the PushButton has an image list, the bounding rectangle is also sized to include the button's image.

When sent to a button of any other type, the size of the control's window rectangle is retrieved.

**Note** To use this macro, you must provide a manifest specifying Comctl32.dll version 6.0. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).

## See also

[BCM_GETIDEALSIZE](https://learn.microsoft.com/windows/desktop/Controls/bcm-getidealsize)

**Other Resources**

**Reference**

[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)