# IDsObjectPicker::InvokeDialog

## Description

The **IDsObjectPicker::InvokeDialog** method displays a modal object picker dialog box and returns the user selections.

## Parameters

### `hwndParent`

Handle to the owner window of the dialog box. This parameter cannot be **NULL** or the result of the [GetDesktopWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdesktopwindow) function.

### `ppdoSelections`

Pointer to an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface pointer that receives a data object that contains data about the user selections. This data is supplied in the [CFSTR_DSOP_DS_SELECTION_LIST](https://learn.microsoft.com/windows/desktop/AD/cfstr-dsop-ds-selection-list) data format. This parameter receives **NULL** if the user cancels the dialog box.

## Return value

Returns a standard error code or one of the following values.

## Remarks

Before **IDsObjectPicker::InvokeDialog** is called, the [IDsObjectPicker](https://learn.microsoft.com/windows/desktop/api/objsel/nn-objsel-idsobjectpicker) object must be initialized by calling [IDsObjectPicker::Initialize](https://learn.microsoft.com/windows/desktop/api/objsel/nf-objsel-idsobjectpicker-initialize). After the **IDsObjectPicker** object is initialized, **InvokeDialog** can be called multiple times without reinitializing the interface.

## See also

[CFSTR_DSOP_DS_SELECTION_LIST](https://learn.microsoft.com/windows/desktop/AD/cfstr-dsop-ds-selection-list)

[DS_SELECTION](https://learn.microsoft.com/windows/desktop/api/objsel/ns-objsel-ds_selection)

[DS_SELECTION_LIST](https://learn.microsoft.com/windows/desktop/api/objsel/ns-objsel-ds_selection_list)

[Directory Object Picker](https://learn.microsoft.com/windows/desktop/AD/directory-object-picker)

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[IDsObjectPicker](https://learn.microsoft.com/windows/desktop/api/objsel/nn-objsel-idsobjectpicker)