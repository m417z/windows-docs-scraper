# CreatePropertySheetPageA function

## Description

Creates a new page for a property sheet.

## Parameters

### `constPropSheetPagePointer`

Type: **LPCPROPSHEETPAGE**

Pointer to a [PROPSHEETPAGE](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetpagea_v2) structure that defines a page to be included in a property sheet.

## Return value

Type: **HPROPSHEETPAGE**

Returns the handle to the new property page if successful, or **NULL** otherwise.

## Remarks

**Note** Before common controls version 7.0, this function did not support visual styles.

An application uses the [PropertySheet](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propertysheeta) function to create a property sheet that includes the new page. If you are not using the Aero wizard style ([PSH_AEROWIZARD](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2)), the application can use the [PSM_ADDPAGE](https://learn.microsoft.com/windows/desktop/Controls/psm-addpage) message to add the new page to an existing property sheet.

Windows 95: The system can support a maximum of 16,364 window handles.

> [!NOTE]
> The prsht.h header defines CreatePropertySheetPage as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).