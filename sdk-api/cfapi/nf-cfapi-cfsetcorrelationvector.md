# CfSetCorrelationVector function

## Description

Allows a sync provider to instruct the platform to use a specific correlation vector for telemetry purposes on a placeholder file. This is optional.

## Parameters

### `FileHandle` [in]

The handle to the placeholder file. The platform properly synchronizes the operation with other active requests. An attribute or no-access handle is sufficient.

### `CorrelationVector` [in]

A specific correlation vector to be associated with the *FileHandle*.

## Return value

If this function succeeds, it returns `S_OK`. Otherwise, it returns an **HRESULT** error code.

## Remarks

The platform automatically assigns a correlation vector to each file when it is first opened, and provides this correlation vector with each callback to the sync provider as part of the common [CF_CALLBACK_INFO](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_callback_info). It is suggested that the sync engine call this function to increment the last digit of the correlation vector “clock” as the sync provider progresses through internal stages (as defined by the sync provider) of satisfying the request.

## See also

[CF_CALLBACK_INFO](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_callback_info)