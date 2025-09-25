# GetSystemFirmwareTable function

## Description

Retrieves the specified firmware table from the firmware table provider.

## Parameters

### `FirmwareTableProviderSignature` [in]

The identifier of the firmware table provider to which the query is to be directed. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| 'ACPI' | The ACPI firmware table provider. |
| 'FIRM' | The raw firmware table provider. |
| 'RSMB' | The raw SMBIOS firmware table provider. |

### `FirmwareTableID` [in]

The identifier of the firmware table. This identifier is little endian, you must reverse the characters in the string.

For example, FACP is an ACPI provider, as described in the Signature field of the DESCRIPTION_HEADER structure in the ACPI specification (see the [Advanced Configuration and Power Interface (ACPI) Specification](https://uefi.org/htmlspecs/ACPI_Spec_6_4_html/). Therefore, use 'PCAF' to specify the FACP table, as shown in the following example:

`retVal = GetSystemFirmwareTable('ACPI', 'PCAF', pBuffer, BUFSIZE);`

For more information, see the Remarks section of the [EnumSystemFirmwareTables](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-enumsystemfirmwaretables) function.

### `pFirmwareTableBuffer` [out]

A pointer to a buffer that receives the requested firmware table. If this parameter is **NULL**, the return value is the required buffer size.

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
* Use the **GetSystemFirmwareTable** function to read the raw SMBIOS firmware table.

There is no way for applications to write to low physical memory.

The raw SMBIOS table provider ('RSMB') retrieves the contents of the raw SMBIOS firmware table. The *pFirmwareTableBuffer* buffer receives the following data:

```cpp
#include <windows.h>

struct RawSMBIOSData
{
    BYTE    Used20CallingMethod;
    BYTE    SMBIOSMajorVersion;
    BYTE    SMBIOSMinorVersion;
    BYTE    DmiRevision;
    DWORD   Length;
    BYTE    SMBIOSTableData[];
};

```

The raw firmware table provider ('FIRM') retrieves the contents of the specified physical address range. The function returns the size of the address range.

The ACPI table provider ('ACPI') retrieves the contents of the specified ACPI table. Because OEMs can include ACPI firmware tables that are not listed in the ACPI specification, you should first call [EnumSystemFirmwareTables](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-enumsystemfirmwaretables) to enumerate all ACPI tables that are currently on the system.

For ACPI, if the system contains multiple tables with the same name, they are all enumerated with [EnumSystemFirmwareTables](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-enumsystemfirmwaretables). However, **GetSystemFirmwareTable** retrieves only the first table in the list with this name.

#### Examples

The following example illustrates retrieving the SMBIOS table.

```cpp
DWORD error = ERROR_SUCCESS;
DWORD smBiosDataSize = 0;
RawSMBIOSData* smBiosData = NULL; // Defined in this link
DWORD bytesWritten = 0;

// Query size of SMBIOS data.
smBiosDataSize = GetSystemFirmwareTable('RSMB', 0, NULL, 0);

// Allocate memory for SMBIOS data
smBiosData = (RawSMBIOSData*) HeapAlloc(GetProcessHeap(), 0, smBiosDataSize);
if (!smBiosData) {
    error = ERROR_OUTOFMEMORY;
    goto exit;
}

// Retrieve the SMBIOS table
bytesWritten = GetSystemFirmwareTable('RSMB', 0, smBiosData, smBiosDataSize);

if (bytesWritten != smBiosDataSize) {
    error = ERROR_INVALID_DATA;
    goto exit;
}

// Process the SMBIOS data and free the memory under an exit label

```

## See also

[Access SMBIOS information from a Universal Windows App](https://learn.microsoft.com/windows/desktop/SysInfo/access-smbios-information-from-a-universal-windows-app)

[EnumSystemFirmwareTables](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-enumsystemfirmwaretables)

[System
Information Functions](https://learn.microsoft.com/windows/desktop/SysInfo/system-information-functions)