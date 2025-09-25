# SetupDiClassNameFromGuidExW function

## Description

The **SetupDiClassNameFromGuidEx** function retrieves the class name associated with a class GUID. The class can be installed on a local or remote computer.

## Parameters

### `ClassGuid` [in]

The class GUID of the class name to retrieve.

### `ClassName` [out]

A pointer to a string buffer that receives the NULL-terminated name of the class for the specified GUID.

### `ClassNameSize` [in]

The size, in characters, of the *ClassName* buffer.

### `RequiredSize` [out, optional]

The number of characters required to store the class name (including a terminating null). *RequiredSize* is always less than MAX_CLASS_NAME_LEN.

### `MachineName` [in, optional]

A pointer to a NULL-terminated string that contains the name of a remote system on which the class is installed. This parameter is optional and can be **NULL**. If *MachineName* is **NULL**, the local system name is used.

> [!CAUTION]
> Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

### `Reserved`

Must be **NULL**.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[SetupDiClassGuidsFromNameEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiclassguidsfromnameexa)

[SetupDiClassNameFromGuid](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiclassnamefromguida)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupDiClassNameFromGuidEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).