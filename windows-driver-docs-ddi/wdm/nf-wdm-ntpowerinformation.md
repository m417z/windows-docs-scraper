# NtPowerInformation function (wdm.h)

## Description

The **NtPowerInformation** routine sets or retrieves system power information.

## Parameters

### `InformationLevel` [in]

Specifies the requested information level, which indicates the specific power information to be set or retrieved. Currently, the only supported *POWER_INFORMATION_LEVEL* value is **PlatformInformation**.

| Value | Description |
|--|--|
| **PlatformInformation** | Information represents the currently supported power capabilities of the system. Information may change as drivers are installed. For example, the installation of legacy device drivers that do not support power management might modify the capabilities of the system. |

### `InputBuffer` [in, optional]

Pointer to a caller-allocated input buffer. This parameter must be **NULL**, otherwise **ERROR_INVALID_PARAMETER** is returned.

### `InputBufferLength` [in]

Size, in bytes, of the buffer at *InputBuffer*. The parameter must be set to zero.

### `OutputBuffer` [out, optional]

A pointer to an output buffer. The data type of this buffer depends on the information level requested in the *InformationLevel* parameter. For the **PlatformInformation** level, the only currently supported value, the *OutputBuffer* parameter is required and should be of the [POWER_PLATFORM_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_power_platform_information) type.

### `OutputBufferLength` [in]

Size, in bytes, of the output buffer. Depending on the information level requested, the buffer may be variably sized. *PlatformInformation*, the only currently supported value, requires a buffer that is the size of a [POWER_PLATFORM_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_power_platform_information) structure.

## Return value

Returns STATUS_SUCCESS if the call is successful. If the call fails, possible error codes include the following:

| Return code | Description |
|--|--|
| **STATUS_BUFFER_TOO_SMALL** | The output buffer is of insufficient size to contain the data being returned. |
| **STATUS_INVALID_PARAMETER** | The **PlatformInformation** information level, which is the only currently supported value, requires no input buffer and must contain an output buffer. The caller either supplied an input buffer or no output buffer. |
| **STATUS_ACCESS_DENIED** | The caller had insufficient access rights to perform the requested action. |

## Remarks

[NtPowerInformation]() and **ZwPowerInformation** are two versions of the same Windows Native System Services routine.

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

### Examples

This example illustrates a valid function call.

```cpp
POWER_PLATFORM_INFORMATION PlatformInfo = {0};
NTSTATUS Result = NtPowerInformation(PlatformInformation, NULL, 0, &PlatformInfo, sizeof(PlatformInfo));
```

## See also

[POWER_PLATFORM_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_power_platform_information)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)