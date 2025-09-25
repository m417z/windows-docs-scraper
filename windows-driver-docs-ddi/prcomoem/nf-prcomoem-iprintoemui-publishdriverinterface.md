# IPrintOemUI::PublishDriverInterface

## Description

The `IPrintOemUI::PublishDriverInterface` method allows a user interface plug-in to obtain the Unidrv or Pscript5 driver's **IPrintOemDriverUI**, **IPrintCoreUI2**, **IPrintCoreHelperPS**, or **IPrintCoreHelperUni** interface.

## Parameters

### `pIUnknown`

Caller-supplied pointer to the **IUnknown** interface of the driver's [IPrintCoreUI2 COM Interface](https://learn.microsoft.com/windows-hardware/drivers/print/iprintcoreui2-com-interface), [IPrintOemDriverUI COM Interface](https://learn.microsoft.com/windows-hardware/drivers/print/iprintoemdriverui-com-interface), [IPrintCoreHelperPS Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcorehelperps), or [IPrintCoreHelperUni Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcorehelperuni). See Remarks.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |

## Remarks

The Pscript5 driver supports the **IPrintCoreUI2**, **IPrintOemDriverUI**, and **IPrintCoreHelperPS** interfaces. Unidrv supports the **IPrintOemDriverUI** and **IPrintCoreHelperUni** interfaces. User interface plug-ins for both types of driver must implement the `IPrintOemUI::PublishDriverInterface` method.

The method should return information on its supported Pscript5 interfaces as follows:

1. The Pscript5 driver first calls the `IPrintOemUI::PublishDriverInterface` method with the *pIUnknown* pointer set to the **IPrintCoreUI2** instance's **IUnknown** interface. If the user interface plug-in is able to use the **IPrintCoreUI2** interface, the method must return S_OK. Otherwise, the plug-in should return E_FAIL.
2. If the plug-in has returned E_FAIL, the Pscript5 driver calls the `IPrintOemUI::PublishDriverInterface` method again, but with the *pIUnknown* pointer set to the **IPrintOemDriverUI** instance's **IUnknown** interface. If the plug-in can use the **IPrintOemDriverUI** interface, the method must return S_OK. Otherwise, the plug-in should return E_FAIL.
3. If the plug-in's **IPrintOemUI::GetInfo** method has returned a value of OEMPUBLISH_IPRINTCOREHELPER in *pBuffer* in response to a call with *dwMode* set to OEMGI_GETREQUESTEDHELPERINTERFACES, the Pscript5 driver calls the `IPrintOemUI::PublishDriverInterface` method again, but with the *pIUnknown* pointer set to an object that implements the **IPrintCoreHelperPS** and **IPrintCoreHelper** interfaces. If the plug-in can use the **IPrintCoreHelperPS** or **IPrintCoreHelper** interface, the method should return S_OK. Otherwise, the method should return E_FAIL.

The method should return information on its supported Unidrv interfaces as follows:

1. The Unidrv driver first calls the `IPrintOemUI::PublishDriverInterface` method with the *pIUnknown* pointer set to the **IPrintOemDriverUI** instance's **IUnknown** interface. If the plug-in is able to use the **IPrintOemDriverUI** interface, the method must return S_OK. Otherwise, the plug-in should return E_FAIL.
2. If the plug-in's [IPrintOemUI::GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-getinfo) method has returned a value of OEMPUBLISH_IPRINTCOREHELPER in *pBuffer* in response to a call with *dwMode* set to OEMGI_GETREQUESTEDHELPERINTERFACES, the Unidrv driver calls the `IPrintOemUI::PublishDriverInterface` method again, but with the *pIUnknown* pointer set to an object that implements the **IPrintCoreHelperUni** and **IPrintCoreHelper** interfaces. If the plug-in uses the **IPrintCoreHelperUni** or **IPrintCoreHelper** interface, the method should return S_OK. Otherwise, the method should return E_FAIL.

If the plug-in fails all calls to `IPrintOemUI::PublishDriverInterface`, the plug-in will not receive further calls. If the user interface plug-in will be calling **IPrintCoreUI2**, **IPrintOemDriverUI**, **IPrintCoreHelperPS**, or **IPrintCoreHelperUni** interface methods, it must use the received **IUnknown** interface pointer to call **IUnknown::QueryInterface** (described in the Microsoft Windows SDK documentation) in order to obtain a pointer to the driver's supported version of the **IPrintCoreUI2**, **IPrintOemDriverUI**, **IPrintCoreHelperPS**, or **IPrintCoreHelperUni** interface. For more information, see [Interface Identifiers for Printer Drivers](https://learn.microsoft.com/windows-hardware/drivers/print/interface-identifiers-for-printer-drivers).

During processing of each DDI function, UI plug-ins should not mix the use of methods of the pre-Windows Vista interfaces (for example, the [IPrintOemDriverUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemdriverui) or [IPrintCoreUI2](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcoreui2) interface) and the new methods of the Windows Vista interfaces (for example, [IPrintCoreHelperUni](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcorehelperuni) or [IPrintCoreHelperPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcorehelperps)) to read or write driver settings. For example, during the [IPrintOemUI::DocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-documentpropertysheets) method, the UI plug-in should not use the [IPrintOemDriverUI::DrvUpdateUISetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriverui-drvupdateuisetting) method to write settings and use the [IPrintCoreHelper::GetOption](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcorehelper-getoption) method to read settings. For another example, during the [IPrintOemUI::PrinterEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-printerevent) method, the UI plug-in should not use the [IPrintCoreUI2::GetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcoreui2-getoptions) method to read settings and use the [IPrintCoreHelper::SetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcorehelper-setoptions) method to write settings. Synchronization of the reading and writing of settings is not supported between these different versions of interfaces.

## See also

[IPrintOemUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemui)

[IPrintOemUI::GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-getinfo)