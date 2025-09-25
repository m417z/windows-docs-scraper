# IUIAutomation::CreateTreeWalker

## Description

Retrieves a tree walker object that can be used to traverse the Microsoft UI Automation tree.

## Parameters

### `pCondition` [in]

Type: **[IUIAutomationCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcondition)***

A pointer to a condition that specifies the elements of interest.

### `walker` [out, retval]

Type: **[IUIAutomationTreeWalker](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtreewalker)****

Receives a pointer to the tree walker object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.