# TrustLevel enumeration

## Description

Represents the trust level of an activatable class.

## Constants

### `BaseTrust:0`

The component has access to resources that are not protected.

### `PartialTrust`

The component has access to resources requested in the app manifest and approved by the user.

### `FullTrust`

The component requires the full privileges of the user.

## Remarks

Classes can be activated depending on the trust level of the caller and the trust classification of the activatable class.

[RegisteredTrustLevel](https://learn.microsoft.com/previous-versions/dn408470(v=vs.85)) is an alias for this enumeration.

## See also

[IInspectable::GetTrustLevel](https://learn.microsoft.com/windows/desktop/api/inspectable/nf-inspectable-iinspectable-gettrustlevel)