# DS_SELECTION_LIST structure

## Description

The **DS_SELECTION_LIST** structure contains data about the objects the user selected from an object picker dialog box. This structure is supplied by the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface supplied by the [IDsObjectPicker::InvokeDialog](https://learn.microsoft.com/windows/desktop/api/objsel/nf-objsel-idsobjectpicker-invokedialog) method in the [CFSTR_DSOP_DS_SELECTION_LIST](https://learn.microsoft.com/windows/desktop/AD/cfstr-dsop-ds-selection-list) data format.

## Members

### `cItems`

Contains the number of elements in the **aDsSelection** array.

### `cFetchedAttributes`

Contains the number of elements returned in the **pvarFetchedAttributes** member of each
[DS_SELECTION](https://learn.microsoft.com/windows/desktop/api/objsel/ns-objsel-ds_selection) structure.

### `aDsSelection`

Contains an array of [DS_SELECTION](https://learn.microsoft.com/windows/desktop/api/objsel/ns-objsel-ds_selection) structures, one for each object selected by the user. The **cItems** member indicates the number of elements in this array.

## See also

[CFSTR_DSOP_DS_SELECTION_LIST](https://learn.microsoft.com/windows/desktop/AD/cfstr-dsop-ds-selection-list)

[DS_SELECTION](https://learn.microsoft.com/windows/desktop/api/objsel/ns-objsel-ds_selection)

[Directory Object Picker](https://learn.microsoft.com/windows/desktop/AD/directory-object-picker)

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[IDsObjectPicker::InvokeDialog](https://learn.microsoft.com/windows/desktop/api/objsel/nf-objsel-idsobjectpicker-invokedialog)