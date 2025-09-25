# NET_FW_MODIFY_STATE enumeration

## Description

The NET_FW_MODIFY_STATE enumerated type specifies the effect of modifications to the current policy.

## Constants

### `NET_FW_MODIFY_STATE_OK:0`

Changing or adding a firewall rule or firewall group to the current profile will take effect.

### `NET_FW_MODIFY_STATE_GP_OVERRIDE`

Changing or adding a firewall rule or firewall group to the current profile will not take effect because the profile is controlled by the group policy.

### `NET_FW_MODIFY_STATE_INBOUND_BLOCKED`

Changing or adding a firewall rule or firewall group to the current profile will not take effect because unsolicited inbound traffic is not allowed.

## See also

[Windows Firewall with Advanced Security Enumerated Types](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-with-advanced-security-enumerated-types)

[Windows Firewall with Advanced Security Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-with-advanced-security-reference)