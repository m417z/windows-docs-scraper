# CERT_POLICY_CONSTRAINTS_INFO structure

## Description

The **CERT_POLICY_CONSTRAINTS_INFO** structure contains established policies for accepting certificates as trusted.

## Members

### `fRequireExplicitPolicy`

**BOOL** flag indicating whether explicit policy information is required.

### `dwRequireExplicitPolicySkipCerts`

**DWORD** indicating the number of required explicit policy certificates.

### `fInhibitPolicyMapping`

**BOOL** flag indicating whether policy mapping is inhibited.

### `dwInhibitPolicyMappingSkipCerts`

**DWORD** indicating the number of policy mapping certificates to be skipped.