# _PEP_ACPI_EXTENDED_ADDRESS structure (pepfx.h)

## Description

The **PEP_ACPI_EXTENDED_ADDRESS** structure is used to report resource usage in the address space such as memory and IO.

## Members

### `Type`

A [PEP_ACPI_RESOURCE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_pep_acpi_resource_type) enumeration value describing this resource.

### `Flags`

A [PEP_ACPI_RESOURCE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_resource_flags) structure describing this resource.

### `ResourceFlags`

Indicates the type of resource this structure describes.

| Value | Meaning |
| --- | --- |
| 0 | Indicates that this resource is a memory range. |
| 1 | Indicates that this resource is an IO range. |
| 2 | Indicates that this resource is a bus number range. |
| 3-191 | These values are reserved for future use. |
| 192-255 | These values are reserved for use by the hardware vendor. |

### `GeneralFlags`

A value containing the bit flags that are common to all resource types.

| Bit(s) | Meaning |
| --- | --- |
| **0 - Consumer/Producer flag** | When set, this indicates that the device consumes this resource. |
| **1 - Decode type** | When set, indicates that this bridge subtractively decodes the address. This applies to top level bridges only. <br><br>When not set, indicates that this bridge positively decodes this address. |
| **2 - Minimum address fixed** | When set, indicates that the minimum address is fixed. |
| **3 - Max address fixed** | When set, indicates that the maximum address is fixed. |
| **4 to 7 - Reserved** | These bits are reserved and must be set to zero. |

### `TypeSpecificFlags`

The value of this member is dependent on the value in **ResourceFlags** member. The flags for each resource type are described in the tables below.

Memory Resource (**ResourceFlags** = **0**)

| Bit(s) | Meaning |
| --- | --- |
| **0 - Write status** | When set, indicates that this memory range is available for reading and writing. Otherwise, this indicates that this memory range is read-only. |
| **1 to 2 - Memory attributes (MEM)** | **0** - Indicates the memory is non-cacheable.<br><br>**1** - Indicates the memory is cacheable.<br><br>**2** - Indicates the memory is cacheable and supports write combining.<br><br>**3**  - The memory is cacheable and prefetchable. |
| **3 to 4 - Memory attributes (MTP)** | These bits are only defined if this memory resource describes system RAM. <br><br>**0** - Address range memory: This range is available RAM usable by the operating system.<br><br>**1** - Address range reserved: This range of addresses is in use or reserved by the system and is not to be included in the allocatable memory pool of the operating system's memory manager.<br><br>**2** - Address range ACPI: ACPI Reclaim Memory. This range is available RAM usable by the OS after it reads the ACPI tables. <br><br>**3** - Address Range NVS: ACPI NVS Memory. This range of addresses is in use or reserved by the system and must not be used by the operating system. This range is required to be saved and restored across an NVS sleep. |
| **5 - Memory to IO translation** | **0** - Type-static: This resource is memory on the primary and secondary sides of the bridge.<br><br>**1** - Type-translation: This resource is memory on the secondary side of the bridge and IO on the primary side of the bridge. |
| **6 to 7 - Reserved** | These bits are reserved and must be set to zero. |

IO Resource (**ResourceFlags** = **1**)

| Bit(s) | Meaning |
| --- | --- |
| **0 to 1 - Range** | **0** - Reserved.<br><br>**1** - Non-ISA ranges only. This flag is for bridges on systems with multiple bridges. Setting this bit means the memory window specified in this descriptor is limited to the non-ISA IO addresses that fall within the specified window. The non-ISA IO ranges are: n100-n3FF, n500-n7FF, n900-nBFF, nD00-nFFF. This bit can only be set for bridges entirely configured through the ACPI namespace.<br><br>**2** - ISA ranges only. This flag is for bridges on systems with multiple bridges. Setting this bit means the memory window specified in this descriptor is limited to the ISA IO addresses that fall within the specified window. The ISA IO ranges are: n000-n0FF, n400-n4FF, n800-n8FF, nC00-nCFF. This bit can only be set for bridges entirely configured through the ACPI namespace.<br><br>**3** - The memory window covers the entire range |
| **2 to 3 - Reserved** | These bits are reserved and must be set to zero. |
| **4 - IO to memory translation** | **0** - Type-static: This resource is IO on the primary and secondary sides of the bridge.<br><br>**1** - Type-translation: This resource is IO on the secondary side of the bridge and memory on the primary side of the bridge. |
| **5 - Sparse translation** | This bit is only meaningful if bit 4 (IO to memory translation) is set.<br><br>**0** - Dense translation: The primary-side memory address of any specific IO port within the secondary-side range can be found using the following function. <br><br> *address = port + TranslationAddress*<br><br>**1** - Sparse translation: The primary-side memory address of any specific IO port within the secondary-side range can be found using the following function.<br><br>*address = (((port & 0xFFFc) << 10) || (port & 0xFFF)) + TranslationAddress*<br><br>In the address used to access the IO port, bits 2 to 11 must be identical to bits 12 to 21, this gives four bytes of IO ports on each 4 KB page. |
| **6 to 7 - Reserved** | These bits are reserved and must be set to zero. |

Bus Number Range Resource (**ResourceFlags** = **2**)

| Bit(s) | Meaning |
| --- | --- |
| **0 to 7 - Reserved** | These bits are reserved and must be set to zero. |

### `RevisionId`

Indicates the revision of the extended address space descriptor detailed by this structure. For ACPI 3.0, this value is 1.

### `Reserved`

### `Granularity`

A bit mask indicating which bits have been decoded.

### `MinimumAddress`

The minimum starting address. For bridges that translate addresses, this is the address space on the secondary side of the bridge.

### `MaximumAddress`

The maximum starting address. For bridges that translate addresses, this is the address space
on the secondary side of the bridge.

### `TranslationAddress`

For bridges that translate addresses across the bridge, this is the
address on the primary side.

### `AddressLength`

The address length.

### `TypeAttribute`

Indicates attributes that are specific to the resource type that is specified in the **ResourceFlags** member. If **ResourceFlags** is zero, this value is zero, otherwise the meaning of the value can be found in the *UEFI Specification* in the section titled **GetMemoryMap()**.

### `DescriptorName`

The name of this resource descriptor.