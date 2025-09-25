# PropSheet_RecalcPageSizes macro

## Syntax

```cpp
BOOL PropSheet_RecalcPageSizes(
   HWND hDlg
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Recalculates the page size of a standard or wizard property sheet after pages have been added or removed. You can use this macro or send the [PSM_RECALCPAGESIZES](https://learn.microsoft.com/windows/desktop/Controls/psm-recalcpagesizes) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the property sheet's dialog box.

## Remarks

When a property sheet is created, it is sized to fit its initial collection of pages. To maintain compatibility with previous versions of the common controls, property sheets and wizards do not automatically resize themselves when pages are subsequently added or removed. With common controls [version 5.80](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) and later, applications should use the **PropSheet_RecalcPageSizes** macro after adding or removing pages with [PropSheet_AddPage](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propsheet_addpage), [PropSheet_InsertPage](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propsheet_insertpage), [PropSheet_RemovePage](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propsheet_removepage), or their equivalent messages. It ensures that the property sheet is properly sized for its current collection of pages. If this macro or the equivalent message is not used, some property sheet pages may be truncated or too large.

**Note** This macro is not supported when using the Aero wizard style ([PSH_AEROWIZARD](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2)).