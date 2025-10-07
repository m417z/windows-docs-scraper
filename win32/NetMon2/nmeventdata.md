# NMEVENTDATA structure

The **NMEVENTDATA** structure contains information about an event condition that is passed to Network Monitor to insert a line in the expert viewer.

## Members

**Version**

Version number of the **NMEVENTDATA** structure. The version number must be zero. Future versions of Network Monitor may support a higher version number.

**EventIdent**

Identifier of the event. **EventIdent** is unique to each expert, and references an [event reference page](https://learn.microsoft.com/windows/win32/netmon2/event-reference-page).

**Flags**

A set of flags that describes who sends the event data, and how the event is displayed.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **EVENT\_FLAG\_EXPERT** | The event came from an expert. <br> |
| **NMEVENTFLAG\_DO\_NOT\_DISPLAY\_SEVERITY** | Do not display the severity level for the event. <br> |
| **NMEVENTFLAG\_DO\_NOT\_DISPLAY\_SOURCE** | Do not display the source name for the event. <br> |
| **NMEVENTFLAG\_DO\_NOT\_DISPLAY\_EVENT\_NAME** | Do not display the event name for the event. <br> |
| **NMEVENTFLAG\_DO\_NOT\_DISPLAY\_DESCRIPTION** | Do not display the description for the event. <br> |
| **NMEVENTFLAG\_DO\_NOT\_DISPLAY\_MACHINE** | Do not display the machine name for the event. <br> |
| **NMEVENTFLAG\_DO\_NOT\_DISPLAY\_TIME** | Do not display the time for the event <br> |
| **NMEVENTFLAG\_DO\_NOT\_DISPLAY\_FIXED\_COLUMNS** | Do not display the Severity, Source, Event Name, Description, Machine, or Time columns. This is not a single flag, but it is a union of the previous six flags. <br> |

**Severity**

Severity level of the event. The severity level can have one of the following values:

NMEVENT\_SEVERITY\_INFORMATIONAL NMEVENT\_SEVERITY\_WARNING NMEVENT\_SEVERITY\_STRONG\_WARNING NMEVENT\_SEVERITY\_ERROR NMEVENT\_SEVERITY\_SEVERE\_ERROR NMEVENT\_SEVERITY\_CRITICAL\_ERROR

**NumColumns**

Number of columns designated in the current structure.

**szSourceName**

Name of the expert that is displayed.

**szEventName**

Name of the event that is displayed.

**szDescription**

Description of the event that is displayed.

**szMachine**

Obsolete, should be **NULL**.

**Justification**

Information displayed in the second window of the Event Viewer. The **Justification** member may be **NULL**. If it is **NULL**, the second window is not be visible.

**szUrl**

Reserved; this member must be **NULL**.

**SysTime**

Time at which the event condition occurs. The time is measured relative to the beginning of the capture.

**Column**

Table of column structures that appears in the top pane of the Event Viewer.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

