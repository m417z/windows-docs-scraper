## Description

The **IPrintTicketProvider2::GetPrintCapabilities** method queries the provider for a complete print capabilities document that describes the printer's features and parameters.

## Parameters

### `pPrintTicket` [in]

A pointer to the print ticket. The settings of the print ticket constrain the device capabilities.

### `ppCapabilities` [out]

A pointer to a variable that receives the address of the device capabilities document.

## Return value

**IPrintTicketProvider2::GetPrintCapabilities** should return **S_OK** if the operation succeeds. Otherwise, this method should return a standard COM error code.

## Remarks

The input print ticket should be used to determine and describe constraints on the settings in the output print capabilities document. No features, options, and parameters that are described in the output print capabilities document should change because of the contents of the input print ticket. Only the constraint status of the features, options, and parameters are subject to change.

## See also