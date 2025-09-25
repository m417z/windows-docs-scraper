## Description

The **IPrintTicketProvider::QueryDeviceNamespace** method queries the device for its default namespace uniform resource identifier (URI).

## Parameters

### `pDefaultNamespace` [out]

A pointer to a BSTR that receives the namespace URI. The driver places the namespace URI in the buffer that is pointed to by *pDefaultNamespace*.

**IPrintTicketProvider::QueryDeviceNamespace** is responsible for allocating the string by means of a call to **SysAllocString** (described in the Microsoft Windows SDK documentation), but the caller is responsible for freeing the string.

## Return value

**IPrintTicketProvider::QueryDeviceNamespace** should return **S_OK** if the operation succeeds and **E_FAIL** otherwise.