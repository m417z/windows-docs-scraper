# _ViewOptions enumeration

## Description

The
**ViewOptions** enumeration is used by the
[Views.Add](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/views-add) method and specifies the visibility of the view, scope tree, and toolbars, as well as the persistence state of the view. These flags can be combined using a bitwise OR operation. This enumeration applies to the
[MMC 2.0 Automation Object Model](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmc-2-0-automation-object-model).

## Constants

### `ViewOption_Default:0`

The view is added with default settings.

### `ViewOption_ScopeTreeHidden:0x1`

The view is added with the scope tree pane hidden. The user will not be able to show the scope tree, as the **Console Tree** check box will be disabled in the **Customize View** dialog box.

### `ViewOption_NoToolBars:0x2`

The view is added with toolbars hidden.

### `ViewOption_NotPersistable:0x4`

The view is added as temporary (without persistence capability).

### `ViewOption_ActionPaneHidden:0x8`

## See also

[Views collection](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/views-collection)

[Views.Add](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/views-add)