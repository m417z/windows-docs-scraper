# EtwEventWriteFull function

[The EtwEventWriteFull function and the structures that it returns are internal to the operating system and subject to change from one release of Windows to another.]

Writes a full event to a session.

## Parameters

*RegHandle*

RegHandle for the provider.

*EventDescriptor*

Event Descriptor of the event to log.

*EventProperty*

Flag given by the user.

*ActivityId*

Activity Id.

*RelatedActivityId*

Related activity Id.

*UserDataCount*

The number of user data items.

*UserData*

Pointer to an array of user data items.

## Return value

A Win32 error code.

## Remarks

The EtwEventWriteFull function and the structures that it returns are internal to the operating system and subject to change from one release of Windows to another. To maintain the compatibility of your application, it is better to use public functions instead.

## Requirements
|   |   |
| ---- |:---- |
| **Target Platform** | Windows |
| **Header** | ntetw.h |

## See also

[EventWrite](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventwrite)

[EventWriteEx](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventwriteex)