# IDENTITY_TYPE enumeration

## Description

Specifies the type of identities to enumerate. This enumeration is used by the [IIdentityProvider::GetIdentityEnum](https://learn.microsoft.com/windows/desktop/api/identityprovider/nf-identityprovider-iidentityprovider-getidentityenum) and [IIdentityStore::EnumerateIdentities](https://learn.microsoft.com/windows/desktop/api/identitystore/nf-identitystore-iidentitystore-enumerateidentities) methods.

## Constants

### `IDENTITIES_ALL:0`

Enumerate all identities.

### `IDENTITIES_ME_ONLY:0x1`

Enumerate only identities associated with the current user.