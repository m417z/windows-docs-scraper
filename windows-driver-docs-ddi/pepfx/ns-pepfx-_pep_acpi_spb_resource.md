# _PEP_ACPI_SPB_RESOURCE structure (pepfx.h)

## Description

The **PEP_ACPI_SPB_RESOURCE** structure describes an ACPI serial bus connection resource.

## Members

### `Type`

A [PEP_ACPI_RESOURCE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_pep_acpi_resource_type) enumeration value describing this resource.

### `Flags`

A [PEP_ACPI_RESOURCE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_resource_flags) structure that describes the capabilities of this ACPI resource.

### `TypeSpecificFlags`

Specifies the bit flags that are common to all serial bus connection types.

| Bit(s) | Meaning |
| --- | --- |
| **0 - Subordinate mode** | **0x0** - Indicates that communication over this connection is initiated by the controller.<br><br>**0x1** - Indicates that communication over this connection is initiated by the device. |
| **1 - Consumer/producer mode** | **0x0** - Indicates that this device produces and consumes this resource.<br><br>**0x1** - Indicates that this device consumes this resource. |
| **2 to 7 - Reserved** | These bits are reserved and must be set to zero. |

### `ResourceSourceIndex`

### `ResourceSourceName`

The name of the serial bus controller device to which this
connection descriptor applies. The name can be a fully
qualified path, a relative path, or a simple name segment
that utilizes the namespace search rules.

### `VendorData`

A pointer to optional data that is specific to the serial bus connection type.

### `VendorDataLength`

The length of the buffer pointed to by **VendorData**.