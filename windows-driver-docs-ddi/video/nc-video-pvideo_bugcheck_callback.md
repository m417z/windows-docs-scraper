# PVIDEO_BUGCHECK_CALLBACK callback function

## Description

The *HwVidBugcheckCallback* function enables the miniport driver to append data to a dump file when a bug check occurs.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's per-adapter storage area. For more information, see [Device Extensions](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-extensions).

### `BugcheckCode` [in]

Specifies a [bug check code](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-code-reference2).

### `Buffer` [in]

Pointer to the memory location where the miniport driver can store the data that is to be appended to the dump file.

### `BufferSize` [in]

Specifies the size, in bytes, of the buffer pointed to by the *Buffer* parameter.

## Remarks

This function is available in Windows XP SP1 and later.

This function is called when a bug check occurs. The miniport driver can collect data that is to be appended to the dump file and write this data to the buffer. The driver must not write more than *BufferSize* bytes to the buffer.

A video miniport driver registers the *HwVidBugcheckCallback* function by calling the [VideoPortRegisterBugcheckCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportregisterbugcheckcallback) function. The **VideoPortRegisterBugcheckCallback** function exposes this video miniport driver-supplied callback to the system.

To facilitate system recovery after a bug check, any registers that are accessed by this function must not impede the ability of the hardware to transfer to fallback mode, regardless of the state of the device. Also, the function *must* return control to its caller.

Because a system can consist of multiple video miniport drivers, vendors should add an identifying string to the data that this function appends to the dump file.

The function is called at raised IRQL and must not attempt to access pageable code or data.

## See also

[VideoPortRegisterBugcheckCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportregisterbugcheckcallback)