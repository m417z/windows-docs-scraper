# _CM_EISA_SLOT_INFORMATION structure (miniport.h)

## Description

The **CM_EISA_SLOT_INFORMATION** structure defines EISA configuration header information returned by [HalGetBusData](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85)) for the input *BusDataType* = **EisaConfiguration**, or by [HalGetBusDataByOffset](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85)) for the inputs *BusDataType* = **EisaConfiguration** and *Offset* = 0, assuming the caller-allocated *Buffer* is of sufficient *Length*.

## Members

### `ReturnCode`

Contains a status code if an error occurs when the EISA BIOS is queried. Possible status codes include the following:

* EISA_INVALID_SLOT
* EISA_INVALID_FUNCTION
* EISA_INVALID_CONFIGURATION
* EISA_EMPTY_SLOT
* EISA_INVALID_BIOS_CALL

### `ReturnFlags`

The return flags.

### `MajorRevision`

Information supplied by the manufacturer.

### `MinorRevision`

Information supplied by the manufacturer.

### `Checksum`

The checksum value, allowing validation of the configuration data.

### `NumberFunctions`

The number at this slot.

### `FunctionInformation`

Whether there is available [CM_EISA_FUNCTION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_eisa_function_information) for this slot.

### `CompressedId`

The EISA compressed identification of the device at this slot. This value is identical to the **CompressedId** member of the **CM_EISA_FUNCTION_INFORMATION** structure. This member can be read to determine whether the caller should call **HalGetBusData** or **HalGetBusDataByOffset** again with sufficient buffer space to get more detailed **CM_EISA_FUNCTION_INFORMATION** for a device it supports.

## Remarks

The information returned by **HalGetBusData** or **HalGetBusDataByOffset** in **CM_EISA_SLOT_INFORMATION** and in **CM_EISA_FUNCTION_INFORMATION** immediately following it is read-only.

The driver of an EISA device might call **HalGetBusData** or **HalGetBusDataByOffset** for each slot on each EISA bus in the system, requesting only **CM_EISA_SLOT_INFORMATION** in order to find the device(s) it supports by examining the returned **CompressedId** values. Then, such a driver could allocate sufficient buffer space to call **HalGetBusData(ByOffset)** again for **CM_EISA_SLOT_INFORMATION** and **CM_EISA_FUNCTION_INFORMATION** at slots where its device(s) can be found.

## See also

[CM_EISA_FUNCTION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_eisa_function_information)

[HalGetBusData](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))

[HalGetBusDataByOffset](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))