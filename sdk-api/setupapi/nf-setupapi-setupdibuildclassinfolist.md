# SetupDiBuildClassInfoList function

## Description

The **SetupDiBuildClassInfoList** function returns a list of setup class GUIDs that identify the classes that are installed on a local computer.

## Parameters

### `Flags` [in]

Flags used to control exclusion of classes from the list. If no flags are specified, all setup classes are included in the list. Can be a combination of the following values:

#### DIBCI_NOINSTALLCLASS

Exclude a class if it has the **NoInstallClass** value entry in its registry key.

#### DIBCI_NODISPLAYCLASS

Exclude a class if it has the **NoDisplayClass** value entry in its registry key.

### `ClassGuidList` [out, optional]

A pointer to a GUID-typed array that receives a list of setup class GUIDs. This pointer is optional and can be **NULL**.

### `ClassGuidListSize` [in]

The number of GUIDs in the array that is pointed to by the *ClassGuildList* parameter. If *ClassGuidList* is **NULL**, *ClassGuidSize* must be zero.

### `RequiredSize` [out]

A pointer to a DWORD-typed variable that receives the number of GUIDs that are returned (if the number is less than or equal to the size, in GUIDs, of the array that is pointed to by the *ClassGuidList* parameter).

If this number is greater than the size of the *ClassGuidList* array, it indicates how large the *ClassGuidList* array must be in order to contain all the class GUIDs.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by making a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To retrieve the number of classes that are installed on a local computer, call **SetupDiBuildClassInfoList** with *ClassGuidList* set to **NULL** and *ClassGuidSize* set to zero. In response to such a call, the function returns the number of classes in ******RequiredSize*.

**SetupDiBuildClassInfoList** does not return a class GUID for a class if the **NoUseClass** value entry exists in the registry key of the class.

To retrieve the list of setup class GUIDs installed on a remote system use [SetupDiBuildClassInfoListEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdibuildclassinfolistexa).

## See also

[SetupDiBuildClassInfoListEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdibuildclassinfolistexa)

[SetupDiGetClassDescription](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdescriptiona)

[SetupDiGetINFClass](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetinfclassa)