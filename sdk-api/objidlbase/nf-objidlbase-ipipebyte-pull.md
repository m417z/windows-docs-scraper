# IPipeByte::Pull

## Description

Retrieves data of the byte type from the pipe source.

## Parameters

### `buf` [out]

A pointer to the memory buffer that receives the data. The buffer must be able to hold at least the number of bytes specified in *cRequest*.

### `cRequest` [in]

The number of bytes requested.

### `pcReturned` [out]

The actual number of bytes returned.

## Return value

This method returns S_OK to indicate that the data was retrieved successfully.

## Remarks

When the **Pull** method is called, data is requested from the provider of the pipe. The caller must provide a buffer that will hold at least the number of bytes specified in the *cRequest* parameter. The proxy will unmarshal the data into the provided buffer and set the number of bytes actually provided in *pcReturned*. The *pcReturned* parameter can be less than or equal to *cRequest*, but it will never be greater. When *pcReturned* is 0, it indicates that there is no more data.

## See also

[IPipeByte](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipipebyte)