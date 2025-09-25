## Description

The **OPTTYPE** structure is used by CPSUI applications (including printer interface DLLs) for describing the type and other characteristics of a [property sheet option](https://learn.microsoft.com/windows-hardware/drivers/print/property-sheet-options), if the option is specified by an [**OPTITEM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_optitem) structure.

## Members

### `cbSize`

Size, in bytes, of the **OPTTYPE** structure.

### `Type`

Specifies the [CPSUI option type](https://learn.microsoft.com/windows-hardware/drivers/print/cpsui-option-types).

### `Flags`

Optional bit flags that modify the option's characteristics. The following flags can be set in any combination.

#### OPTTF_NOSPACE_BEFORE_POSTFIX

CPSUI should not add a space character between the string specified by the [**OPTITEM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_optitem) structure's **pName** string and the [**OPTPARAM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_optparam) structure's **pData** string, when displaying the option.

Valid only if the option type is or [TVOT_SCROLLBAR](https://learn.microsoft.com/windows-hardware/drivers/print/tvot-scrollbar) or [TVOT_TRACKBAR](https://learn.microsoft.com/windows-hardware/drivers/print/tvot-trackbar).

#### OPTTF_TYPE_DISABLED

All the **OPTPARAM** structures to which **pOptParam** points are disabled, so that none of the parameter values are user-selectable.

### `Count`

Specifies the number of [**OPTPARAM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_optparam) structures to which **pOptParam** points. This member's value is dependent on the [CPSUI option type](https://learn.microsoft.com/windows-hardware/drivers/print/cpsui-option-types).

### `BegCtrlID`

If **pDlgPage** in [**COMPROPSHEETUI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_compropsheetui) identifies a CPSUI-supplied page, or if **DlgTemplateID** in [**DLGPAGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_dlgpage) identifies a CPSUI-supplied template, **BegCtrlID** is not used.

Otherwise, **BegCtrlID** must contain the first of a sequentially numbered set of Windows control identifiers. Control identifier usage is dependent on the [CPSUI option type](https://learn.microsoft.com/windows-hardware/drivers/print/cpsui-option-types).

### `pOptParam`

Pointer to an array of [**OPTPARAM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_optparam) structures describing the parameter values that a user can select for the option.

### `Style`

Specifies flags that can be used to modify the option's display characteristics. The flags that can be specified are dependent on the [CPSUI option type](https://learn.microsoft.com/windows-hardware/drivers/print/cpsui-option-types).

### `wReserved`

Reserved, must be initialized to zero.

### `dwReserved`

Reserved, must be initialized to zero.