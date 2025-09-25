# ROUTER_CUSTOM_IKEv2_POLICY0 structure

## Description

Contains the IKEv2 main mode and quick mode policy configuration.

Do not use the **ROUTER_CUSTOM_IKEv2_POLICY0** structure directly in your code; using [ROUTER_CUSTOM_IKEv2_POLICY](https://learn.microsoft.com/windows/desktop/RRAS/router-management-data-types) instead ensures that the proper version, based on the operating system the code in compiled under, is used.

## Members

### `dwIntegrityMethod`

A value that specifies the integrity algorithm to be negotiated during IKEv2 main mode SA negotiation. The allowed values for this member are defined in [IKEEXT_INTEGRITY_TYPE](https://learn.microsoft.com/windows/desktop/api/iketypes/ne-iketypes-ikeext_integrity_type).

### `dwEncryptionMethod`

A value that specifies the encryption algorithm to be negotiated during IKEv2 main mode SA negotiation. The allowed valued for this member are defined in [IKEEXT_CIPHER_TYPE](https://learn.microsoft.com/windows/desktop/api/iketypes/ne-iketypes-ikeext_cipher_type).

### `dwCipherTransformConstant`

A value that specifies the encryption algorithm to be negotiated during IKEv2 quick mode SA negotiation. The allowed valued for this member are defined in [IPSEC_CIPHER_TYPE](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ne-ipsectypes-ipsec_cipher_type).

### `dwAuthTransformConstant`

A value that specifies the hash algorithm to be negotiated during IKEv2 quick mode SA negotiation. The allowed valued for this member are defined in [IPSEC_AUTH_TYPE](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ne-ipsectypes-ipsec_auth_type).

### `dwPfsGroup`

A value that specifies the Diffie Hellman algorithm that should be used for Quick Mode PFS (Perfect Forward Secrecy). The allowed valued for this member are defined in [IPSEC_PFS_GROUP](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ne-ipsectypes-ipsec_pfs_group).

### `dwDhGroup`

A value that specifies the type of Diffie Hellman group used for Internet Key Exchange (IKE) key generation during MM SA negotiation. The allowed valued for this member are defined in [IKEEXT_DH_GROUP](https://learn.microsoft.com/windows/desktop/api/iketypes/ne-iketypes-ikeext_dh_group).