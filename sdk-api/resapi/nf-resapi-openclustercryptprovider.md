# OpenClusterCryptProvider function

## Description

Opens a handle to a Cryptographic Service Provider (CSP) in order to manage the encryption of [Checkpointing](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/checkpointing) data for a cluster resource. The **POPEN_CLUSTER_CRYPT_PROVIDER** type defines a pointer to this function.

## Parameters

### `lpszResource` [in]

A pointer to a null-terminated Unicode string that contains the name of the cluster resource that is associated with the [Checkpointing](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/checkpointing) data.

### `lpszProvider` [in]

A pointer to a null-terminated Unicode string that contains the name of the CSP.

### `dwType` [in]

A bitmask that specifies the CSP type.

This parameter can be set to one of the following values:

#### PROV_RSA_FULL (1)

#### PROV_RSA_SIG (2)

#### PROV_DSS (3)

#### PROV_FORTEZZA (4)

#### PROV_MS_EXCHANGE (5)

#### PROV_SSL (6)

#### PROV_RSA_SCHANNEL (12)

#### PROV_DSS_DH (13)

#### PROV_EC_ECDSA_SIG (14)

#### PROV_EC_ECNRA_SIG (15)

#### PROV_EC_ECDSA_FULL (16)

#### PROV_EC_ECNRA_FULL (17)

#### PROV_DH_SCHANNEL (18)

#### PROV_SPYRUS_LYNKS (20)

#### PROV_RNG (21)

#### PROV_INTEL_SEC (22)

#### PROV_REPLACE_OWF (23)

#### PROV_RSA_AES (24)

### `dwFlags` [in]

The flags that specify the settings for the operation. This parameter can be set to the default value "0", or **CLUS_CREATE_CRYPT_CONTAINER_NOT_FOUND** (0x0001).

## Return value

If the operation completes successfully, this function returns a [HCLUSCRYPTPROVIDER](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn823545(v=vs.85)) structure containing a handle to the CSP.

## See also

[CloseClusterCryptProvider](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-closeclustercryptprovider)

[Cryptography Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cryptography-functions)