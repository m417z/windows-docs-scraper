# LINEAGENTSESSIONINFO structure

## Description

The
**LINEAGENTSESSIONINFO** structure contains information about the ACD agent session. The
[lineGetAgentSessionInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentsessioninfo) function returns the
**LINEAGENTSESSIONINFO** structure.

## Members

### `dwTotalSize`

Total size allocated to this structure, in bytes.

### `dwNeededSize`

Size needed to hold all the information requested, in bytes.

### `dwUsedSize`

Size of the portion of this structure that contains useful information, in bytes.

### `dwAgentSessionState`

One of the
[LINEAGENTSESSIONSTATE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineagentsessionstate--constants).

### `dwNextAgentSessionState`

One of the
[LINEAGENTSESSIONSTATE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineagentsessionstate--constants).

### `dateSessionStartTime`

Time session was created.

### `dwSessionDuration`

Duration of the agent session in seconds. Active period only; timing stops when a session enters the ASST_SESSION_ENDED state.

### `dwNumberOfCalls`

Number of ACD calls handled during this agent session by this agent.

### `dwTotalTalkTime`

Number of seconds spent talking in ACD calls during this agent session by this agent.

### `dwAverageTalkTime`

Average time spent talking for each ACD call during this agent session by this agent, in seconds.

### `dwTotalCallTime`

Number of seconds spent on ACD calls during this agent session by this agent. It includes time on the phone plus wrap-up time.

### `dwAverageCallTime`

Average time spent for each ACD call during this agent session, in seconds. Includes time on the phone plus wrap-up time.

### `dwTotalWrapUpTime`

Number of seconds spent on ACD call wrap-up (after-call work) during this agent session by this agent.

### `dwAverageWrapUpTime`

Average time for each ACD call spent in wrap-up (after-call work) during this agent session, in seconds.

### `cyACDCallRate`

Call rate for each agent session. This is a fixed-point decimal number.

### `dwLongestTimeToAnswer`

Longest time a call was waiting to be answered, in seconds.

### `dwAverageTimeToAnswer`

Average time calls waited to be answered, in seconds.

## See also

[About Call Center Controls](https://learn.microsoft.com/windows/desktop/Tapi/about-call-center-controls)

[lineGetAgentSessionInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentsessioninfo)