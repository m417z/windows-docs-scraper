# SetupDiLoadClassIcon function

## Description

The **SetupDiLoadClassIcon** function loads both the large and mini-icon for the specified class.

## Parameters

### `ClassGuid` [in]

A pointer to the GUID of the class for which the icon(s) should be loaded.

### `LargeIcon` [out, optional]

A pointer to an icon handle that receives the handle value for the loaded large icon for the specified class. This pointer is optional and can be **NULL**. If the pointer is **NULL**, the large icon is not loaded.

### `MiniIconIndex` [out, optional]

A pointer to an INT-typed variable that receives the index of the mini-icon for the specified class. The mini-icon is stored in the device installer's mini-icon cache. The pointer is optional and can be **NULL**.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The icons of the class are either predefined and loaded from the device installer's internal cache, or they are loaded directly from the class installer's executable. This function queries the registry value **ICON** in the specified class's section. If the **ICON** value is specified, it indicates which mini-icon to load.

If the **ICON** value is negative, the absolute value represents a predefined icon in the class's registry. See [SetupDiDrawMiniIcon](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdidrawminiicon) for a list of the predefined mini-icons.

If the **ICON** value is positive, it represents an icon in the class installer's executable image that will be extracted. The value 1 is reserved. This function also uses the **INSTALLER32** registry value and then the **ENUMPROPPAGES32** registry value to determine which executable image to extract the icons from. For more information about these registry values, see [INF ClassInstall32 Section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-classinstall32-section).

When a caller is finished using the icon, the caller must call **DestroyIcon** (which is described in the Microsoft Windows SDK documentation).

If the *LargeIcon*  parameter is specified, but the *ClassGuid* parameter does not supply a valid class GUID or the **Icon** registry value of the class is not valid, **SetupDiLoadClassIcon** loads the default large icon, returns the handle for the large icon, and, if the *MiniIconIndex* parameter is specified, returns the index of the default mini-icon.

## See also

[SetupDiDrawMiniIcon](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdidrawminiicon)

[SetupDiGetClassBitmapIndex](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassbitmapindex)