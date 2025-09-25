# _ACPI_GET_DEVICE_SPECIFIC_DATA structure

## Description

The ACPI_GET_DEVICE_SPECIFIC_DATA structure contains input arguments for the IOCTL_ACPI_GET_DEVICE_SPECIFIC_DATA control method.

## Members

### `Signature`

A unique identifier for the IOCTL.

### `Section`

A GUID specified by the caller.

### `PropertyNameLength`

The length of the property name.

### `PropertyName`

Specifies the property name. If not specified, the **PropertyNameLength** and the **PropertyName** are returned. If a **PropertyName** is specified, only the value of that **PropertyName** is returned.