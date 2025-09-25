# IPrintOemUni::DevMode

## Description

The `IPrintOemUni::DevMode` method, provided by rendering plug-ins for Unidrv, performs operations on private [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) members.

## Parameters

### `dwMode`

Specifies a caller-supplied constant. See the Remarks section for more information.

### `pOemDMParam`

Caller-supplied pointer to an [OEMDMPARAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemdmparam) structure.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed |

## Remarks

A rendering plug-in for Unidrv must implement the `IPrintOemUni::DevMode` method.

If you are providing a user interface plug-in for Unidrv, and if you are adding private members to the driver's [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure, you must implement both the `IPrintOemUI::DevMode` and the `IPrintOemUni::DevMode` methods. The code implementing these methods must be identical and can be placed in a library that is statically linked to both the UI plug-in and the rendering plug-in.

The `IPrintOemUni::DevMode` method must perform the operation indicated by its *dwMode* value. Each time `IPrintOemUni::DevMode` is called, *dwMode* contains one of the following constants, which are listed in the order they are received:

## See also

[IPrintOemUI::DevMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-devmode)

[IPrintOemUni](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemuni)