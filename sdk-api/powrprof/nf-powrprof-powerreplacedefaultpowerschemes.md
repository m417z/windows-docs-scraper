# PowerReplaceDefaultPowerSchemes function

## Description

Replaces the default power schemes with the current user's power schemes. This allows an
administrator to change the default power schemes for the system. Replacing the default schemes enables users to
use the **Restore Defaults** option in the Control Panel
**Power Options** application to restore customized power scheme defaults instead of the
original Windows power scheme defaults.

## Return value

Returns **ERROR_SUCCESS** (zero) if the call was successful, and a nonzero value if
the call failed.

## Remarks

The caller must be a member of the local Administrators group.