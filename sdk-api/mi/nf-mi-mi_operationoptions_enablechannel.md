# MI_OperationOptions_EnableChannel function

## Description

Uses
[MI_Context_WriteMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_writemessage) to enable logging to the specified
channel.

## Parameters

### `options` [in, out]

A pointer to a [MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) structure.

### `channel` [in]

Channel to enable, which can be any of the following.

#### MI_WRITEMESSAGE_CHANNEL_WARNING (0)

Channel used to broadcast warning messages.

#### MI_WRITEMESSAGE_CHANNEL_VERBOSE (1)

Channel used to broadcast verbose informational messages.

#### MI_WRITEMESSAGE_CHANNEL_DEBUG (2)

Channel used to broadcast debugging information.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.