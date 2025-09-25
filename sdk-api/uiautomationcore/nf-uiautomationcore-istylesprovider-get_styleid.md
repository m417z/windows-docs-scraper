# IStylesProvider::get_StyleId

## Description

Identifies the visual style of an element in a document.

This property is read-only.

## Parameters

## Remarks

A provider should use this property to expose style identifiers that are useful to client applications. For example, a provider might expose the [StyleId_Title](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-style-identifiers) identifier for an element that represents the title of a presentation. A screen reader could then retrieve the **StyleId** property, discover that the element is a presentation title, and read the title to the user.

### List Styles

IDs for list styles are supported starting with Windows 8.1.

These styles should be applied at a paragraph level; all text that is part of a list item should have one of these styles applied to it.

When bullet styles are mixed within a list, the **BulletedList** style should be applied to the whole range, and the [BulletStyle](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-bulletstyle) attribute value (property identified by **UIA_BulletStyleAttributeId**) should be mixed according to breakdown of different bullet types within the range.

When nested lists contain bullets also (perhaps of a different type than the main list), the **BulletedList** style would again be applied to the whole range, and the **BulletStyle** attribute value is whatever the nested bullet style is (for the range covering the nested list).

## See also

[BulletStyle](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-bulletstyle)

[IStylesProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-istylesprovider)

[UI Automation Support for Textual Content](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-ui-automation-textpattern-overview)