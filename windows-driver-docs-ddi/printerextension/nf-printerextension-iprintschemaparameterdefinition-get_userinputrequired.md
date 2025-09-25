## Description

The **UserInputRequired** property gets the Boolean value that indicates whether or not a user input value is required for the Print Schema parameter.

This property is read-only.

## Parameters

### `pbIsRequired`

Defines the **BOOL** parameter *pbIsRequired*.

## Return value

Returns an **HRESULT** value. If the property call was not successful, it returns the appropriate **HRESULT** error code.

## Remarks

The print dialog can use **UserInputRequired** to determine whether or not it should force the user to enter a valid value for the parameter, before it allows printing to proceed.

## See also

[IPrintSchemaParameterDefinition](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemaparameterdefinition)