# IPrintOemUni::PublishDriverInterface

## Description

The `IPrintOemUni::PublishDriverInterface` method allows a rendering plug-in for Unidrv to obtain the Unidrv driver's **IPrintOemDriverUni** or **IPrintCoreHelperUni** interface.

## Parameters

### `pIUnknown`

Caller-supplied pointer to the **IUnknown** interface of the driver's [IPrintOemDriverUni COM Interface](https://learn.microsoft.com/windows-hardware/drivers/print/iprintoemdriveruni-com-interface) or [IPrintCoreHelperUni interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcorehelperuni).

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |

## Remarks

A rendering plug-in for [Unidrv](https://learn.microsoft.com/windows-hardware/drivers/) must implement the `IPrintOemUni::PublishDriverInterface` method, and the method must return S_OK in response to at least one call. Otherwise, the driver will not call the plug-in's other **IPrintOemUni** interface methods.

The method should return information on its supported Unidrv interfaces as follows:

1. The Unidrv driver first calls the `IPrintOemUI::PublishDriverInterface` method with the *pIUnknown* pointer set to the **IPrintOemDriverUni** instance's **IUnknown** interface. If the rendering plug-in will be calling **IPrintOemDriverUni** interface methods, it must use the received **IUnknown** interface pointer to call **IUnknown::QueryInterface** (described in the Microsoft Windows SDK documentation) in order to obtain a pointer to the driver's supported version of the **IPrintOemDriverUni** interface. For more information, see [Interface Identifiers for Printer Drivers](https://learn.microsoft.com/windows-hardware/drivers/print/interface-identifiers-for-printer-drivers).
2. If the plug-in's [IPrintOemUni::GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-getinfo) method has returned a value of OEMPUBLISH_IPRINTCOREHELPER in *pBuffer* in response to a call with *dwMode* set to OEMGI_GETREQUESTEDHELPERINTERFACES, the Unidrv driver calls the `IPrintOemUni::PublishDriverInterface` method again, but with the *pIUnknown* pointer set to an object that implements the **IPrintCoreHelperUni** and **IPrintCoreHelper** interfaces. If the plug-in retains a pointer to the object, the method should return S_OK. Otherwise, the method should return E_FAIL.

## See also

[IPrintOemUni](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemuni)

[IPrintOemUni::GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-getinfo)