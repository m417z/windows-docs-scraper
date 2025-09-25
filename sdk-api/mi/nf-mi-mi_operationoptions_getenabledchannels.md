# MI_OperationOptions_GetEnabledChannels function

## Description

Gets the list of previously enabled channels.

## Parameters

### `options` [in]

[MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) structure.

### `channels`

Returned buffer that contains the numbers of all enabled channels.

### `bufferLength` [in]

The length, in elements, of the **channels** buffer. If 0, the returned **channelCount** value will reflect how large the **channels** buffer needs to be.

### `channelCount` [out]

Number of enabled channels.

### `flags` [out, optional]

Unused.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.