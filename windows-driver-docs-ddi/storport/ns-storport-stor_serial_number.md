## Description

**STOR_SERIAL_NUMBER** is the structure pointed to by the **Parameters** parameter when a miniport's [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) routine is called with a **ControlType** of **ScsiAdapterSerialNumber**.

## Members

### `Version`

Version of this structure. Currently set to 1.

### `Size`

Size of this structure, in bytes. Set to ```sizeof(STOR_SERIAL_NUMBER)```.

### `Unicode`

BOOLEAN value that is set TRUE if the serial number is in Unicode or FALSE if it's in ASCII.

### `SerialNumber`

NULL-terminated string representing the serial number. **SerialNumber** can contain up to 128 Unicode or ASCII characters (including the trailing NULL character). Even though there is enough space for 256 ASCII characters, do not return more than 128 characters.

## See also

[**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control)