# RtwqShutdown function

## Description

Shuts down the platform. Call this function once for every call to [RtwqStartup](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqstartup). Do not call this function from work queue threads.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

In general, apps should not have pending work after they call this function.