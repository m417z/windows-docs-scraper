# ITaskbarList3::ThumbBarAddButtons

## Description

Adds a thumbnail toolbar with a specified set of buttons to the thumbnail image of a window in a taskbar button flyout.

## Parameters

### `hwnd` [in]

Type: **HWND**

The handle of the window whose thumbnail representation will receive the toolbar. This handle must belong to the calling process.

### `cButtons` [in]

Type: **UINT**

The number of buttons defined in the array pointed to by *pButton*. The maximum number of buttons allowed is 7.

### `pButton` [in]

Type: **LPTHUMBBUTTON**

A pointer to an array of [THUMBBUTTON](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-thumbbutton) structures. Each **THUMBBUTTON** defines an individual button to be added to the toolbar. Buttons cannot be added or deleted later, so this must be the full defined set. Buttons also cannot be reordered, so their order in the array, which is the order in which they are displayed left to right, will be their permanent order.

## Return value

Type: **HRESULT**

Returns **S_OK** if successful, or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *hwnd* parameter does not specify a handle that belongs to the process or does not specify a window that is associated with a taskbar button. This value is also returned if *pButton* is less than 1 or greater than 7. |

## Remarks

This method allows an application to define buttons for an active toolbar control that is embedded in a window's taskbar thumbnail preview. This provides access to the window's essential commands without making the user restore or activate the window. For example, Windows Media Player might offer standard media transport controls such as play, pause, mute, and stop.

The toolbar used in the thumbnail is essentially a standard [toolbar](https://learn.microsoft.com/windows/desktop/Controls/toolbar-control-reference) control. It has a maximum of seven buttons, and it is center-aligned, transparent, and displayed in an area beneath the thumbnail rather than covering any portion of it. Each button's ID, image, tooltip, and state are defined in a [THUMBBUTTON](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-thumbbutton) structure, which is then passed to the taskbar. The application can then subsequently show, alter, or hide buttons from the thumbnail toolbar as required by its current state by calling [ITaskbarList3::ThumbBarUpdateButtons](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-thumbbarupdatebuttons).

When a button in a thumbnail toolbar is clicked, the window associated with that thumbnail is sent a [WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command) message with the [HIWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632657(v=vs.85)) of its *wParam* parameter set to **THBN_CLICKED** and the [LOWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632659(v=vs.85)) to the button ID.

After a toolbar has been added to a thumbnail, buttons can be altered only through [ITaskbarList3::ThumbBarUpdateButtons](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-thumbbarupdatebuttons). While individual buttons cannot be added or removed, they can be shown and hidden through **ThumbBarUpdateButtons** as needed. The toolbar itself cannot be removed without re-creating the window itself.

Because there is a limited amount of space in which to display thumbnails, as well as a constantly changing number of thumbnails to display, applications are not guaranteed a specific toolbar size. If display space is low, buttons in the toolbar are truncated from right to left as needed. Therefore, an application should prioritize the commands associated with its buttons to ensure that those of highest priority are to the left and are therefore least likely to be truncated.

Thumbnail toolbars are displayed only when thumbnails are being displayed. For instance, if a taskbar button represents a group with more open windows than there is room to display thumbnails for, the UI reverts to a legacy menu rather than thumbnails.

#### Examples

The following example shows how to use **ThumbBarAddButtons** to add a toolbar that contains two buttons to a thumbnail on the extended taskbar.

```cpp
HRESULT AddThumbarButtons(HWND hwnd, HIMAGELIST himl, HIMAGELIST himlHot)
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

[ITaskbarList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist)

[ITaskbarList2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist2)

[ITaskbarList3](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist3)

[ITaskbarList3::ThumbBarSetImageList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-thumbbarsetimagelist)

[ITaskbarList3::ThumbBarUpdateButtons](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-thumbbarupdatebuttons)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)