# VideoPortRegisterBugcheckCallback function

## Description

The **VideoPortRegisterBugcheckCallback** function allows a video miniport driver to register for, or hook, a callback that is invoked when a specified bug check occurs.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `BugcheckCode` [in]

Indicates the bug check code for which to be called back. Currently, the miniport driver can register only for bug check code 0xEA.

### `Callback` [in]

Pointer to the miniport driver's [HwVidBugcheckCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_bugcheck_callback) function. This function must be nonpaged, and must not reference pageable code or data. The miniport driver can set this parameter to **NULL** to indicate that the bug check callback should be unhooked.

### `BugcheckDataSize` [in]

Indicates the sum of BUGCHECK_DATA_SIZE_RESERVED and the number of bytes of data the miniport driver will provide for inclusion in the dump file. The value of this parameter must be less than or equal to 4000. The miniport driver can set this parameter to zero to indicate that the bug check callback should be unhooked.

## Return value

**VideoPortRegisterBugcheckCallback** returns NO_ERROR if it succeeds. Otherwise, it returns a status code indicating the nature of the failure.

## Remarks

If you are developing a video miniport driver intended to run on Windows XP or an earlier NT-base operating system, you can use the [VideoPortGetProcAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_port_get_proc_address) callback routine to find the address of the **VideoPortRegisterBugcheckCallback** function. For details, see [Using VideoPortGetProcAddress](https://learn.microsoft.com/windows-hardware/drivers/display/using-videoportgetprocaddress).

A miniport driver can register for a callback when a specific type of bug check occurs. Currently, only [bug check code 0xEA](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-0xea--thread-stuck-in-device-driver) can be hooked. When the bug check occurs, the minidriver-supplied callback function is called and the miniport driver can append data to the dump file. This is useful for collecting statistical data when direct debugging is not possible.

The value of the *BugcheckDataSize* parameter must be BUGCHECK_DATA_SIZE_RESERVED bytes larger than the data provided by the miniport driver. For example, suppose the miniport driver provides DUMP_SIZE bytes of data to be written to the dump file. Then the value of *BugcheckDataSize* should be DUMP_SIZE + BUGCHECK_DATA_SIZE_RESERVED, and that total value must be less than or equal to 4000.

The constant BUGCHECK_DATA_SIZE_RESERVED (defined in *video.h*) is available in Microsoft Windows Server 2003 and later build environments. In the Windows XP SP1 build environment, use 48 instead of BUGCHECK_DATA_SIZE_RESERVED.

The miniport driver can unregister a previously-registered callback by calling this function, specifying **NULL** for the *Callback* parameter, or zero for the *DataSize* parameter.

For more information, see [Video Port Driver Support for Bug Check Callbacks](https://learn.microsoft.com/windows-hardware/drivers/display/video-port-driver-support-for-bug-check-callbacks).

## See also

[HwVidBugcheckCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_bugcheck_callback)