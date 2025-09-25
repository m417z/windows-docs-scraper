# VideoPortSetRegistryParameters function

## Description

The **VideoPortSetRegistryParameters** function writes information under the **adapter** key in the registry.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's device extension.

### `ValueName` [in]

Pointer to a buffer containing a null-terminated Unicode string that names the value entry for which data is being written in the registry.

### `ValueData` [in]

Pointer to a buffer containing the values to be written for the *ValueName* entry.

### `ValueLength`

Specifies the size, in bytes, of the data to be written to the registry.

## Return value

**VideoPortSetRegistryParameters** returns NO_ERROR if the given data was successfully written to the registry. Otherwise, it can return ERROR_INVALID_PARAMETER.

## Remarks

**VideoPortSetRegistryParameters** searches under the registry's **adapter** key for the value name specified in the *ValueName* parameter. If the value name that is searched for does not exist, this function creates it automatically. When the value name is found or created, the contents of the *ValueData* parameter are copied to the value name.

For Windows XP and later operating system versions, the value name specified in the *ValueName* parameters does not need to be directly associated with the **adapter** key. Instead, *ValueName* can be associated with a subkey whose path includes the **adapter** key. If the *ValueName* string contains one or more backslashes, **VideoPortSetRegistryParameters** searches for or creates the subkey whose value name is at the end of the string.

For example, if *ValueName* is set to the string "SubKey1\Value1", this function searches for **SubKey1** under the **adapter** key in the registry, creating **SubKey1** if it does not exist. The function then searches for the **Value1** value name, creating it if necessary. **VideoPortSetRegistryParameters** then copies the contents of the *ValueData* parameter to the registry. The path specified in the *ValueName* parameter can refer to a value name an arbitrary number of levels below the **adapter** key, but the behavior of this function is essentially the same. If at any point a subkey or value name is not found, it is created automatically.

In Windows 2000 and later, **VideoPortSetRegistryParameters** returns ERROR_INVALID_PARAMETER if the string passed in the *ValueName* parameter begins with "DefaultSettings." (note that the period is part of the string). In operating systems earlier than Windows 2000, a video miniport driver can pass a value name that begins with "DefaultSettings." to specify the default resolution for a monitor, but there is no need for that capability in Windows 2000 and later.

In a checked build of any version of the operating system, a value name that begins with "DefaultSettings." causes an assertion failure.

**VideoPortSetRegistryParameters** cannot be called from a miniport driver's [HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt) or [HwVidTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_timer) functions, or from [VideoPortQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportqueuedpc), or from a callback to [VideoPortSynchronizeExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportsynchronizeexecution).

## See also

[HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter)

[HwVidInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_initialize)

[VideoPortFlushRegistry](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportflushregistry)

[VideoPortGetRegistryParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetregistryparameters)