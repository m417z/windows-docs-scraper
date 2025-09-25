# DAD_ShowDragImage function

## Description

[**DAD_ShowDragImage** is available in Windows 2000 and Windows XP. It might be altered or unavailable in subsequent versions. Use [ImageList_DragShowNolock](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_dragshownolock) instead.
]

Shows or hides the image being dragged.

## Parameters

### `fShow`

Type: **BOOL**

A value that specifies whether to show or hide the image being dragged.

#### FALSE

Hides the image.

#### TRUE

Shows the image.

## Return value

Type: **BOOL**

Returns nonzero if successful, or zero otherwise.

## Remarks

This function works on locked windows. It does not work on layered windows.