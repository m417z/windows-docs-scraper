# AuxKlibEnumerateSystemFirmwareTables function

## Description

The **AuxKlibEnumerateSystemFirmwareTables** routine enumerates all system firmware tables of the specified type.

## Parameters

### `FirmwareTableProviderSignature` [in]

The identifier of the firmware table provider to which the query is to be directed. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| 'ACPI' | The ACPI firmware table provider. |
| 'FIRM' | The raw firmware table provider. |
| 'RSMB' | The raw SMBIOS firmware table provider. |

### `FirmwareTableBuffer` [out, optional]

A pointer to a caller-allocated buffer to which the routine writes the list of firmware tables. If this parameter is NULL, the value written to **ReturnLength* is the required buffer size. For more information about the contents of this buffer, see the Remarks section.

### `BufferLength` [in]

The size, in bytes, of the buffer pointed to by *FirmwareTableBuffer*.

### `ReturnLength` [out, optional]

A pointer to a location to which the routine writes the number of bytes of data written to the buffer pointed to by *FirmwareTableBuffer*.

## Return value

**AuxKlibEnumerateSystemFirmwareTables** returns STATUS_SUCCESS if the call is successful. Possible return values include the following error codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was supplied to the routine. |
| **STATUS_BUFFER_TOO_SMALL** | The caller-allocated buffer is too small, but the required buffer size has been written to the *ReturnLength* output parameter. |

## Remarks

If the call is successful, this routine writes an array of one or more table identifiers to the buffer pointed to by the *FirmwareTableBuffer* parameter. Each element of this array is a DWORD value that identifies a firmware table that is available from the provider specified by the *FirmwareTableProviderSignature* parameter.

The raw SMBIOS table provider ('RSMB') currently returns a single table identifier, 0x00000000. This corresponds to the raw SMBIOS firmware table.

The raw firmware table provider ('FIRM') retrieves a list of DWORD table identifiers. Each identifier corresponds to the beginning of a physical address range. Currently, this provider returns two identifiers, 0x000C0000 and 0x000E0000. These identifiers represent physical memory from 0x000C0000 to 0x000DFFFF and from 0x000E0000 to 0x000FFFFF, respectively.

The ACPI table provider ('ACPI') returns a list of DWORD table identifiers. Each identifier returned corresponds to **Signature** field of the **DESCRIPTION_HEADER** structure for an ACPI table currently in the ACPI namespace of the system. For more information about this structure, see the Advanced Configuration and Power Interface Specification at the [Advanced Configuration and Power Interface](https://go.microsoft.com/fwlink/p/?linkid=57185) website.

For ACPI, if the system firmware contains multiple tables with the same name, **AuxKlibEnumerateSystemFirmwareTables** enumerates them all. However, [AuxKlibGetSystemFirmwareTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/nf-aux_klib-auxklibgetsystemfirmwaretable) retrieves only the first table in the list that has this name.

**AuxKlibEnumerateSystemFirmwareTables** is the kernel-mode equivalent of the Win32 [EnumSystemFirmwareTables](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_firmware_table_interface) function.

Drivers must call [AuxKlibInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/nf-aux_klib-auxklibinitialize) before calling **AuxKlibEnumerateSystemFirmwareTable**.

**AuxKlibEnumerateSystemFirmwareTables** is defined in the Aux_klib.h header file that is included in the WDK for Windows 8 and later versions of Windows. To use this routine, drivers should link to the version of Aux_klib.lib that is included in the WDK for Windows 8 and later versions of Windows. The implementation of **AuxKlibEnumerateSystemFirmwareTables** in these versions of the WDK can be used in versions of Windows starting with Windows Vista.

## See also

[AuxKlibGetSystemFirmwareTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/nf-aux_klib-auxklibgetsystemfirmwaretable)

[AuxKlibInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/nf-aux_klib-auxklibinitialize)

[EnumSystemFirmwareTables](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_firmware_table_interface)