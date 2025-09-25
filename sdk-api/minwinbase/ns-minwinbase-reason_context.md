# REASON_CONTEXT structure

## Description

Contains information about a power request. This structure is used by the
[PowerCreateRequest](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-powercreaterequest) and
[SetWaitableTimerEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-setwaitabletimerex) functions.

## Members

### `Version`

The version number of the structure. This parameter must be set to
**POWER_REQUEST_CONTEXT_VERSION**.

### `Flags`

The format of the reason for the power request. This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| **POWER_REQUEST_CONTEXT_DETAILED_STRING**<br><br>0x00000002 | The *Detailed* structure identifies a localizable string resource that describes the reason for the power request. |
| **POWER_REQUEST_CONTEXT_SIMPLE_STRING**<br><br>0x00000001 | The *SimpleReasonString* parameter contains a simple, non-localizable string that describes the reason for the power request. |

### `Reason`

A union that consists of either a **Detailed** structure or a string.

### `Reason.Detailed`

A structure that identifies a localizable string resource to describe the reason for the power
request.

### `Reason.Detailed.LocalizedReasonModule`

The module that contains the string resource.

### `Reason.Detailed.LocalizedReasonId`

The ID of the string resource.

### `Reason.Detailed.ReasonStringCount`

The number of strings in the *ReasonStrings* parameter.

### `Reason.Detailed.ReasonStrings`

An array of strings to be substituted in the string resource at run time.

### `Reason.SimpleReasonString`

A non-localized string that describes the reason for the power request.

## Remarks

It is safe to pass read-only strings as the *SimpleReasonString* or *ReasonStrings* because the [PowerCreateRequest](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-powercreaterequest) and [SetWaitableTimerEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-setwaitabletimerex) functions read from the strings and do not write to them.

## See also

[PowerCreateRequest](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-powercreaterequest)

[SetWaitableTimerEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-setwaitabletimerex)