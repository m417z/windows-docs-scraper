# IUIFramework::InvalidateUICommand

## Description

Invalidates a Windows Ribbon framework Command property, value, or state.

## Parameters

### `commandId` [in]

Type: **UINT32**

The ID for the Command, which is specified in the markup resource file.

### `flags` [in]

Type: **[UI_INVALIDATIONS](https://learn.microsoft.com/windows/desktop/api/uiribbon/ne-uiribbon-ui_invalidations)**

Identifies which [aspect](https://learn.microsoft.com/windows/desktop/api/uiribbon/ne-uiribbon-ui_invalidations) of a command to invalidate.

**Note** Passing **UI_INVALIDATIONS_ALLPROPERTIES** invalidates all properties bound to a command, including value and state.

### `key` [in]

Type: **const PROPERTYKEY***

The property key of the command property or state.
This parameter can be **NULL**.

## Return value

Type: **HRESULT**

Returns S_OK if successful; otherwise, an error value from the following list.

| Value | Description |
| --- | --- |
| E_INVALIDARG | An invalid value for *key* was supplied. |
| E_FAIL | The operation failed. All the commands failed to invalidate, or none of the properties specified are supported. |

## Remarks

Resources defined in the Ribbon framework markup are stored in a resource table that is created
when the markup file is compiled into binary format. A resource cannot be reinstated from the Markup resource table after it has been invalidated.

After invalidation, the framework queries the host application for the resource details.

When a Command value is invalidated (*flags* contains UI_INVALIDATIONS_VALUE) the value of *key* is **NULL**.

If **IUIFramework::InvalidateUICommand** is called multiple times
and the [UI_INVALIDATIONS](https://learn.microsoft.com/windows/desktop/api/uiribbon/ne-uiribbon-ui_invalidations)
value passed in each call specifies overlapping properties, such as **UI_INVALIDATIONS_STATE**
and **UI_INVALIDATIONS_ALLPROPERTIES**, then only one callback to the host application is created.

## See also

[IUIFramework](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiframework)

[UI_INVALIDATIONS](https://learn.microsoft.com/windows/desktop/api/uiribbon/ne-uiribbon-ui_invalidations)

[Windows Ribbon Framework Samples](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-samples-entry)