# SFV_SETITEMPOS structure

## Description

Stores position information for an item. Used with message [SFVM_SETITEMPOS](https://learn.microsoft.com/windows/desktop/shell/sfvm-setitempos).

## Members

### `pidl`

Type: **PCUITEMID_CHILD**

A pointer to an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) for the item.

### `pt`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

A [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure indicating the position of the item.