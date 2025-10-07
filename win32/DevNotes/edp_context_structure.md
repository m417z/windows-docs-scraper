# EDP_CONTEXT structure

Under WIP policy, represents the enterprise context (such as enterprise IDs) of a process.

## Members

### contextStates

States (flags) from the [EDP_CONTEXT_STATES](https://learn.microsoft.com/windows/win32/devnotes/edp_context_states-enum) enumeration that apply to the WIP enterprise context.

### allowedEnterpriseIdCount

The number of enterprise IDs in *AllowedEnterpriseIds*.

### enterpriseIdForUIEnforcement

Enterprise ID of the current UI context of the process.

### allowedEnterpriseIds

List of all enterprise IDs the application is allowed to access the enterprise data of.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------|
| Minimum supported client | Windows 10 |
| Minimum supported server | Windows 10 |
| Header | None |

