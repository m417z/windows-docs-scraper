# EnumSystemFirmwareTables function

## Description

Enumerates all system firmware tables of the specified type.

## Parameters

### `FirmwareTableProviderSignature` [in]

The identifier of the firmware table provider to which the query is to be directed. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| 'ACPI' | The ACPI firmware table provider. |
| 'FIRM' | The raw firmware table provider. Not supported for UEFI systems; use 'RSMB' instead. |
| 'RSMB' | The raw SMBIOS firmware table provider. |

### `pFirmwareTableEnumBuffer` [out]

A pointer to a buffer that receives the list of firmware tables. If this parameter is **NULL**, the return value is the required buffer size.

For more information on the contents of this buffer, see the Remarks section.

### `BufferSize` [in]

The size of the *pFirmwareTableBuffer* buffer, in bytes.

## Return value

If the function succeeds, the return value is the number of bytes written to the buffer. This value will always be less than or equal to *BufferSize*.

If the function fails because the buffer is not large enough, the return value is the required buffer size, in bytes. This value is always greater than *BufferSize*.

If the function fails for any other reason, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Starting with Windows 10, version 1803, Universal Windows apps can access the System Management BIOS (SMBIOS) information by declaring the **smbios** restricted capability in the app manifest.
See [Access SMBIOS information from a Universal Windows App](https://learn.microsoft.com/windows/desktop/SysInfo/access-smbios-information-from-a-universal-windows-app) for details. Only raw SMBIOS (RSMB) firmware tables can be accessed from a Universal Windows app.

As of Windows Server 2003 with Service Pack 1 (SP1), applications cannot access the \Device\PhysicalMemory object. Access to this object is limited to kernel-mode drivers. This change affects applications read System Management BIOS (SMBIOS) or other BIOS data stored in the lowest 1MB of physical memory. Applications have the following alternatives to read data from low physical memory:

* Retrieve the SMBIOS properties using WMI. Many individual properties are contained in the [Win32 classes](https://learn.microsoft.com/windows/desktop/CIMWin32Prov/win32-provider). You can also retrieve the raw SMBIOS data in a single buffer using the **MSSMBios_RawSMBiosTables** class.
* Use the [GetSystemFirmwareTable](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemfirmwaretable) function to read the raw SMBIOS firmware table.

There is no way for applications to write to low physical memory.

The raw SMBIOS table provider ('RSMB') currently returns a single table identifier, 0x0000. This corresponds to the raw SMBIOS firmware table.

The raw firmware table provider ('FIRM') returns a list of **DWORD** table identifiers. Each identifier corresponds to the beginning of a physical address range. Currently, this provider returns 'C0000' and 'E0000'. These values correspond to physical memory from 0xC0000 to 0xDFFFF and 0xE0000 to 0xFFFFF, respectively.

The ACPI table provider ('ACPI') returns a list of **DWORD** table identifiers. Each identifier returned corresponds to Signature field of the DESCRIPTION_HEADER structure for an ACPI table currently in the ACPI namespace of the system.

For ACPI, if the system contains multiple tables with the same name, they are all enumerated with **EnumSystemFirmwareTables**. However, [GetSystemFirmwareTable](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemfirmwaretable) retrieves only the first table in the list with this name.

## See also

[Access SMBIOS information from a Universal Windows App](https://learn.microsoft.com/windows/desktop/SysInfo/access-smbios-information-from-a-universal-windows-app)

[GetSystemFirmwareTable](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemfirmwaretable)

[System
Information Functions](https://learn.microsoft.com/windows/desktop/SysInfo/system-information-functions)