# _KF_REDIRECTION_CAPABILITIES enumeration

## Description

Flags that specify the current redirection capabilities of a known folder. Used by [IKnownFolder::GetRedirectionCapabilities](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfolder-getredirectioncapabilities).

## Constants

### `KF_REDIRECTION_CAPABILITIES_ALLOW_ALL:0xff`

The folder can be redirected if any of the bits in the lower byte of the value are set but no DENY flag is set. DENY flags are found in the upper byte of the value.

### `KF_REDIRECTION_CAPABILITIES_REDIRECTABLE:0x1`

The folder can be redirected. Currently, redirection exists for only common and user folders; fixed and virtual folders cannot be redirected.

### `KF_REDIRECTION_CAPABILITIES_DENY_ALL:0xfff00`

Redirection is not allowed.

### `KF_REDIRECTION_CAPABILITIES_DENY_POLICY_REDIRECTED:0x100`

The folder cannot be redirected because it is already redirected by group policy.

### `KF_REDIRECTION_CAPABILITIES_DENY_POLICY:0x200`

The folder cannot be redirected because the policy prohibits redirecting this folder.

### `KF_REDIRECTION_CAPABILITIES_DENY_PERMISSIONS:0x400`

The folder cannot be redirected because the calling application does not have sufficient permissions.

## See also

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))