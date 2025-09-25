# _PEP_ACPI_RESOURCE_FLAGS structure (pep_x.h)

## Description

> [!NOTE]
> Microsoft supports a diverse and inclusionary environment. This article contains references to terminology that the Microsoft [Style Guide for Bias-Free Communications](https://learn.microsoft.com/style-guide/bias-free-communication) recognizes as exclusionary. The word or phrase is used in this article for consistency because it currently appears in the software. When the software is updated to remove the language, this article will be updated to be in alignment.

The **PEP_ACPI_RESOURCE_FLAGS** structure contains flags describing an ACPI resource.

## Members

### `AsULong`

The consolidated values of the flags in **DUMMYSTRUCTNAME**.

### `DUMMYSTRUCTNAME`

 A structure containing ACPI resource flags.

### `DUMMYSTRUCTNAME.Shared`

When set, indicates that this is a shared device.

### `DUMMYSTRUCTNAME.Wake`

When set, indicates that this device can be woken from a low-power state.

### `DUMMYSTRUCTNAME.ResourceUsage`

When set, indicates that this device is in use.

### `DUMMYSTRUCTNAME.SlaveMode`

When set, indicates that this device is in slave mode.

### `DUMMYSTRUCTNAME.AddressingMode`

When set, indicates that this device is in addressing mode.

### `DUMMYSTRUCTNAME.SharedMode`

When set, indicates that this device is in shared mode.

### `DUMMYSTRUCTNAME.Reserved`

This member is reserved and should be set to zero.