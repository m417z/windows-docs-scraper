# LINEAGENTENTRY structure

## Description

The
**LINEAGENTENTRY** structure describes an individual ACD agent. The
[LINEAGENTLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentlist) structure can contain an array of
**LINEAGENTENTRY** structures.

## Members

### `hAgent`

Unique identifier for an agent. It is the responsibility of the agent handler to generate and maintain uniqueness of these identifiers.

### `dwNameSize`

Size of the agent name string including the **null** terminator, in bytes.

### `dwNameOffset`

Offset from the beginning of the structure to a **null**-terminated string that specifies the name of the agent, which is also the operating system's user name. The size of the string is specified by **dwNameSize**.

### `dwIDSize`

Size of the ID string including the **null** terminator, in bytes.

### `dwIDOffset`

Offset from the beginning of the structure to a **null**-terminated string that specifies the ID of the agent. Used by legacy ACD systems to identify the agent. The size of the string is specified by **dwIDSize**.

### `dwPINSize`

Size of the PIN string, in bytes.

### `dwPINOffset`

Offset from the beginning of the structure to a **null**-terminated string that specifies the PIN or password of the agent. Used by legacy ACD systems for agent authorization. The size of the string is specified by **dwPINSize**.

## See also

[About Call Center Controls](https://learn.microsoft.com/windows/desktop/Tapi/about-call-center-controls)

[LINEAGENTLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentlist)