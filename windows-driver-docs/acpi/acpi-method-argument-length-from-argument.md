# ACPI_METHOD_ARGUMENT_LENGTH_FROM_ARGUMENT macro

The ACPI_METHOD_ARGUMENT_LENGTH_FROM_ARGUMENT macro calculates the size, in bytes, of the data that is contained in the Data array of an [**ACPI_METHOD_ARGUMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_method_argument_v1) structure.

## Parameters

*Argument*
A pointer to an **ACPI_METHOD_ARGUMENT** structure.

## Return value

The size, in bytes, of the data that is contained in the **Data** array of the **ACPI_METHOD_ARGUMENT** structure that *Argument* points to.

## Remarks

A driver can use this macro to determine the size, in bytes, of the data in the **Data** array of an **ACPI_METHOD_ARGUMENT** structure.

## Requirements

**Target platform:** Desktop

**Header:** acpiioct.h (include Acpiioct.h)

## See also

[**ACPI_METHOD_ARGUMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_method_argument_v1)