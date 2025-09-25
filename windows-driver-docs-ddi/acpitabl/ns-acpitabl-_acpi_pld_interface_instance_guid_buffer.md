# _ACPI_PLD_INTERFACE_INSTANCE_GUID_BUFFER structure

## Description

Describes the ACPI PLD interface instance GUID descriptor buffer, revision 1 (Microsoft custom PLD buffer extension, 128-bits).

## Members

### `ReferenceGuid`

The ReferenceString field of the ACPI_PLD_INTERFACE_INSTANCE_GUID_BUFFER structure.

## Remarks

The GUID is defined as follows:

```cpp
DEFINE_GUID(ACPI_PLD_INTERFACE_INSTANCE_GUID_BUFFER_GUID,
    0x1face9db, 0x2530, 0x4248, 0x8e, 0xe3, 0x51, 0x05, 0x3a, 0xef, 0x47, 0xc2);
```

## See also