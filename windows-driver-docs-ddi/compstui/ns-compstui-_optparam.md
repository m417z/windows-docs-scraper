## Description

An array of **OPTPARAM** structures is used by CPSUI applications (including printer interface DLLs) for describing all the parameter values associated with a [property sheet option](https://learn.microsoft.com/windows-hardware/drivers/print/property-sheet-options). The array's address is included in an [**OPTTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_opttype) structure.

## Members

### `cbSize`

Size, in bytes, of the **OPTPARAM** structure.

### `Flags`

Optional bit flags that modify the parameter's characteristics. The following flags can be set in any combination:

#### OPTPF_DISABLED

If set, the parameter is not user-selectable. Can be used with the following option types:

[TVOT_2STATES](https://learn.microsoft.com/windows-hardware/drivers/print/tvot-2states)

[TVOT_3STATES](https://learn.microsoft.com/windows-hardware/drivers/print/tvot-3states)

[TVOT_COMBOBOX](https://learn.microsoft.com/windows-hardware/drivers/print/tvot-combobox)

[TVOT_LISTBOX](https://learn.microsoft.com/windows-hardware/drivers/print/tvot-listbox)

#### OPTPF_HIDE

If set, the parameter not displayed in the treeview. Can be used with the following option types:

[TVOT_3STATES](https://learn.microsoft.com/windows-hardware/drivers/print/tvot-3states)

[TVOT_COMBOBOX](https://learn.microsoft.com/windows-hardware/drivers/print/tvot-combobox)

[TVOT_LISTBOX](https://learn.microsoft.com/windows-hardware/drivers/print/tvot-listbox)

#### OPTPF_ICONID_AS_HICON

If set, the **IconID** member contains an icon handle.

If not set, the **IconID** member contains an icon resource identifier.

#### OPTPF_OVERLAY_NO_ICON

If set, CPSUI overlays its IDI_CPSUI_NO icon onto the icon identified by the **IconID** member.

#### OPTPF_OVERLAY_STOP_ICON

If set, CPSUI overlays the IDI_CPSUI_STOP icon onto the icon identified by the **IconID** member.

#### OPTPF_OVERLAY_WARNING_ICON

If set, CPSUI overlays its IDI_CPSUI_WARNING icon onto the icon identified by the **IconID** member.

#### OPTPF_USE_HDLGTEMPLATE

If set, **lParam** contains a template handle.

If not set, **lParam** contains a template resource identifier.

(Used only if **Style** is PUSHBUTTON_TYPE_DLGPROC.)

### `Style`

Push button style, used only for the [TVOT_PUSHBUTTON](https://learn.microsoft.com/windows-hardware/drivers/print/tvot-pushbutton) option type.

### `pData`

Pointer to the parameter's value. Use of this member is dependent on the [CPSUI option type](https://learn.microsoft.com/windows-hardware/drivers/print/cpsui-option-types).

### `IconID`

Usually identifies the icon to be associated with the option parameter, but is sometimes used for other purposes. Use of this member is dependent on the [CPSUI option type](https://learn.microsoft.com/windows-hardware/drivers/print/cpsui-option-types).

### `lParam`

Use of this member is dependent on the [CPSUI option type](https://learn.microsoft.com/windows-hardware/drivers/print/cpsui-option-types).

### `dwReserved`

Reserved, must be initialized to zero.

## Remarks

If the OPTPF_HIDE flag is set in all the **OPTPARAM** structures associated with an option, CPSUI hides the entire option.