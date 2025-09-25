# LPFNPSPCALLBACKA callback function

## Description

Specifies an application-defined callback function that a property sheet calls when a page is created and when it is about to be destroyed. An application can use this function to perform initialization and cleanup operations for the page.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Reserved; must be **NULL**.

### `uMsg` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Action flag. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PSPCB_ADDREF** | [Version 5.80](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) or later. A page is being created. The return value is not used. |
| **PSPCB_CREATE** | A dialog box for a page is being created. Return nonzero to allow it to be created, or zero to prevent it. |
| **PSPCB_RELEASE** | A page is being destroyed. The return value is ignored. |

### `ppsp` [in, out]

Type: **LPPROPSHEETPAGE**

Pointer to a [PROPSHEETPAGE](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetpagea_v2) structure that defines the page being created or destroyed. See the Remarks section for further discussion.

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The return value depends on the value of the *uMsg* parameter.

## Remarks

An application must specify the address of this callback function in the **pfnCallback** member of a [PROPSHEETPAGE](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetpagea_v2) structure before passing the structure to the [CreatePropertySheetPage](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-createpropertysheetpagea) function.

**Note** The property sheet is in the process of manipulating the list of pages when this function is called. Do not attempt to add, remove, or insert pages while handling this notification. Doing so will have unpredictable results.

With the exception of the **lParam** member, your application should not modify the [PROPSHEETPAGE](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetpagea_v2) structure. Doing so will have unpredictable results. The **lParam** member contains application-defined data and can be modified as needed.

> [!NOTE]
> The prsht.h header defines LPFNPSPCALLBACK as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).