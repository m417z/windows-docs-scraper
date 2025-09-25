# PVIDEO_PORT_GET_PROC_ADDRESS callback function

## Description

The *VideoPortGetProcAddress* callback routine retrieves the address of a Windows 2000 or later video port driver function.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's hardware device extension.

### `FunctionName` [in]

Pointer to a null-terminated ASCII string that contains the name of the function being searched for.

## Return value

*VideoPortGetProcAddress* returns a pointer to the function specified in the *FunctionName* parameter, if it exists. If that function does not exist, this function returns **NULL**.

## Remarks

*VideoPortGetProcAddress* makes it possible for a video miniport driver to gain access to video port driver functions without linking to them directly. This enables a miniport driver to take full advantage of Windows 2000 and later features but still be able to load on earlier NT-based operating system versions. For an example of how to use *VideoPortGetProcAddress*, see [Using VideoPortGetProcAddress](https://learn.microsoft.com/windows-hardware/drivers/display/using-videoportgetprocaddress).

The **VideoPortGetProcAddress** member of the [VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info) structure contains the address of this callback routine.

## See also

[VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info)