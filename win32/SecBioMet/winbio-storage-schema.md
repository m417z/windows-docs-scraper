# WINBIO\_STORAGE\_SCHEMA structure

The **WINBIO\_STORAGE\_SCHEMA** structure describes the capabilities of a biometric storage adapter. This structure is used by the [**WinBioEnumDatabases**](https://learn.microsoft.com/windows/desktop/api/Winbio/nf-winbio-winbioenumdatabases) function.

## Members

**BiometricFactor**

The type of biometric measurement saved in the database.

**DatabaseId**

A GUID that identifies the database.

**DataFormat**

A GUID that identifies the format of the templates in the database.

**Attributes**

Information about the characteristics of the database. This can be a bitwise **OR** of the following constants.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------|
| **WINBIO\_DATABASE\_FLAG\_MASK**<br>0xFFFF0000 | Represents a mask for the flag bits.<br> |
| **WINBIO\_DATABASE\_FLAG\_REMOTE**<br>0x00020000 | The database resides on a remote computer.<br> |
| **WINBIO\_DATABASE\_FLAG\_REMOVABLE**<br>0x00010000 | The database resides on a removable drive.<br> |
| **WINBIO\_DATABASE\_TYPE\_DBMS**<br>0x00000002 | The database is managed by a database management system.<br> |
| **WINBIO\_DATABASE\_TYPE\_FILE**<br>0x00000001 | The database is contained in a file.<br> |
| **WINBIO\_DATABASE\_TYPE\_MASK**<br>0x0000FFFF | Represents a mask for the type bits.<br> |
| **WINBIO\_DATABASE\_TYPE\_ONCHIP**<br>0x00000003 | The database resides on the biometric sensor.<br> |
| **WINBIO\_DATABASE\_TYPE\_SMARTCARD**<br>0x00000004 | The database resides on a smart card.<br> |

**FilePath**

The path and file name of the database if it resides on the computer disk.

**ConnectionString**

A string value that can be sent to a database server to identify the database.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | Winbio\_types.h (include Winbio.h) |

## See also

[Client Application Structures](https://learn.microsoft.com/windows/win32/secbiomet/client-application-structures)

[**WinBioEnumDatabases**](https://learn.microsoft.com/windows/desktop/api/Winbio/nf-winbio-winbioenumdatabases)

