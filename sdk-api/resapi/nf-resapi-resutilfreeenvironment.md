# ResUtilFreeEnvironment function

## Description

Destroys the environment variable block created with [ResUtilGetEnvironmentWithNetName](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetenvironmentwithnetname). The **PRESUTIL_FREE_ENVIRONMENT** type defines a pointer to this function.

## Parameters

### `lpEnvironment` [in]

Pointer to the environment variable block returned from [ResUtilGetEnvironmentWithNetName](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetenvironmentwithnetname).

## Return value

This function has no return values.

## See also

[ResUtilGetEnvironmentWithNetName](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetenvironmentwithnetname)