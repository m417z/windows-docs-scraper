# TreeTraversalOptions enumeration

## Description

Defines values that can be used to customize tree navigation order.

## Constants

### `TreeTraversalOptions_Default:0`

Pre-order,
visit children from first to last.

### `TreeTraversalOptions_PostOrder:0x1`

Post-order, see Remarks for more info.

### `TreeTraversalOptions_LastToFirstOrder:0x2`

Visit children from last to first.

## Remarks

Option groups (flags):

* Traversal order (pre-order, post-order) defines when nodes should be tested
  against search conditions. For example, "on enter" or "on leave".
* Visit order defines in which order relatives are visited. Relatives include
  children and siblings. Visit orders are relative to parents. From the child
  perspective First-to-Last means "visit the next sibling from the child" while
  Last-to-First means "visit the previous sibling from the child".

## See also

[Text Attribute Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-textattribute-ids)