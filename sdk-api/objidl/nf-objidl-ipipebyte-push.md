# IPipeByte::Push

## Description

Sends data of the byte type to the pipe source.

## Parameters

### `buf` [in]

A pointer to the memory buffer that holds the data to be sent.

### `cSent` [in]

The number of bytes in the buffer.

## Return value

This method returns S_OK to indicate that the data was sent successfully.

## Remarks

When the **Push** method is called, the data is being sent to the provider of the pipe. The caller fills the buffer with the data and then calls **Push**. The number of bytes being sent is specified in the *cSent* parameter. The caller is responsible for ensuring that the buffer is valid for the duration of the call.

When the last of the data has been pushed, the caller must do one last push of *cSent* equal to 0 to indicate that the data transfer is complete.

## See also

[IPipeByte](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipipebyte)