# IPrintOemPS::PublishDriverInterface

## Description

The `IPrintOemPS::PublishDriverInterface` method allows a rendering plug-in for Pscript5 to obtain the Pscript5 driver's **IPrintCorePS2**, **IPrintOemDriverPS**, or **IPrintCoreHelperPS** interface.

## Parameters

### `pIUnknown`

Caller-supplied pointer to the **IUnknown** interface of the driver's [IPrintCorePS2 COM Interface](https://learn.microsoft.com/windows-hardware/drivers/print/iprintcoreps2-com-interface), [IPrintOemDriverPS COM Interface](https://learn.microsoft.com/windows-hardware/drivers/print/iprintoemdriverps-com-interface), or [IPrintCoreHelperPS Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcorehelperps).

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed |

## Remarks

The Pscript5 driver supports the **IPrintCorePS2**, **IPrintOemDriverPS**, and **IPrintCoreHelperPS** interfaces. A rendering plug-in for Pscript5 must implement the `IPrintOemPS::PublishDriverInterface` method. The method should return information on its supported Pscript5 interfaces as follows:

1. The Pscript5 driver first calls the `IPrintOemPS::PublishDriverInterface` method with the *pIUnknown* pointer set to the **IPrintCorePS2** instance's **IUnknown** interface. If the rendering plug-in is able to use the **IPrintCorePS2** interface, the method must return S_OK. Otherwise, the plug-in should return E_FAIL.
2. If the plug-in has returned E_FAIL, the Pscript5 driver calls the `IPrintOemPS::PublishDriverInterface` method again, but with the *pIUnknown* pointer set to the **IPrintOemDriverPS** instance's **IUnknown** interface. If the plug-in is able to use the **IPrintOemDriverPS** interface, the method must return S_OK. Otherwise, the plug-in should return E_FAIL.
3. If the plug-in's [IPrintOemPS::GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps-getinfo) method has returned a value of OEMPUBLISH_IPRINTCOREHELPER in *pBuffer* in response to a call with *dwMode* set to OEMGI_GETREQUESTEDHELPERINTERFACES in *pBuffer*, the Pscript5 driver calls the `IPrintOemPS::PublishDriverInterface` method again, but with the *pIUnknown* pointer set to an object that implements the **IPrintCoreHelperPS** and **IPrintCoreHelper** interfaces. If the plug-in retains a pointer to the object interface, the method should return S_OK. Otherwise, the method should return E_FAIL.

If the plug-in fails all calls to `IPrintOemPS::PublishDriverInterface`, the plug-in will not receive further calls. If the plug-in will be calling **IPrintCorePS2**, **IPrintOemDriverPS**, or **IPrintCoreHelperPS** interface methods, it must use the received **IUnknown** interface pointer to call **IUnknown::QueryInterface** (described in the Microsoft Windows SDK documentation) in order to obtain a pointer to the driver's supported version of the **IPrintCorePS2**, **IPrintOemDriverPS**, or **IPrintCoreHelperPS** interface. For more information, see [Accessing Printer Driver Interfaces from Plug-Ins](https://learn.microsoft.com/windows-hardware/drivers/print/accessing-printer-driver-interfaces-from-plug-ins).

## See also

[IPrintOemPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemps)

[IPrintOemPS::GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps-getinfo)