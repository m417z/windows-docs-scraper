# IComponentData2::QueryDispatch

## Description

The
**QueryDispatch** method returns the snap-in's **IDispatch** interface for a specified item. MMC exposes this interface through the
[MMC 2.0 Automation object model](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmc-2-0-automation-object-model). Script, or other applications, can access the **IDispatch** interface for the item represented by the specified cookie through the
[View.SnapinScopeObject](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/view-snapinscopeobject) and
[View.SnapinSelectionObject](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/view-snapinselectionobject) methods.

## Parameters

### `cookie` [in]

A value that specifies the context item (or items) for which the **IDispatch** interface is requested. The *cookie* value is previously provided by the snap-in, and MMC uses it in this method call.

### `type` [in]

A value that specifies the data object as one of the following constant values, which are members of the
**DATA_OBJECT_TYPES** enumeration.

#### CCT_SCOPE = 0x8000

Data object for the scope pane.

#### CCT_RESULT = 0x8001

Data object for the result pane.

### `ppDispatch` [out]

Dispatch interface pointer. The snap-in sets **ppDispatch* to the **IDispatch** interface corresponding to the *cookie* value.

## Return value

If successful, the return value is S_OK. Other return values indicate an error code.

## See also

[View.SnapinScopeObject](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/view-snapinscopeobject)

[View.SnapinSelectionObject](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/view-snapinselectionobject)