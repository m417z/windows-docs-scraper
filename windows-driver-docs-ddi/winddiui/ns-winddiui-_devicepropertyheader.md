## Description

The **DEVICEPROPERTYHEADER** structure is used as an input parameter to a printer interface DLL's [DrvDevicePropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdevicepropertysheets) function.

## Members

### `cbSize`

Size, in bytes, of the **DEVICEPROPERTYHEADER** structure.

### `Flags`

Is a set of flags that can be set to the following value:

| Value | Meaning |
|---|---|
| DPS_NOPERMISSION | If set, the user is not permitted to update device settings. |

### `hPrinter`

Printer handle.

### `pszPrinterName`

Pointer to a NULL-terminated string representing a printer name.