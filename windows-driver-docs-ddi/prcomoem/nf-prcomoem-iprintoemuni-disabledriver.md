# IPrintOemUni::DisableDriver

## Description

The `IPrintOemuNI::DisableDriver` method allows a rendering plug-in for [Unidrv](https://learn.microsoft.com/windows-hardware/drivers/) to free resources that were allocated by the plug-in's [IPrintOemUni::EnableDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-enabledriver) method.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed |

## Remarks

A rendering plug-in for Unidrv must implement the `IPrintOemUni::DisableDriver` method.

The `IPrintOemUni::DisableDriver` method, provided by rendering plug-ins for Unidrv, performs the same types of operations as the [DrvDisableDriver](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvdisabledriver) function that is exported by Unidrv's printer graphics DLL.

`IPrintOemUni::DisableDriver` and **IPrintOemUni::EnableDriver** must be implemented as a pair. If you implement one, you must implement the other. For more information, see the Remarks section in [IPrintOemUni::EnableDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-enabledriver).

This is the last **IPrintOemUni** interface method that is called before the rendering plug-in is unloaded.