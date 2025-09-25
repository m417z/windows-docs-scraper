# SSTP_CERT_INFO structure

## Description

The **SSTP_CERT_INFO** structure contains information about a Secure Socket Tunneling Protocol (SSTP) based certificate.

## Members

### `isDefault`

A value that is **TRUE** if this is the default mode, and **FALSE** otherwise.

**Note** Default mode is when the administrator has not explicitly configured the device and the SSTP service automatically chooses a valid certificate.

### `certBlob`

A [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the SSTP based certificate hash.

The **cbData** member contains the length, in bytes, of the certificate hash in the **pbData** member. If **cbData** is zero, the SSTP certificate configuration is cleaned and the SSTP service automatically chooses a valid certificate. The hashing algorithm used to calculate **pbData** is defined by the **certAlgorithm** member of the [SSTP_CONFIG_PARAMS](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-sstp_config_params) structure.

## See also

[MPRAPI_TUNNEL_CONFIG_PARAMS](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mprapi_tunnel_config_params0)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)

[Router Management Structures](https://learn.microsoft.com/windows/desktop/RRAS/router-management-structures)

[SSTP_CONFIG_PARAMS](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-sstp_config_params)