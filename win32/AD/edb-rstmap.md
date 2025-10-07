# EDB\_RSTMAP structure

The **EDB\_RSTMAP** structure is used with the [**DsRestoreRegister**](https://learn.microsoft.com/windows/win32/ad/dsrestoreregister) function to map a backed up database to a new database.

## Members

**szDatabaseName**

Pointer to a null-terminated string that contains the name of the database when it was backed up.

**szNewDatabaseName**

Pointer to a null-terminated string that contains the new name of the database, including its new location, when applicable.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista<br> |
| Minimum supported server<br> | Windows Server 2008<br> |
| Header<br> | Ntdsbcli.h |
| Unicode and ANSI names<br> | **EDB\_RSTMAPW** (Unicode) and **EDB\_RSTMAPA** (ANSI)<br> |

## See also

[**DsRestoreRegister**](https://learn.microsoft.com/windows/win32/ad/dsrestoreregister)

[Directory Backup Structures](https://learn.microsoft.com/windows/win32/ad/directory-backup-structures)

