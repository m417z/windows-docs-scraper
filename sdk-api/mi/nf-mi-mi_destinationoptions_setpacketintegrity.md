# MI_DestinationOptions_SetPacketIntegrity function

## Description

Enables or disables packet integrity (signing) of a protocol connection.

## Parameters

### `options` [in, out]

A [MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) object returned from the [MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions) function.

### `integrity`

Boolean value where **MI_TRUE** means to use packet integrity (signing) and **MI_FALSE** means to not use packet integrity.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

The default setting is **MI_TRUE**. This setting does not apply to all protocols and will be ignored when not supported.