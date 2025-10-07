# ACPI_METHOD_ARGUMENT_LENGTH macro

The ACPI_METHOD_ARGUMENT_LENGTH macro calculates the size, in bytes, of a variable-length [**ACPI_METHOD_ARGUMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_method_argument_v1) structure that contains data of a specified size, in bytes.

## Parameters

*DataLength*
The size, in bytes, of data in the **Data** array of an **ACPI_METHOD_ARGUMENT** structure.

## Return value

The size, in bytes, of a variable-length **ACPI_METHOD_ARGUMENT** structure that can contains a **Data** array whose size, in bytes, is *DataLength*.

## Remarks

A driver can use this macro to calculate the required size, in bytes, of a variable-length **ACPI_METHOD_ARGUMENT** structure that can contain a **Data** array of a specified size, in bytes.

## Requirements

**Target platform:** Desktop

**Header:** acpiioct.h (include Acpiioct.h)

## See also

[**ACPI_METHOD_ARGUMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_method_argument_v1)