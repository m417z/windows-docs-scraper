# SetupDiClassGuidsFromNameA function

## Description

The **SetupDiClassGuidsFromName** function retrieves the GUID(s) associated with the specified class name. This list is built based on the classes currently installed on the system.

## Parameters

### `ClassName` [in]

The name of the class for which to retrieve the class GUID.

### `ClassGuidList` [out]

A pointer to an array to receive the list of GUIDs associated with the specified class name.

### `ClassGuidListSize` [in]

The number of GUIDs in the *ClassGuidList* array.

### `RequiredSize` [out]

Supplies a pointer to a variable that receives the number of GUIDs associated with the class name. If this number is greater than the size of the *ClassGuidList* buffer, the number indicates how large the array must be in order to store all the GUIDs.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by making a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Call **SetupDiClassGuidsFromNameEx** to retrieve the class GUIDs for a class on a remote computer.

> [!NOTE]
> The setupapi.h header defines SetupDiClassGuidsFromName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiClassGuidsFromNameEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiclassguidsfromnameexa)

[SetupDiClassNameFromGuid](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiclassnamefromguida)