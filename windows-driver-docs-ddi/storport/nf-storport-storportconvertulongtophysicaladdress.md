# StorPortConvertUlongToPhysicalAddress function

## Description

The **StorPortConvertUlongToPhysicalAddress** routine converts an unsigned long address into a physical address.

## Parameters

### `UlongAddress` [in]

Contains the address to be converted.

## Return value

The **StorPortConvertUlongToPhysicalAddress** routine returns the physical address that corresponds to the unsigned long address that the caller passed in.

## Remarks

**StorPortConvertUlongToPhysicalAddress** uses **STOR_PHYSICAL_ADDRESS** to represent physical addresses.

```cpp
typedef PHYSICAL_ADDRESS STOR_PHYSICAL_ADDRESS, *PSTOR_PHYSICAL_ADDRESS;

```

The **STOR_PHYSICAL_ADDRESS** type is an operating system-independent data type that Storport miniport drivers use to represent either a physical addresses or a bus-relative address.

The StorPortConvertPhysicalAddressToULong64 macro converts a physical address to a ULONG64 value.

```cpp
ULONG64 StorPortConvertPhysicalAddressToULong64(
  [in] STOR_PHYSICAL_ADDRESS Address
);

```

| Term | Description |
| --- | --- |
| *Address [in]* | **STOR_PHYSICAL_ADDRESS**<br><br>Specifies an address value of type STOR_PHYSICAL_ADDRESS. |
| Return value | **ULONG64**<br><br>**StorPortConvertPhysicalAddressToULong64** returns a ULONG64 value derived from the physical address that was passed to it. |

StorPortConvertPhysicalAddressToULong64 uses **STOR_PHYSICAL_ADDRESS** to represent physical addresses.