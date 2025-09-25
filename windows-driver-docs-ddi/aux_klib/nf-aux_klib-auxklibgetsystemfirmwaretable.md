# AuxKlibGetSystemFirmwareTable function

## Description

The **AuxKlibGetSystemFirmwareTable** routine retrieves the specified firmware table from the firmware table provider.

## Parameters

### `FirmwareTableProviderSignature` [in]

The identifier of the firmware table provider to which the query is to be directed. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| 'ACPI' | The ACPI firmware table provider. |
| 'FIRM' | The raw firmware table provider. |
| 'RSMB' | The raw SMBIOS firmware table provider. |

### `FirmwareTableID` [in]

The identifier of the firmware table. The characters in the identifier are in little-endian order.

For example, FACP is the name of a table provided by ACPI. The FACP table is identified by the 4-byte value 'PCAF' (0x50434146) in the **Signature** field of the **DESCRIPTION_HEADER** structure at the start of the table. The following code example shows how to specify FACP in an **AuxKlibGetSystemFirmwareTable** call:

`status = AuxKlibGetSystemFirmwareTable('ACPI', 'PCAF', pBuffer, BUFSIZE, &dataSize);`

In this example, `pBuffer` points to the caller-allocated buffer, `BUFSIZE` is the size in bytes of this buffer, and `dataSize` is a variable to which the routine writes the number of bytes written to the buffer. For more information about the **DESCRIPTION_HEADER** structure, see the Advanced Configuration and Power Interface Specification at the [Advanced Configuration and Power Interface](https://go.microsoft.com/fwlink/p/?linkid=57185) website.

### `FirmwareTableBuffer` [out, optional]

A pointer to a caller-allocated buffer that receives the list of firmware tables. If this parameter is NULL, the value written to **ReturnLength* is the required buffer size. For more information about the contents of this buffer, see the Remarks section.

### `BufferLength` [in]

The size, in bytes, of the buffer pointed to by *FirmwareTableBuffer*.

### `ReturnLength` [out, optional]

A pointer to a location to which the routine writes the number of bytes of data written to the buffer pointed to by *FirmwareTableBuffer*.

## Return value

**AuxKlibGetSystemFirmwareTable** returns STATUS_SUCCESS if the call is successful. Possible return values include the following error codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was supplied to the routine. |
| **STATUS_BUFFER_TOO_SMALL** | The caller-allocated buffer is too small, but the required buffer size has been written to the *ReturnLength* output parameter. |

## Remarks

The raw SMBIOS table provider ('RSMB') retrieves the contents of the raw SMBIOS firmware table. The data written to the *FirmwareTableBuffer* buffer starts with the following structure:

```
struct RawSMBIOSData
{
  BYTE  Used20CallingMethod;
  BYTE  SMBIOSMajorVersion;
  BYTE  SMBIOSMinorVersion;
  BYTE  DmiRevision;
  DWORD  Length;
  BYTE  SMBIOSTableData[];
};
```

The raw firmware table provider ('FIRM') retrieves the contents of the specified physical address range. The value written to **ReturnLength* is the size of the address range.

The ACPI table provider ('ACPI') retrieves the contents of the specified ACPI table. Because OEMs can include ACPI firmware tables that are not listed in the ACPI specification, you should first call [AuxKlibEnumerateSystemFirmwareTables](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/nf-aux_klib-auxklibenumeratesystemfirmwaretables) to enumerate all ACPI tables that are currently available from the system firmware.

For ACPI, if the system firmware contains multiple tables with the same name, **AuxKlibEnumerateSystemFirmwareTables** enumerates them all. However, **AuxKlibGetSystemFirmwareTable** retrieves only the first table in the list that has this name.

**AuxKlibGetSystemFirmwareTable** is the kernel-mode equivalent of the Win32 [GetSystemFirmwareTable](https://learn.microsoft.com/windows/win32/api/sysinfoapi/nf-sysinfoapi-getsystemfirmwaretable) function.

Drivers must call [AuxKlibInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/nf-aux_klib-auxklibinitialize) before calling **AuxKlibGetSystemFirmwareTable**.

**AuxKlibGetSystemFirmwareTable** is defined in the Aux_klib.h header file that is included in the WDK for Windows 8 and later versions of Windows. To use this routine, drivers should link to the version of Aux_klib.lib that is included in the WDK for Windows 8 and later versions of Windows. The implementation of **AuxKlibGetSystemFirmwareTable** in these versions of the WDK can be used in versions of Windows starting with Windows Vista.

## See also

[AuxKlibEnumerateSystemFirmwareTables](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/nf-aux_klib-auxklibenumeratesystemfirmwaretables)

[AuxKlibInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/nf-aux_klib-auxklibinitialize)

[GetSystemFirmwareTable](https://learn.microsoft.com/windows/win32/api/sysinfoapi/nf-sysinfoapi-getsystemfirmwaretable)