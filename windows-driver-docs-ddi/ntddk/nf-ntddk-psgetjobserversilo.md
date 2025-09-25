## Description

This routine returns the effective *ServerSilo* for the job. The returned pointer is valid as long as the supplied *Job* object remains referenced.

This returns a *ServerSilo* or a value indicating the host silo. Unlike [PsGetJobSilo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetjobsilo), it will not return an app silo, even if one is present.

## Parameters

### `Job` [in, optional]

A job object.

### `ServerSilo` [out]

 A pointer that receives the server silo for the job.

## Return value

The following NT status codes are returned.

| Return code | Description |
|---|---|
| **STATUS_INVALID_PARAMETER** | The *Job* parameter is **NULL**. |
| **STATUS_SUCCESS** | A PESILO is returned successfully. |

## Remarks

**STATUS_SUCCESS** is returned even if a server silo is not in effect for the job. In that case, it will return the default host silo.