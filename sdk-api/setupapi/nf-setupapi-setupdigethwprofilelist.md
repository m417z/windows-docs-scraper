# SetupDiGetHwProfileList function

## Description

The **SetupDiGetHwProfileList** function retrieves a list of all currently defined hardware profile IDs.

## Parameters

### `HwProfileList` [out]

A pointer to an array to receive the list of currently defined hardware profile IDs.

### `HwProfileListSize` [in]

The number of DWORDs in the *HwProfileList* buffer.

### `RequiredSize` [out]

A pointer to a variable of type DWORD that receives the number of hardware profiles currently defined. If the number is larger than *HwProfileListSize*, the list is truncated to fit the array size. The value returned in *RequiredSize* indicates the array size required to store the entire list of hardware profiles. In this case, the function fails and a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INSUFFICIENT_BUFFER.

### `CurrentlyActiveIndex` [out, optional]

A pointer to a variable of type DWORD that receives the index of the currently active hardware profile in the retrieved hardware profile list. This parameter is optional and can be **NULL**.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by making a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Call [SetupDiGetHwProfileListEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigethwprofilelistexa) to retrieve the hardware profile IDs for a remote computer.

## See also

[SetupDiCreateDevRegKey](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedevregkeya)

[SetupDiOpenDevRegKey](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiopendevregkey)