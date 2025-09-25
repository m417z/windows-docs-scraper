# LINEEVENT callback function

## Description

*Line_Event* is a callback function implemented by TAPI and supplied to the service provider as a parameter to
[TSPI_lineOpen](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineopen). The service provider calls this function to report events that occur on the line or on calls on the line.

The **LINEEVENT** type defines a pointer to this callback function. *Line_Event* is a placeholder for the application-defined function name.

## Parameters

### `htLine`

The TAPI handle for the line on which the event occurred.

### `htCall`

The TAPI handle for the call on which the event occurred if this is a call-related event. For line-related events where there is no call, this parameter is set to **NULL**.

### `dwMsg`

Specifies the kind of event that is being reported. Interpretation of the other parameters is performed in different ways according to the context indicated by *dwMsg*.

### `dwParam1`

A parameter for the message.

### `dwParam2`

A parameter for the message.

### `dwParam3`

A parameter for the message.

## Remarks

The call state when calling this function can be any state.

The service provider passes the
[HTAPILINE](https://learn.microsoft.com/windows/desktop/Tapi/htapiline) value supplied to
[TSPI_lineOpen](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineopen) as the *htLine* parameter. It includes the message identifier and parameters specific to the event.

This function differs from the callback function defined at the TAPI level in that it separates line and call parameters. Both parameters are used for some messages. The sets of messages that can be passed to this procedure differ slightly from the TAPI level. In particular, completion of asynchronously executing requests is reported through the
[Completion_Proc](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) callback instead of this one.

## See also

[Completion_Proc](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[TSPI_lineOpen](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineopen)