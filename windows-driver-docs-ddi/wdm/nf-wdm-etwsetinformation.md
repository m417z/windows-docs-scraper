## Description

The **EtwSetInformation** provides special-purpose information to modify a kernel-mode ETW provider registration. The **EtwSetInformation** function is the kernel-mode equivalent of the [**EventSetInformation**](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventsetinformation) function.

## Parameters

### `RegHandle` [in]

The registration handle of the ETW provider to modify. The registration handle is returned by [**EtwRegister**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-etwregister).

### `InformationClass` [in]

The type ([**EVENT_INFO_CLASS**](https://learn.microsoft.com/windows/win32/api/evntprov/ne-evntprov-event_info_class)) of operation to perform on the registration object.

### `EventInformation` [in, optional]

The input buffer.

### `InformationLength` [in]

Size of the input buffer.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

| Return code | Description |
|--|--|
| STATUS_INVALID_HANDLE | This error is returned if the *RegHandle* parameter is not a valid registration handle. |
| STATUS_INVALID_PARAMETER | One or more of the parameters is not valid. |
| STATUS_INVALID_DEVICE_REQUEST | The request is not supported. |

## Remarks

## See also

[**EventSetInformation**](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventsetinformation)

[**EVENT_INFO_CLASS**](https://learn.microsoft.com/windows/win32/api/evntprov/ne-evntprov-event_info_class)