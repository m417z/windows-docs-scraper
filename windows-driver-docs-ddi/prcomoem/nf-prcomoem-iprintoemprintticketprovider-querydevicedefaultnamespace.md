## Description

The **IPrintOemPrintTicketProvider::QueryDeviceDefaultNamespace** method queries the device for its default namespace uniform resource identifier (URI).

## Parameters

### `pbstrNamespaceUri` [out]

A pointer to a BSTR that receives the namespace URI. The plug-in places the namespace URI in the buffer that is pointed to by *pbstrNamespaceUri*. **IPrintOemPrintTicketProvider::QueryDeviceDefaultNamespace** is responsible for allocating the string by means of a call to **SysAllocString** (described in the Microsoft Windows SDK documentation), but the caller is responsible for freeing the string.

## Return value

**IPrintOemPrintTicketProvider::QueryDeviceDefaultNamespace** should return one of the following values.

| Return code | Description |
|--|--|
| **S_OK** | The operation succeeded. |
| **E_NOTIMPL** | The plug-in does not intend to override the default namespace that the core driver generated from the plug-in's provider. |

## Remarks

The plug-in should specify the name of the private namespace URI that the core driver should use to handle any features that are defined in the GPD file or PPD file that the core driver does not recognize. The plug-in might specify a set of namespaces as a result of the call to the [IPrintOemPrintTicketProvider::BindPrinter](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemprintticketprovider-bindprinter) method. The purpose of the **IPrintOemPrintTicketProvider::QueryDeviceDefaultNamespace** is to inform the core driver about which of these namespaces is to be used as the default namespace. The core driver associates all of the features that it does not recognize with this default namespace, and places any such features in the print ticket.

When **IPrintOemPrintTicketProvider::QueryDeviceDefaultNamespace** returns, the core driver is responsible for adding the private namespace URI that the plug-in has specified (in **pbstrNamespaceUri*) to the root node of the DOM document. The core driver also must define a prefix for the private namespace that the plug-in should use when the plug-in adds a new node to the print ticket under the plug-in's private namespace. The plug-in should not define its own prefix for this default private namespace URI.

## See also

[IPrintOemPrintTicketProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemprintticketprovider)

[IPrintOemPrintTicketProvider::BindPrinter](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemprintticketprovider-bindprinter)