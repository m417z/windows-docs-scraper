# IPipeDouble::Pull

## Description

Retrieves data of the double type from the pipe source.

## Parameters

### `buf` [out]

A pointer to the memory buffer that receives the data. The buffer must be able to hold at least the number of doubles specified in *cRequest*.

### `cRequest` [in]

The number of doubles requested.

### `pcReturned` [out]

The actual number of doubles returned.

## Return value

This method returns S_OK to indicate that the data was retrieved successfully.

## Remarks

When the **Pull** method is called, data is requested from the provider of the pipe. The caller must provide a buffer that will hold at least the number of doubles specified in the *cRequest* parameter. The proxy will unmarshal the data into the provided buffer and set the number of doubles actually provided in *pcReturned*. The *pcReturned* parameter can be less than or equal to *cRequest*, but it will never be greater. When *pcReturned* is 0, it indicates that there is no more data.

## See also

[IPipeDouble](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipipedouble)