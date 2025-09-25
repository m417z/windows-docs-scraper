# TreeScope enumeration

## Description

Contains values that specify the scope of various operations in the Microsoft UI Automation tree.

## Constants

### `TreeScope_None:0x0`

The scope excludes the subtree from the search.

### `TreeScope_Element:0x1`

The scope includes the element itself.

### `TreeScope_Children:0x2`

The scope includes children of the element.

### `TreeScope_Descendants:0x4`

The scope includes children and more distant descendants of the element.

### `TreeScope_Parent:0x8`

The scope includes the parent of the element.

### `TreeScope_Ancestors:0x10`

The scope includes the parent and more distant ancestors of the element.

### `TreeScope_Subtree`

The scope includes the element and all its descendants. This flag is a combination of the TreeScope_Element and TreeScope_Descendants values.

## See also

[AddAutomationEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-addautomationeventhandler)

[AddPropertyChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-addpropertychangedeventhandler)

[AddPropertyChangedEventHandlerNativeArray](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-addpropertychangedeventhandlernativearray)

[AddStructureChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-addstructurechangedeventhandler)

[FindAll](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-findall)

[FindAllBuildCache](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-findallbuildcache)

[FindFirst](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-findfirst)

[FindFirstBuildCache](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-findfirstbuildcache)

**Reference**