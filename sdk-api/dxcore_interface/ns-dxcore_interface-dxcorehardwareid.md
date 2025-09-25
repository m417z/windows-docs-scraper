## Description

Represents the PnP hardware ID parts for an adapter.

## Members

### `vendorID`

Type: **uint32_t\***

The PCI ID or ACPI ID of the adapter's hardware vendor. If this value is less than or equal to 0xFFFF, it is a PCI ID; otherwise, it is an ACPI ID.

### `deviceID`

Type: **uint32_t\***

The PCI ID or ACPI ID of the adapter's hardware device. If **vendorID** is a PCI ID, it is also a PCI ID; otherwise, it is an ACPI ID.

### `subSysID`

Type: **uint32_t\***

The PCI ID or ACPI ID of the adapter's hardware subsystem. If **vendorID** is a PCI ID, it is also a PCI ID; otherwise, it is an ACPI ID.

### `revision`

Type: **uint32_t\***

The adapter's PCI or ACPI revision number. If **vendorID** is a PCI ID, it is a PCI device revision number; otherwise, it is an ACPI device revision number.

## See also

[DXCore reference](https://learn.microsoft.com/windows/win32/dxcore/dxcore-reference), [Using DXCore to enumerate adapters](https://learn.microsoft.com/windows/win32/dxcore/dxcore-enum-adapters)