# SetupDiGetClassBitmapIndex function

## Description

The **SetupDiGetClassBitmapIndex** function retrieves the index of the mini-icon supplied for the specified class.

## Parameters

### `ClassGuid` [in, optional]

A pointer to the GUID of the [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes) for which to retrieve the mini-icon. This pointer is optional and can be **NULL**.

### `MiniIconIndex` [out]

A pointer to a variable of type INT that receives the index of the mini-icon for the specified device setup class. If the *ClassGuid* parameter is **NULL** or if there is no mini-icon for the specified class, **SetupDiGetClassBitmapIndex** returns the index of the mini-icon for the Unknown device setup class.

## Return value

If there is a min-icon for the specified device setup class, **SetupDiGetClassBitmapIndex** returns **TRUE**. Otherwise, this function returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). If the *ClassGuid* parameter is **NULL**, or if there is no mini-icon for the specified class, the function returns **FALSE** and [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_NO_DEVICE_ICON.

## Remarks

For a list of the device setup class mini-icons and their corresponding indexes, see [SetupDiDrawMiniIcon](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdidrawminiicon).

## See also

[SetupDiDrawMiniIcon](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdidrawminiicon)

[SetupDiLoadClassIcon](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiloadclassicon)