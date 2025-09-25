# MI_OperationOptions_DisableChannel function

## Description

Uses [MI_Context_WriteMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_writemessage) to disable logging to the specified
channel.

## Parameters

### `options` [in, out]

A pointer to a [MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) structure.

### `channel` [in]

Channel to disable, which can be any of the following.

#### MI_WRITEMESSAGE_CHANNEL_WARNING

Channel used to broadcast warning messages.

#### MI_WRITEMESSAGE_CHANNEL_VERBOSE

Channel used to broadcast verbose informational messages.

#### MI_WRITEMESSAGE_CHANNEL_DEBUG

Channel used to broadcast debugging information.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.