# IFileDialogCustomize::MakeProminent

## Description

Places a control in the dialog so that it stands out compared to other added controls.

## Parameters

### `dwIDCtl` [in]

Type: **DWORD**

The ID of the control.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method causes the control to be placed near the **Open** or **Save** button instead of being grouped with the rest of the custom controls.

Only check buttons (check boxes), push buttons, combo boxes, and menus—or a visual group that contains only a single item of one of those types—can be made prominent.

Only one control can be marked in this way. If a dialog has only one added control, that control is marked as prominent by default.