# PowerSetRequest function

## Description

Increments the count of power requests of the specified type for a power request object.

## Parameters

### `PowerRequest` [in]

A handle to a power request object.

### `RequestType` [in]

The power request type to be incremented. This parameter can be one of the following values.

| Value | Description |
|--------|-------------|
| PowerRequestDisplayRequired | The display remains on even if there is no user input for an extended period of time.<br><br>
**Note:** A **PowerRequestSystemRequired** must be taken in addition to a **PowerRequestDisplayRequired** to ensure the display stays on and the system does not enter sleep for the duration of the request.

|
| PowerRequestSystemRequired | The system continues to run instead of entering sleep after a period of user inactivity. |
| PowerRequestAwayModeRequired | The system enters away mode instead of sleep in response to explicit action by the user. In away mode, the system continues to run but turns off audio and video to give the appearance of sleep. **PowerRequestAwayModeRequired** is only applicable on Traditional Sleep (S3) systems. |
| PowerRequestExecutionRequired | The calling process continues to run instead of being suspended or terminated by process lifetime management mechanisms. When and how long the process is allowed to run depends on the operating system and power policy settings.<br><br>On Traditional Sleep (S3) systems, an active **PowerRequestExecutionRequired** request implies **PowerRequestSystemRequired**. |

## Return value

If the function succeeds, it returns a nonzero value.

If the function fails, it returns zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

On Modern Standby systems on DC power, system and execution required power requests are terminated 5 minutes after the system sleep timeout has expired.

Except for **PowerRequestAwayModeRequired** on Traditional Sleep (S3) systems, power requests are terminated upon user-initiated system sleep entry (power button, lid close or selecting **Sleep** from the **Start** menu).

To conserve power and provide the best user experience, applications that use power requests should follow these best practices:

* When creating a power request, provide a localized text string that describes the reason for the request in the [REASON_CONTEXT](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-reason_context) structure.
* Call **PowerSetRequest** immediately before the scenario that requires the request.
* Call [PowerClearRequest](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-powerclearrequest) to decrement the reference count for the request as soon as the scenario is finished.
* Clean up all request objects and associated handles before the process exits or the service stops.

## See also

[PowerClearRequest](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-powerclearrequest)

[PowerCreateRequest](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-powercreaterequest)