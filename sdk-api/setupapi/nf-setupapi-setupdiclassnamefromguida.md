# SetupDiClassNameFromGuidA function

## Description

The **SetupDiClassNameFromGuid** function retrieves the class name associated with a class GUID.

## Parameters

### `ClassGuid` [in]

A pointer to the class GUID for the class name to retrieve.

### `ClassName` [out]

A pointer to a buffer that receives the NULL-terminated string that contains the name of the class that is specified by the pointer in the *ClassGuid* parameter.

### `ClassNameSize` [in]

The size, in characters, of the buffer that is pointed to by the *ClassName* parameter. The maximum size, in characters, of a NULL-terminated class name is MAX_CLASS_NAME_LEN. For more information about the class name size, see the following **Remarks** section.

### `RequiredSize` [out, optional]

A pointer to a variable that receives the number of characters that are required to store the requested NULL-terminated class name. This pointer is optional and can be **NULL**.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Call **SetupDiClassNameFromGuidEx** to retrieve the name for a class on a remote computer.

**SetupDiClassNameFromGuid** does not enforce a restriction on the length of the class name that it can return. This function returns the required size for a NULL-terminated class name even if it is greater than MAX_CLASS_NAME_LEN. However, MAX_CLASS_NAME_LEN is the maximum length of a valid NULL-terminated class name. A caller should never need a buffer that is larger than MAX_CLASS_NAME_LEN. For more information about class names, see the description of the **Class** entry of an [INF Version section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-version-section).

> [!NOTE]
> The setupapi.h header defines SetupDiClassNameFromGuid as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiClassGuidsFromName](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiclassguidsfromnamea)

[SetupDiClassNameFromGuidEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiclassnamefromguidexa)