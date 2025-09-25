# SetupDiCreateDeviceInfoListExA function

## Description

The **SetupDiCreateDeviceInfoList** function creates an empty [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) on a remote or a local computer and optionally associates the set with a device setup class .

## Parameters

### `ClassGuid` [in, optional]

A pointer to the GUID of the device setup class to associate with the newly created device information set. If this parameter is specified, only devices of this class can be included in this device information set. If this parameter is set to **NULL**, the device information set is not associated with a specific device setup class.

### `hwndParent` [in, optional]

A handle to the top-level window to use for any user interface that is related to non-device-specific actions (such as a select-device dialog box that uses the global class driver list). This handle is optional and can be **NULL**. If a specific top-level window is not required, set *hwndParent* to **NULL**.

### `MachineName` [in, optional]

A pointer to a NULL-terminated string that contains the name of a computer on a network. If a name is specified, only devices on that computer can be created and opened in this device information set. If this parameter is set to **NULL**, the device information set is for devices on the local computer.

> [!CAUTION]
> Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

### `Reserved`

Must be **NULL**.

## Return value

The function returns a handle to an empty device information set if it is successful. Otherwise, it returns INVALID_HANDLE_VALUE. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The caller of this function must delete the returned device information set when it is no longer needed by calling [SetupDiDestroyDeviceInfoList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdidestroydeviceinfolist).

If the device information set is for devices on a remote computer (*MachineName* is not **NULL**), all subsequent operations on this set or any of its elements must use routines that support device information sets with remote elements. The **SetupDi***Xxx* routines that do not provide this support, such as [SetupDiCallClassInstaller](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicallclassinstaller), have a statement to that effect in their reference page.

> [!NOTE]
> The setupapi.h header defines SetupDiCreateDeviceInfoListEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiCreateDeviceInfoList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinfolist)

[SetupDiDestroyDeviceInfoList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdidestroydeviceinfolist)

[SetupDiGetDeviceInfoListDetail](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinfolistdetaila)