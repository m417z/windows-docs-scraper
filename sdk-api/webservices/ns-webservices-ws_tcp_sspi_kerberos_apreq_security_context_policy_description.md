# WS_TCP_SSPI_KERBEROS_APREQ_SECURITY_CONTEXT_POLICY_DESCRIPTION structure

## Description

Describes the policy specifying security context message binding using TCP channel binding
with windows SSPI transport security. The bootstrap channel uses TCP channel binding with
windows SSPI transport security and kerberos message security.

## Members

### `channelProperties`

Template description for the channel properties specified in policy.

### `securityProperties`

Template description for the security properties specified in policy.

### `sspiTransportSecurityBinding`

Windows SSPI security binding description.

### `kerberosApreqMessageSecurityBinding`

kerberos message security binding description.

### `securityContextSecurityBinding`

Security context security binding description.