# IInertiaProcessor::ProcessTime

## Description

The **ProcessTime** method performs calculations for the given tick and can raise the **Started**, **Delta**, or **Completed** event depending on whether extrapolation is completed or not. If extrapolation finished at the previous tick, the method is no-op.

## Parameters

### `timestamp` [in]

A parameter that contains a timestamp (in millisecs) to process.

### `completed` [out]

Indicates whether an operation was performed. A value of false indicates extrapolation was finished at a previous tick and the operation was a no-op.

## Return value

Returns **S_OK** on success, otherwise returns an error code such as **E_FAIL**.

## See also

[IInertiaProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-iinertiaprocessor)

[Methods](https://learn.microsoft.com/windows/desktop/wintouch/imanipulationprocessor-methods)

[Process](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-iinertiaprocessor-process)