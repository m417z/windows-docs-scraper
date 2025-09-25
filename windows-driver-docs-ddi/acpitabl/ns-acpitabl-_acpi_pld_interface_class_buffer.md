# _ACPI_PLD_INTERFACE_CLASS_BUFFER structure

## Description

Describes the ACPI PLD interface class descriptor buffer, revision 1 (Microsoft custom PLD buffer extension, 128-bits).

## Members

### `ClassGuid`

The ClassGuid field of the ACPI_PLD_INTERFACE_CLASS_BUFFER structure.

## Remarks

The GUID is defined as follows:

```cpp
DEFINE_GUID(ACPI_PLD_INTERFACE_CLASS_BUFFER_GUID,
    0x1facec76, 0x96a8, 0x4d9e, 0x84, 0x6e, 0x3a, 0x6d, 0x68, 0x7c, 0x32, 0xfc);
```

## See also