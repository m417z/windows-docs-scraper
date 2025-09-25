# UiaRaiseStructureChangedEvent function

## Description

Called by a provider to notify the Microsoft UI Automation core that the tree structure has changed.

## Parameters

### `pProvider` [in]

Type: **[IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple)***

The provider node where the tree change occurred.

### `structureChangeType` [in]

Type: **[StructureChangeType](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-structurechangetype)**

The type of change that occurred in the tree.

### `pRuntimeId` [in]

Type: **int***

The runtime IDs for the child elements of the provider node where the tree change occurred. This parameter is used only when *structureChangeType* is [StructureChangeType_ChildRemoved](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-structurechangetype); it is **NULL** for all other structure-change events.

**Note** For Windows 7, the array of integers pointed to by *pRuntimeId* can contain a partial set of IDs that identify only those elements affected by the structure change.

### `cRuntimeIdLen` [in]

Type: **int**

Length of the array of integers.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An example of a change in the tree structure is child elements being added to or removed from a list box, or being expanded or collapsed in a tree view.