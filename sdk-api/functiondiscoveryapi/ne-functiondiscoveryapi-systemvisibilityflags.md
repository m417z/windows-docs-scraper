# SystemVisibilityFlags enumeration

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Determines the visibility of the function instance's data.

## Constants

### `SVF_SYSTEM:0`

The function instance's data is available to all users on the system.

### `SVF_USER:1`

The function instance's data is accessible only to the current user.

## Remarks

All data operations and function instances are stored in HKEY_LOCAL_MACHINE. Access to a function instance or its data with system-wide visibility must be performed with Administrator access permissions.