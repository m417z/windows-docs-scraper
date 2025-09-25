# LINEAGENTSESSIONENTRY structure

## Description

The
**LINEAGENTSESSIONENTRY** structure describes an ACD agent session. The
[LINEAGENTSESSIONLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentsessionlist) structure can contain an array of
**LINEAGENTSESSIONENTRY** structures.

## Members

### `hAgentSession`

Unique identifier for an agent session. It is the responsibility of the agent handler to generate and maintain uniqueness of these identifiers.

### `hAgent`

Unique identifier for an agent. It is the responsibility of the agent handler to generate and maintain uniqueness of these identifiers.

### `GroupID`

Universally unique identifier for an ACD group. It is the responsibility of the agent handler to generate and maintain uniqueness of this identifier.

### `dwWorkingAddressID`

Address identifier on which the agent will receive calls for this session.

## See also

[About Call Center Controls](https://learn.microsoft.com/windows/desktop/Tapi/about-call-center-controls)

[LINEAGENTSESSIONLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentsessionlist)

[lineGetAgentSessionList](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentsessionlist)