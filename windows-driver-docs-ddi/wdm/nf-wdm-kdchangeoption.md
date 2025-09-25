# KdChangeOption function

## Description

The **KdChangeOption** routine accesses and changes state in the kernel that is related to kernel debugging.

## Parameters

### `Option` [in]

A value from the KD_OPTION enumeration that indicates the kernel state to access and change. The value of this parameter determines the format and required length of the *InBuffer* and *OutBuffer*. Currently, the only valid value is KD_OPTION_SET_BLOCK_ENABLE.

### `InBufferBytes` [in, optional]

The size, in bytes, of the buffer at *InBuffer*. This value is optional.

### `InBuffer` [in]

A pointer to a caller-allocated input buffer that contains information about the kernel state to change. If *Option* specifies a kernel state that does not require input data, this pointer can be **NULL**.

### `OutBufferBytes` [in, optional]

The size, in bytes, of the buffer at *OutBuffer*. This value is optional.

### `OutBuffer` [out]

A pointer to a caller-allocated output buffer in which information that pertains to the kernel state is returned. If *Option* specifies a kernel state that does not produce output data, this pointer can be **NULL**.

### `OutBufferNeeded` [out, optional]

## Return value

**KdChangeOption** returns STATUS_SUCCESS if it successfully carried out the requested operation. Otherwise, the return value can be one of the following error status codes:

STATUS_ACCESS_DENIED

STATUS_INVALID_INFO_CLASS

STATUS_INVALID_PARAMETER

STATUS_DEBUGGER_INACTIVE

## Remarks

If the operating system was booted with no debug controls, **KdChangeOption** returns STATUS_DEBUGGER_INACTIVE.

Currently, the only valid value for the *Option* parameter is KD_OPTION_SET_BLOCK_ENABLE. If *Option* is set to any other value, **KdChangeOption** returns STATUS_INVALID_INFO_CLASS. When *Option* is KD_OPTION_SET_BLOCK_ENABLE, the caller must set the *InBufferBytes* parameter to **sizeof**(BOOLEAN), the *OutBufferBytes* parameter to zero, and the *OutBuffer* parameter to **NULL**; otherwise, **KdChangeOption** returns STATUS_INVALID_PARAMETER. If the high bit (0x80) in the **KdBlockEnable** system variable is set to one, the debugger can never be re-enabled, and **KdChangeOption** returns STATUS_ACCESS_DENIED. Otherwise, **KdChangeOption** sets the **KdBlockEnable** system variable to the BOOLEAN value that *InBuffer* points to.