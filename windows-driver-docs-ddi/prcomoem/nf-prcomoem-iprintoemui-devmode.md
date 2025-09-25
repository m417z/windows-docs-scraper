# IPrintOemUI::DevMode

## Description

The `IPrintOemUI::DevMode` method, provided by user interface plug-ins, performs operations on the plug-in's private DEVMODEW members.

## Parameters

### `dwMode`

Caller-supplied constant. See the following Remarks section.

### `pOemDMParam`

Caller-supplied pointer to an [OEMDMPARAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemdmparam) structure.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

User interface plug-ins must implement a `IPrintOemUI::DevMode` method if they define private [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure members. The method's purpose is to define, validate, or convert (from one version to another) the contents of the private DEVMODEW structure members.

A private DEVMODEW section must be prefaced by a [OEM_DMEXTRAHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oem_dmextraheader) structure.

The `IPrintOemUI::DevMode` method must perform the operation indicated by its *dwMode* value. Each time `IPrintOemUI::DevMode` is called, *dwMode* contains one of the following constants, which are listed in the order they are received:

## See also

[IPrintOemPS::DevMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps-devmode)

[IPrintOemUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemui)

[IPrintOemUni::DevMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-devmode)