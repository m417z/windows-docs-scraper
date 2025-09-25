## Description

Indicates TLS parameter restrictions.

## Members

### `cAlpnIds`

The number of ALPN Ids in rgstrAlpnIds.

Set to 0 if the following parameter restrictions apply regardless of the negotiated application protocol. It is an error to specify more than SCH_CRED_MAX_SUPPORTED_ALPN_IDS.

### `rgstrAlpnIds`

An array of ALPN IDs that the following parameters apply to.

Set to NULL if parameter restrictions apply regardless of the negotiated application protocol.

### `grbitDisabledProtocols`

The bit string that represents the disabled protocols.

Set to 0 to use system defaults. Schannel protocol flags are [documented here.](https://learn.microsoft.com/windows/win32/api/schannel/ns-schannel-schannel_cred)

### `cDisabledCrypto`

The count of entries in the pDisabledCrypto array. It is an error to specify more than SCH_CRED_MAX_SUPPORTED_CRYPTO_SETTINGS.

### `pDisabledCrypto`

An array of pointers to the CRYPTO_SETTINGS structures that express disabled cryptographic settings.

### `dwFlags`

(*optional*) The flags to pass.

When TLS_PARAMS_OPTIONAL is set, TLS_PARAMETERS will only be honored if they do not cause the server to terminate the handshake.

Otherwise, schannel may fail TLS handshakes in order to honor the TLS_PARAMETERS restrictions.

> [!NOTE]
> TLS_PARAMS_OPTIONAL is valid for server applications only. Must be zero otherwise.

## Remarks

## See also

[SCH_CREDENTIALS](https://learn.microsoft.com/windows/win32/api/schannel/ns-schannel-sch_credentials)

[CRYPTO_SETTINGS](https://learn.microsoft.com/windows/win32/api/schannel/ns-schannel-crypto_settings)