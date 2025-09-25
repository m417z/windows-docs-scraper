# IOleCacheControl::OnStop

## Description

Notifies the cache that it should terminate any existing advise sinks. No indication is given as to whether a connection actually existed.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | An unexpected error has occurred. |
| **E_OUTOFMEMORY** | Insufficient memory is available for this operation. |

## Remarks

The data advisory connection between the running object and the cache is destroyed as part of calling **OnStop**.

## See also

[IOleCacheControl](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecachecontrol)

[IOleCacheControl::OnRun](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecachecontrol-onrun)