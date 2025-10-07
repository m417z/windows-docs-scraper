# ACPI_METHOD_SET_ARGUMENT_BUFFER macro

The ACPI_METHOD_SET_ARGUMENT_BUFFER macro sets the members of an [**ACPI_METHOD_ARGUMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_method_argument_v1) structure for custom data that is supplied in a data buffer.

## Parameters

*Argument*
A pointer to an **ACPI_METHOD_ARGUMENT** structure.

*BuffData*
A pointer to a data buffer that contains custom data.

*BuffLength*
The size, in bytes, of the custom data.

## Return value

This macro does not return a value.

## Remarks

A driver can use this macro to set the members of an **ACPI_METHOD_ARGUMENT** structure that supplies custom data.

## Requirements

**Target platform:** Desktop

**Header:** acpiioct.h (include Acpiioct.h)

## See also

[**ACPI_METHOD_ARGUMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_method_argument_v1)