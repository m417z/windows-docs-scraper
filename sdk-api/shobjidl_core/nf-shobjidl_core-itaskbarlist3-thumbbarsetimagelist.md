# ITaskbarList3::ThumbBarSetImageList

## Description

Specifies an image list that contains button images for a toolbar embedded in a thumbnail image of a window in a taskbar button flyout.

## Parameters

### `hwnd` [in]

Type: **HWND**

The handle of the window whose thumbnail representation contains the toolbar to be updated. This handle must belong to the calling process.

### `himl` [in]

Type: **HIMAGELIST**

The handle of the image list that contains all button images to be used in the toolbar.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Applications must provide these button images:

- The button in its default active state.
- Images suitable for use with high-dpi (dots per inch) displays.

Images must be 32-bit and of dimensions [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics)(SM_CXICON) x [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics)(SM_CYICON). The toolbar itself provides visuals for a button's clicked, disabled, and hover states.

### Accessibility

The button images supplied in the [THUMBBUTTON](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ns-shobjidl_core-thumbbutton) structure indexed from the image list can be used in a variety of user personalization scenarios. A common example is light and dark color modes and contrast themes for accessibility. Choose assets that remain visually clear in all these contexts.

You can handle this in two ways:

- Register for theme change events (see [Support Dark and Light themes in Win32 apps](https://learn.microsoft.com/windows/apps/desktop/modernize/ui/apply-windows-themes)) and update buttons when themes change.
- Use assets with built-in contrast, like glyphs with solid white fills and solid black outlines.

### Examples

The following example shows how to create a thumbnail toolbar with two buttons whose images come from an image list.

```cpp

HRESULT AddThumbBarButtons(HWND hwnd, HIMAGELIST himl, HIMAGELIST himlHot)
{
    // Define an array of two buttons. These buttons provide images through an
    // image list and also provide tooltips.
    DWORD dwMask = THB_BITMAP | THB_TOOLTIP | THB_FLAGS;

    THUMBBUTTON thbButtons[2];
    thbButtons[0].dwMask = dwMask;
    thbButtons[0].iId = 0;
    thbButtons[0].iBitmap = 0;
    thbButtons[0].pszTip = TEXT("Button 1");
    thbButtons[0].dwFlags = THBF_DISMISSONCLICK;

    dwMask = THB_BITMAP | THB_TOOLTIP;
    thbButtons[1].dwMask = dwMask;
    thbButtons[1].iId = 1;
    thbButtons[1].iBitmap = 1;
    thbButtons[1].pszTip = TEXT("Button 2");

    // Create an instance of ITaskbarList3
    ITaskBarList3 *ptbl;
    HRESULT hr = CoCreateInstance(CLSID_TaskbarList,
                                  NULL,
                                  CLSCTX_INPROC_SERVER,
                                  IID_PPV_ARGS(&ptbl);

    if (SUCCEEDED(hr))
    {
        // Declare the image list that contains the button images.
        hr = ptbl->ThumbBarSetImageList(hwnd, himl);

        if (SUCCEEDED(hr))
        {
            // Attach the toolbar to the thumbnail.
            hr = ptbl->ThumbBarAddButtons(hwnd, ARRAYSIZE(thbButtons), &thbButtons);
        }
        ptbl->Release();
    }
    return hr;
}
```

## See also

[ITaskbarList](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nn-shobjidl_core-itaskbarlist)

[ITaskbarList2](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nn-shobjidl_core-itaskbarlist2)

[ITaskbarList3](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nn-shobjidl_core-itaskbarlist3)

[ITaskbarList3::ThumbBarAddButtons](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-thumbbaraddbuttons)

[ITaskbarList3::ThumbBarUpdateButtons](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-thumbbarupdatebuttons)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)