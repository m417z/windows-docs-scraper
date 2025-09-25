# VideoPortGetRomImage function

## Description

Reads the device's read-only memory (ROM).

## Parameters

### `HwDeviceExtension` [in]

A pointer to the miniport driver's device extension.

### `Unused1` [in]

Currently ignored by the video port driver; should be set to **NULL**.

### `Unused2` [in]

Currently ignored by the video port driver; should be set to zero.

### `Length` [in]

Either the number of bytes of ROM data that the video port driver should read and return, or zero.

## Return value

**VideoPortGetRomImage** returns a pointer to a buffer containing the device's ROM (BIOS) data on success; otherwise, returns **NULL** to indicate either there was insufficient memory for the operation, or the device's ROM could not be accessed.

## Remarks

**VideoPortGetRomImage** does not read ROM using the legacy 0xC0000 mapping. It reads ROM that can be discovered using the ACPI_METHOD_DISPLAY_ROM method or the ROM base address register.

The ACPI_METHOD_DISPLAY_ROM alias, defined in Dispmprt.h, represents the method used to obtain the BIOS ROM image. This method is required when the ROM image is stored in a proprietary format such as the system BIOS ROM. This method is not necessary if the ROM image can be read through a standard PCI interface.

The video port driver allocates a buffer of *Length* bytes and fills it with data read from the device's ROM. The video port driver always reads *Length* bytes from the beginning of the device's ROM.

If a miniport driver calls **VideoPortGetRomImage** multiple times, the video port driver will free the buffer from a previous call before allocating and returning a buffer in the current call. Consequently, a miniport driver must only reference the pointer returned by this call to **VideoPortGetRomImage**.

The miniport driver can free the buffer allocated by the video port driver by calling **VideoPortGetRomImage** with a *Length* of zero.

## See also

[VideoPortScanRom](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportscanrom)