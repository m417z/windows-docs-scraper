# SetupDiBuildClassInfoListExA function

## Description

The **SetupDiBuildClassInfoListEx** function returns a list of setup class GUIDs that includes every class installed on the local system or a remote system.

## Parameters

### `Flags` [in]

Flags used to control exclusion of classes from the list. If no flags are specified, all setup classes are included in the list. Can be a combination of the following values:

#### DIBCI_NOINSTALLCLASS

Exclude a class if it has the **NoInstallClass** value entry in its registry key.

#### DIBCI_NODISPLAYCLASS

Exclude a class if it has the **NoDisplayClass** value entry in its registry key.

### `ClassGuidList` [out, optional]

A pointer to a buffer that receives a list of setup class GUIDs.

### `ClassGuidListSize` [in]

Supplies the number of GUIDs in the *ClassGuildList* array.

### `RequiredSize` [out]

A pointer to a variable that receives the number of GUIDs returned. If this number is greater than the size of the *ClassGuidList*, the number indicates how large the *ClassGuidList* array must be in order to contain the list.

### `MachineName` [in, optional]

A pointer to a NULL-terminated string that contains the name of a remote computer from which to retrieve installed setup classes. This parameter is optional and can be **NULL**. If *MachineName* is **NULL**, this function builds a list of classes installed on the local computer.

> [!CAUTION]
> Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

### `Reserved`

Must be **NULL**.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by making a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[SetupDiBuildClassInfoList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdibuildclassinfolist)

[SetupDiGetClassDescriptionEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdescriptionexa)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupDiBuildClassInfoListEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).