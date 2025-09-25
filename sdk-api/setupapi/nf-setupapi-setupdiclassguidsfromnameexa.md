# SetupDiClassGuidsFromNameExA function

## Description

The **SetupDiClassGuidsFromNameEx** function retrieves the GUIDs associated with the specified class name. This resulting list contains the classes currently installed on a local or remote computer.

## Parameters

### `ClassName` [in]

The name of the class for which to retrieve the class GUIDs.

### `ClassGuidList` [out]

A pointer to an array to receive the list of GUIDs associated with the specified class name.

### `ClassGuidListSize` [in]

The number of GUIDs in the *ClassGuidList* array.

### `RequiredSize` [out]

A pointer to a variable that receives the number of GUIDs associated with the class name. If this number is greater than the size of the *ClassGuidList* buffer, the number indicates how large the array must be in order to store all the GUIDs.

### `MachineName` [in, optional]

A pointer to a NULL-terminated string that contains the name of a remote system from which to retrieve the GUIDs. This parameter is optional and can be **NULL**. If *MachineName* is **NULL**, the local system name is used.

> [!CAUTION]
> Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

### `Reserved`

Must be **NULL**.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by making a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Class names are not guaranteed to be unique; only GUIDs are unique. Therefore, one class name can return more than one GUID.

> [!NOTE]
> The setupapi.h header defines SetupDiClassGuidsFromNameEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiClassGuidsFromName](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiclassguidsfromnamea)

[SetupDiClassNameFromGuidEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiclassnamefromguidexa)