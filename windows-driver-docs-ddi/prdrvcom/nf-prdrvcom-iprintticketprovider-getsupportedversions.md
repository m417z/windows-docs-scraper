## Description

The **IPrintTicketProvider::GetSupportedVersions** method retrieves major version numbers of the print schemas that are supported by the plug-in provider.

## Parameters

### `hPrinter` [in]

A handle to the print device.

### `ppVersions` [out]

A pointer to a variable that receives the address of the first element of an array of version numbers. Version numbers in the array can appear in any order. For more information about this parameter, see the following Remarks section.

### `cVersions` [out]

A pointer to a variable that receives the number of elements in the array that is pointed to by *ppVersions*.

## Return value

**IPrintTicketProvider::GetSupportedVersions** should return **S_OK** if the operation succeeds. If this method fails because of lack of memory or other resources, it should return a standard COM error code.

## Remarks

**IPrintTicketProvider::GetSupportedVersions** returns the major version numbers of the print schemas that are supported by the provider interface. The only currently defined version number is 1. Providers can omit intermediate versions.

The plug-in is responsible for allocating the array memory that is pointed to by the *ppVersions* parameter. The plug-in should allocate this memory by using the **CoTaskMemAlloc** function described in the Microsoft Windows SDK documentation, but the plug-in is not responsible for freeing this memory.

Because **IPrintTicketProvider::GetSupportedVersions** can be called before the **IPrintTicketProvider::BindPrinter** method is called, the OEM plug-in provider must check version support based on the handle that is passed in the *hPrinter* parameter. As a result, the OEM plug-in provider should not close the printer handle that is associated with *hPrinter*.

## See also

[IPrintTicketProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/prdrvcom/nn-prdrvcom-iprintticketprovider)

[IPrintTicketProvider::BindPrinter](https://learn.microsoft.com/windows-hardware/drivers/ddi/prdrvcom/nf-prdrvcom-iprintticketprovider-bindprinter)