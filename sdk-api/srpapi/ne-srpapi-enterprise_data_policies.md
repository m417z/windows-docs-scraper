# ENTERPRISE_DATA_POLICIES enumeration

## Description

**Note** Windows Information Protection (WIP) policy can be applied on Windows 10, version 1607.

Indicates whether the app is enlightened for Windows Information Protection (WIP) and whether the app is managed by policy.

## Constants

### `ENTERPRISE_POLICY_NONE:0x0`

The app is not managed by enterprise policy.

### `ENTERPRISE_POLICY_ALLOWED:0x1`

The app is allowed to access enterprise resources according to the enterprise policy.

### `ENTERPRISE_POLICY_ENLIGHTENED:0x2`

The app is enlightened (self-declared in the app's resource file).

### `ENTERPRISE_POLICY_EXEMPT:0x4`

The app is marked as exempt by the enterprise policy.