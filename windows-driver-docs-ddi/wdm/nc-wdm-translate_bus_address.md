# TRANSLATE_BUS_ADDRESS callback function

## Description

The *TranslateBusAddress* routine translates addresses on the parent bus to logical addresses.

## Parameters

### `Context` [in]

A pointer to interface-specific context information. The caller passes the value that is passed as the **Context** member of the [BUS_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_bus_interface_standard) structure for the interface.

### `BusAddress` [in]

The bus-relative address to be translated.

### `Length` [in]

The length, in bytes, of the input memory that *BusAddress* points to.

### `AddressSpace` [in, out]

On input, the address space in which the device's hardware address resides. A value of 0x0 signifies memory space, and a value of 0x1 signifies port I/O space. On output, *AddressSpace* indicates the address space in which the *TranslatedAddress* resides.

### `TranslatedAddress` [out]

The translated (logical) address that corresponds to the bus-relative address that the caller provides in *BusAddress*.

## Return value

The
*TranslateBusAddress* routine returns **TRUE** if the translation operation succeeded and **FALSE** otherwise.

## See also

[BUS_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_bus_interface_standard)