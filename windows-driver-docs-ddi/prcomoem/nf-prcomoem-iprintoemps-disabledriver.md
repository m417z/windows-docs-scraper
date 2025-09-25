# IPrintOemPS::DisableDriver

## Description

The `IPrintOemPS::DisableDriver` method allows a rendering plug-in for [Pscript](https://learn.microsoft.com/windows-hardware/drivers/) to free resources that were allocated by the plug-in's [IPrintOemPS::EnableDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps-enabledriver) method.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

The `IPrintOemPS::DisableDriver` method, provided by rendering plug-ins for Pscript5, performs the same types of operations as the [DrvDisableDriver](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvdisabledriver) function that is exported by Pscript5's printer graphics DLL.

`IPrintOemPS::DisableDriver` and **IPrintOemPS::EnableDriver** must be implemented as a pair. If you implement one, you must implement the other. For more information, see the Remarks section in [IPrintOemPS::EnableDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps-enabledriver).

This is the last **IPrintOemPS** interface method that is called before the rendering plug-in is unloaded.