# UiaRectIsEmpty function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Gets a Boolean value that specifies whether a rectangle has all its coordinates set to 0.

## Parameters

### `rc` [in, ref]

Type: **const [UiaRect](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ns-uiautomationcore-uiarect)**

A reference to a [UiaRect](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ns-uiautomationcore-uiarect) structure that contains the coordinates of the rectangle.

## Return value

Type: **bool**

**TRUE** if the rectangle is empty; otherwise **FALSE**.