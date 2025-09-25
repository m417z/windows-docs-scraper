# MsiDatabaseIsTablePersistentW function

## Description

The
**MsiDatabaseIsTablePersistent** function returns an enumeration that describes the state of a specific table.

## Parameters

### `hDatabase` [in]

Handle to the database that belongs to the relevant table. For more information, see [Obtaining a Database Handle](https://learn.microsoft.com/windows/desktop/Msi/obtaining-a-database-handle).

### `szTableName` [in]

Specifies the name of the relevant table.

## Return value

This function returns MSICONDITION.

## See also

[General Database Access Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)

## Remarks

> [!NOTE]
> The msiquery.h header defines MsiDatabaseIsTablePersistent as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).