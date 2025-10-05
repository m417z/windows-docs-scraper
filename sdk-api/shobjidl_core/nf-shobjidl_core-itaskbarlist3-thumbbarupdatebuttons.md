# ITaskbarList3::ThumbBarUpdateButtons

## Description

Shows, enables, disables, or hides buttons in a thumbnail toolbar as required by the window's current state. A thumbnail toolbar is a toolbar embedded in a thumbnail image of a window in a taskbar button flyout.

## Parameters

### `hwnd` [in]

Type: **HWND**

The handle of the window whose thumbnail representation contains the toolbar.

### `cButtons` [in]

Type: **UINT**

The number of buttons defined in the array pointed to by _pButton_. The maximum number of buttons allowed is 7. This array contains only structures that represent existing buttons that are being updated.

### `pButton` [in]

Type: **LPTHUMBBUTTON**

A pointer to an array of [THUMBBUTTON](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ns-shobjidl_core-thumbbutton) structures. Each **THUMBBUTTON** defines an individual button. If the button already exists (the **iId** value is already defined), then that existing button is updated with the information provided in the structure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Because there is a limited amount of space in which to display thumbnails, as well as a constantly changing number of thumbnails to display, applications are not guaranteed a specific toolbar size. If display space is low, buttons in the toolbar are truncated from right to left as needed. Therefore, an application should prioritize the commands associated with its buttons to ensure that those of highest priority are to the left and are therefore least likely to be truncated.

Thumbnail toolbars are displayed only when thumbnails are being displayed on the taskbar. For instance, if a taskbar button represents a group with more open windows than there is room to display thumbnails for, the UI reverts to a legacy menu rather than thumbnails.

### Accessibility

For information about accessibility in thumb bar button images, see the Remarks section of [ThumbBarSetImageList](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-thumbbarsetimagelist).

### Examples

The following example shows how to use **ThumbBarUpdateButtons** to change the text and image on an existing button in a thumbnail toolbar on the extended taskbar.

```cpp
HRESULT UpdateThumbBarButton(HWND hwnd)
{
    // Define a single structure for the button to update. The ID is that
    // of an existing button, so the other information (bitmap index and
    // tooltip) overwrites the existing values, updating the button.
    THUMBBUTTON thbButton;
    thbButton.dwMask = THB_BITMAP | THB_TOOLTIP;
    thbButtons[0].iId = 1;
    thbButton.iBitmap = 3;
    thbButton.pszTip = TEXT("Different Text");

    // Create an instance of ITaskbarList3
    ITaskBarList3 *ptbl;
    HRESULT hr = CoCreateInstance(CLSID_TaskbarList,
                                  NULL,
                                  CLSCTX_INPROC_SERVER,
                                  IID_PPV_ARGS(&ptbl);

    if (SUCCEEDED(hr))
    {
        // Update the toolbar. In this case, only the single button is updated.
        hr = ptbl->ThumbBarUpdateButtons(hwnd, 1, &thbButton);
        ptbl->Release();
    }
    return hr;
}
```

## See also

[ITaskbarList](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nn-shobjidl_core-itaskbarlist)

[ITaskbarList2](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nn-shobjidl_core-itaskbarlist2)

[ITaskbarList3](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nn-shobjidl_core-itaskbarlist3)

[ITaskbarList3::ThumbBarSetImageList](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-thumbbarsetimagelist)

[ITaskbarList3::ThumbBarAddButtons](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-thumbbaraddbuttons)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)