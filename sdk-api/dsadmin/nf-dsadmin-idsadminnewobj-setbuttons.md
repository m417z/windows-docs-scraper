# IDsAdminNewObj::SetButtons

## Description

The **IDsAdminNewObj::SetButtons** method enables or disables the "Next" command button in the wizard for a specific page.

## Parameters

### `nCurrIndex` [in]

Contains the zero-based index of the wizard page for which the "Next" button will be enabled or disabled. This index is relative to the page count of the wizard extension that calls the method.

### `bValid` [in]

Specifies if the "Next" command button is enabled or disabled. If this value is zero, the "Next" command button is disabled. If this value is nonzero, the "Next" command button is enabled.

## Return value

This method can return one of these values.

Returns one of the following values.

## Remarks

No assumption should be made regarding the state of the "Next" command button when the page is first displayed. The object creation extension should set the state of the "Next" command button when the page is first displayed and when the data in the page changes. If the data in the page is not mandatory, then the "Next" button should be enabled when the page is first displayed and the state should not be changed by the extension.

If the extension calling the function is a primary extension with a single page and there are no secondary extensions loaded, for example: the wizard has a single page, the command buttons are; "OK" and "Cancel", instead of "Back", "Next", and "Cancel". In this case, a call to this function will enable or disable the "OK" button.

## See also

[IDsAdminNewObj](https://learn.microsoft.com/windows/desktop/api/dsadmin/nn-dsadmin-idsadminnewobj)