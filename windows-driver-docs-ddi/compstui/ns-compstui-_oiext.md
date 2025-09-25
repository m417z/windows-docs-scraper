## Description

The **OIEXT** structure supplies additional, optional information about a property sheet page option that is described by an [OPTITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_optitem) structure.

## Members

### `cbSize`

Size, in bytes, of the **OIEXT** structure.

### `Flags`

Can contain the following bit flag:

| Flag | Description |
|---|---|
| OIEXTF_ANSI_STRING | If set, **pHelpFile** points to an ANSI string. If not set, **pHelpFile** points to a Unicode string. CPSUI does not check this flag if **pHelpFile** specifies a resource ID. |

### `hInstCaller`

Instance handle to a DLL containing string and icon resources belonging to the [OPTITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_optitem), [**OPTTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_opttype), and [**OPTPARAM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_optparam) structures associated with the OIEXT structure. If **NULL**, CPSUI obtains resources from the DLL identified by the **hInstCaller** member of a [**COMPROPSHEETUI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_compropsheetui) structure.

### `pHelpFile`

Pointer to a NULL-terminated string representing a path to a help file containing help information for the option. This can be a 32-bit pointer to a NULL-terminated string, or it can be a 16-bit string resource identifier with HIWORD set to zero. If **NULL**, CPSUI uses the help file identified by the **pHelpFile** member of a [**COMPROPSHEETUI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_compropsheetui) structure.

### `dwReserved`

Reserved, must be initialized to zero.