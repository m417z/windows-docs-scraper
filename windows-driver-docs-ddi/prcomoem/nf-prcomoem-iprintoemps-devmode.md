# IPrintOemPS::DevMode

## Description

The `IPrintOemPS::DevMode` method, provided by rendering plug-ins for Pscript5, performs operations on private [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) members.

## Parameters

### `dwMode`

Caller-supplied constant. See the following Remarks section.

### `pOemDMParam`

Caller-supplied pointer to an [OEMDMPARAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemdmparam) structure.

## Return value

This method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

If you are providing a user interface plug-in for Pscript5, and if you are adding private members to the driver's DEVMODEW structure, you must implement both the `IPrintOemUI::DevMode` and the `IPrintOemPS::DevMode` methods. The code implementing these methods must be identical and can be placed in a library that is statically linked to both the UI plug-in and the rendering plug-in.

For a description of the `IPrintOemPS::DevMode` method, see [IPrintOemUI::DevMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-devmode).