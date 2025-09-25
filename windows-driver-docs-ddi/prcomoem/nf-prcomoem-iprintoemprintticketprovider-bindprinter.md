## Description

The **IPrintOemPrintTicketProvider::BindPrinter** method enables the core driver to associate a set of private namespace uniform resource identifiers (URIs) with a device. This method also allows the plug-in to cache information (such as the printer handle) that can be used at a later time.

## Parameters

### `hPrinter` [in]

The spooler's print handle, which is supplied by Unidrv. The provider should not close this handle at any time, because the client of the provider is responsible for managing the lifetime of this handle. The provider can cache the print handle; all future calls on this object are relative to the printer that is associated with this handle.

### `version` [in]

The major version number of the print schema. Windows Vista supports only version 1.

### `pOptions` [out]

A pointer to a variable that receives one of the following enumerated values:

#### OEMPT_DEFAULT

The system places a binary encoding (a binary large object [BLOB]) of the private [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure into the print ticket in a conversion of a DEVMODEW to a print ticket.

#### OEMPT_NOSNAPSHOT

The system will not place a binary encoding (a BLOB) of the private DEVMODEW structure into the print ticket in a conversion of a DEVMODEW to a print ticket. Use this value if all of the public and private DEVMODEW members are fully represented in the print ticket.

The OEM object that is being called should set the value pointed to by this parameter.

### `cNamespaces` [out]

A pointer to a variable that receives the number of private namespace URIs that are used in the plug-in. This number represents the count of strings in the array that is pointed to by **ppNamespaces*.

### `ppNamespaces` [out]

A pointer to a variable that receives the address of the first element of a BSTR array. The plug-in fills each array position with a namespace URI. For more information about this parameter, see the following Remarks section.

## Return value

**IPrintOemPrintTicketProvider::BindPrinter** should return one of the following values.

| Return code | Description |
|--|--|
| **S_OK** | The operation succeeded. |
| **E_VERSION_NOT_SUPPORTED** | The plug-in does not support the version of the print schema that is specified in the *version* parameter. |

## Remarks

The plug-in is responsible for allocating memory for the array that is pointed to by the *ppNamespaces* parameter and for the namespace URI strings. The array should be allocated by using the **CoTaskMemAlloc** function; the namespace strings should be allocated by using the **SysAllocString** function. Both of these functions are described in the Microsoft Windows SDK documentation. The array that is pointed to by the *ppNamespaces* parameter is not required to contain the namespaces for the Print Schema Keywords or the Print Schema Framework.

Binding to a device enables the provider to cache certain objects and handles that it will need for future print ticket or print capabilities services on that device. For example, the printer handle in *hPrinter* can be cached. **IPrintOemPrintTicketProvider::BindPrinter** is guaranteed to be called only once.

An **IPrintOemPrintTicketProvider** object does not have to be able to bind more than once. The print ticket manager always uses different **IPrintOemPrintTicketProvider** object instances for binding to different devices. All resources that are acquired in a successful call to **IPrintOemPrintTicketProvider::BindPrinter** should be released when the reference count of an **IPrintOemPrintTicketProvider** object is zero. (Note that the provider should not close the handle that was passed into the call to **BindPrinter**). The print ticket manager might create multiple providers for the same device, in different versions, if multiple versions are supported.

## See also

[IPrintOemPrintTicketProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemprintticketprovider)

[IPrintOemPrintTicketProvider::ConvertDevModeToPrintTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemprintticketprovider-convertdevmodetoprintticket)

[IPrintOemPrintTicketProvider::ConvertPrintTicketToDevMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemprintticketprovider-convertprinttickettodevmode)

[IPrintOemPrintTicketProvider::GetSupportedVersions](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemprintticketprovider-getsupportedversions)