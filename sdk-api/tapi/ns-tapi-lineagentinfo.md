# LINEAGENTINFO structure

## Description

The
**LINEAGENTINFO** structure contains information about an ACD agent. The
[lineGetAgentInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentinfo) function returns the
**LINEAGENTINFO** structure.

## Members

### `dwTotalSize`

Total size allocated to this structure including the null terminator, in bytes.

### `dwNeededSize`

Size needed to hold all the information requested, in bytes.

### `dwUsedSize`

Size of the portion of this structure that contains useful information, in bytes.

### `dwAgentState`

Must be one of the
[LINEAGENTSTATEEX_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineagentstateex--constants).

### `dwNextAgentState`

Must be one of the
[LINEAGENTSTATEEX_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineagentstateex--constants).

### `dwMeasurementPeriod`

Period for which the switch or implementation stores and calculates information, in seconds. For example, **dwNumberOfACDCalls** holds the number of calls the agent handled; **dwMeasurementPeriod** indicates if this value referenced the calls handed in the last hour, day, or month.

### `cyOverallCallRate`

Agent's call rate (calls per agent hour — where agent hour represents the time that an agent was active in one or more agent sessions) across all agent sessions. This is a fixed-point decimal number.

### `dwNumberOfACDCalls`

Number of ACD calls handled by this agent across all sessions.

### `dwNumberOfIncomingCalls`

Number of incoming non-ACD calls handled by this agent.

### `dwNumberOfOutgoingCalls`

Number of outgoing non-ACD calls handled by this agent.

### `dwTotalACDTalkTime`

Number of seconds spent talking in ACD calls by this agent across all sessions.

### `dwTotalACDCallTime`

Number of seconds spent on ACD calls by this agent (across all sessions). Includes the time on phone plus wrap-up time.

### `dwTotalACDWrapUpTime`

Number of seconds spent on ACD call wrap-up (after call work) by this agent across all sessions.

## See also

[About Call Center Controls](https://learn.microsoft.com/windows/desktop/Tapi/about-call-center-controls)

[lineGetAgentInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentinfo)