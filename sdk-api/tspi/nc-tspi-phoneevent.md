# PHONEEVENT callback function

## Description

*Phone_Event* a callback function implemented by TAPI and supplied to the service provider as a parameter to
[TSPI_phoneOpen](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phoneopen). The service provider calls this function to report events that occur on the phone.

The **PHONEEVENT** type defines a pointer to this callback function. *Phone_Event* is a placeholder for the application-defined function name.

## Parameters

### `htPhone`

The TAPI handle for the phone on which the event occurred.

### `dwMsg`

Specifies the kind of event that is being reported. Interpretation of the other parameters is done in different ways according to the context indicated by *dwMsg*.

### `dwParam1`

A parameter for the message.

### `dwParam2`

A parameter for the message.

### `dwParam3`

A parameter for the message.

## Remarks

The call state when calling this function can be any state.

The service provider passes the
[HTAPIPHONE](https://learn.microsoft.com/windows/desktop/Tapi/htapiphone) value supplied to
[TSPI_phoneOpen](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phoneopen) as the *htPhone* parameter. It includes the message identifier and parameters specific to the event.

The sets of messages that can be passed to this procedure differ slightly from the messages to the corresponding callback at the TAPI level. In particular, completion of asynchronously executing requests is reported through the
[Completion_Proc](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) callback instead of this one.

## See also

[Completion_Proc](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[TSPI_lineOpen](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineopen)