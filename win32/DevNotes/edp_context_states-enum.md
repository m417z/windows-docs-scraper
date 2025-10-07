# EDP_CONTEXT_STATES enumeration

Specifies flags that apply to the WIP enterprise context of a process.

## Constants

### EDP_CONTEXT_NONE

WIP context is personal.

### EDP_CONTEXT_IS_EXEMPT

WIP context is exempt, which applies to system apps and processes.

### EDP_CONTEXT_IS_ENLIGHTENED

WIP context is enlightened, which indicates the app can handle both enterprise and personal data.

### EDP_CONTEXT_IS_UNENLIGHTENED_ALLOWED

WIP context is unenlightened allowed, which indicates the app can only handle enterprise data.

### EDP_CONTEXT_IS_PERMISSIVE

Indicates if an enlightened app is allowed to access enterprise network endpoints at all times.

### EDP_CONTEXT_IS_COPY_EXEMPT

Indicates if the app is allowed to perform file copy without protection.

### EDP_CONTEXT_IS_DENIED

WIP context indicates personal app.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------|
| Minimum supported client | Windows 10 |
| Minimum supported server | Windows 10 |
| Header | None |

