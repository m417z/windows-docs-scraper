# IUIFramework::SetModes

## Description

Specifies the application modes to enable.

## Parameters

### `iModes`

Type: **INT32**

A bit mask that identifies the modes.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A mode indicates the functionality required and, therefore, which elements should be displayed (or
hidden) at run time, depending on the state or context of an application. For example, network connectivity
may directly impact the functionality of an application and require a "Network" mode of
network-related commands whenever a connection is detected.

Modes are specified for elements in the Ribbon markup and bound to individual controls at run time.

Modes can be applied to a Ribbon [Tab](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-tab) and [Group](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-group).

**Note** Modes can be applied to [Button](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-button), [SplitButton](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-splitbutton), and [DropDownButton](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-dropdownbutton) controls when hosted in the left
column of the Application Menu.

## See also

[IUIFramework](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiframework)

[Markup Elements](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-reference-markup-elements)

[Reconfiguring the Ribbon with Application Modes](https://learn.microsoft.com/windows/desktop/windowsribbon/ribbon-applicationmodes)

[Windows Ribbon Framework Samples](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-samples-entry)