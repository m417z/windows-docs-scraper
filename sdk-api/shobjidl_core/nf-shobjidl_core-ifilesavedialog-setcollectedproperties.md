# IFileSaveDialog::SetCollectedProperties

## Description

Specifies which properties will be collected in the save dialog.

## Parameters

### `pList` [in]

Type: **[IPropertyDescriptionList](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescriptionlist)***

Pointer to the interface that represents the list of properties to collect. This parameter can be **NULL**.

### `fAppendDefault` [in]

Type: **BOOL**

**TRUE** to show default properties for the currently selected filetype in addition to the properties specified by *pList*. **FALSE** to show only properties specified by *pList*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The calling application can use the [PSGetPropertyDescriptionListFromString](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetpropertydescriptionlistfromstring) function to construct an [IPropertyDescriptionList](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescriptionlist) from a string such as "prop:Comments;Subject;".

For more information about property schemas, see
[Property Schemas](https://learn.microsoft.com/windows/desktop/properties/building-property-handlers-property-schemas).

**IFileSaveDialog::SetCollectedProperties** can be called at any time before the dialog is displayed or while it is visible. If different properties are to be collected depending on the chosen filetype, then **IFileSaveDialog::SetCollectedProperties** can be called in response to [OnTypeChange](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialogevents-ontypechange).

**Note** By default, no properties are collected in the save dialog.

## See also

[IFileSaveDialog](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifilesavedialog)

[IFileSaveDialog::SetProperties](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifilesavedialog-setproperties)