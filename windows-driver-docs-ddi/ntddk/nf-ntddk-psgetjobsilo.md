## Description

This routine returns the first job in the hierarchy that is a *Silo*. The returned pointer is valid as long as the supplied *Job* object remains referenced.

This returns both app silos and server silos, whichever is first.

## Parameters

### `Job` [in]

A job object.

### `Silo` [out]

 A pointer that receives the silo for the job.

## Return value

The following NT status codes are returned:

| Return code | Description |
|---|---|
| **STATUS_INVALID_PARAMETER** | The *Job* parameter is **NULL**. |
| **STATUS_JOB_NO_CONTAINER** | No silo is present. |
| **STATUS_SUCCESS** | A PESILO is returned successfully. |