# LSA_TOKEN_INFORMATION_NULL structure

## Description

The **LSA_TOKEN_INFORMATION_NULL** structure is used in cases where a non-authenticated system access is needed.

For example, a non-authentication network circuit (such as a null session) can be given **NULL** information. This results in an anonymous token being generated for the logon. An anonymous token gives the user no ability to access protected system resources, but does allow access to non-protected system resources.

## Members

### `ExpirationTime`

Time at which the [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) becomes not valid. Use a value in the distant future if the context never expires.

### `Groups`

[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups) structure containing the [security identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIDs) of groups the user is to be made a member of. This should not include WORLD or other SIDs defined and assigned by the system.

Each SID is expected to be in a separately allocated block of memory. The [TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups) structure is also expected to be in a separately allocated block of memory.