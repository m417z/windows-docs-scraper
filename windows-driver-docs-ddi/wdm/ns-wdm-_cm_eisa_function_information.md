## Description

The **CM_EISA_FUNCTION_INFORMATION** structure defines detailed EISA configuration information returned by [HalGetBusData](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85)) for the input *BusDataType* **EisaConfiguration**, or by **HalGetBusDataByOffset** for the input *BusDataType* **EisaConfiguration** and the *Offset* zero, assuming the caller-allocated *Buffer* is of sufficient *Length*.

## Members

### `CompressedId`

The EISA compressed identification of the device at this slot. The value is identical to the **CompressedId** member of the [CM_EISA_SLOT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_eisa_slot_information) structure.

### `IdSlotFlags1`

The EISA slot identification flags.

### `IdSlotFlags2`

The EISA slot identification flags.

### `MinorRevision`

Information supplied by the manufacturer.

### `MajorRevision`

Information supplied by the manufacturer.

### `Selections`

The EISA selections for the device.

### `FunctionFlags`

Indicates which of the members has available information. Callers can use the following system-defined masks to determine whether a particular type of configuration information can be or has been returned by **HalGetBusData** or [HalGetBusDataByOffset](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85)):

EISA_FUNCTION_ENABLED

EISA_FREE_FORM_DATA

EISA_HAS_PORT_INIT_ENTRY

EISA_HAS_PORT_RANGE

EISA_HAS_DMA_ENTRY

EISA_HAS_IRQ_ENTRY

EISA_HAS_MEMORY_ENTRY

EISA_HAS_TYPE_ENTRY

EISA_HAS_INFORMATION

The EISA_HAS_INFORMATION mask is a combination of the following:

EISA_HAS_PORT_RANGE

EISA_HAS_DMA_ENTRY

EISA_HAS_IRQ_ENTRY

EISA_HAS_MEMORY_ENTRY

EISA_HAS_TYPE_ENTRY

### `TypeString`

Specifies the type of device.

### `EisaMemory`

Describes the EISA device memory configuration information, defined as follows:

```cpp
typedef struct _EISA_MEMORY_CONFIGURATION {
    EISA_MEMORY_TYPE ConfigurationByte;
    UCHAR DataSize;
    USHORT AddressLowWord;
    UCHAR AddressHighByte;
    USHORT MemorySize;
} EISA_MEMORY_CONFIGURATION, *PEISA_MEMORY_CONFIGURATION;
```

### `EisaIrq`

Describes the EISA interrupt configuration information, defined as follows:

```cpp
typedef struct _EISA_IRQ_CONFIGURATION {
    EISA_IRQ_DESCRIPTOR ConfigurationByte;
    UCHAR Reserved;
} EISA_IRQ_CONFIGURATION, *PEISA_IRQ_CONFIGURATION;
```

### `EisaDma`

Describes the EISA DMA configuration information, defined as follows:

```cpp
typedef struct _EISA_DMA_CONFIGURATION {
    DMA_CONFIGURATION_BYTE0 ConfigurationByte0;
    DMA_CONFIGURATION_BYTE1 ConfigurationByte1;
} EISA_DMA_CONFIGURATION, *PEISA_DMA_CONFIGURATION;
```

### `EisaPort`

Describes the EISA device port configuration information, defined as follows:

```cpp
typedef struct _EISA_PORT_CONFIGURATION {
    EISA_PORT_DESCRIPTOR Configuration;
    USHORT PortAddress;
} EISA_PORT_CONFIGURATION, *PEISA_PORT_CONFIGURATION;
```

### `InitializationData`

Vendor-supplied, device-specific initialization data, if any.

## Remarks

The information returned by **HalGetBusData** or **HalGetBusDataByOffset** in **CM_EISA_FUNCTION_INFORMATION** and/or in the [CM_EISA_SLOT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_eisa_slot_information) header immediately preceding it is read-only.

## See also

[**CM_EISA_SLOT_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_eisa_slot_information)

[HalGetBusData](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))

[HalGetBusDataByOffset](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))