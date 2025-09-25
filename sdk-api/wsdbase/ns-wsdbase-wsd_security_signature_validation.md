# WSD_SECURITY_SIGNATURE_VALIDATION structure

## Description

Represents the criteria for matching client compact signatures against messages.

## Members

### `signingCertArray`

An array of [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) stuctures that contain certificates to be matched against a message. Only one matching certificate is required for validation. This parameter can be **NULL**.

### `dwSigningCertArrayCount`

The count of certificates in *signingMatchArray*.

### `hSigningCertStore`

A handle to a certificate store that contains certificates to be matched against a message. Only one matching certificate is required for validation. This parameter can be **NULL**.

### `dwFlags`

A flag that specifies how unsigned messages are handled. If set to **WSDAPI_COMPACTSIG_ACCEPT_ALL_MESSAGES**, then the discovery object will accept unsigned messages, signed-and-verified messages and signed-but-verified, (that is, those for which the signing cert could not be found either in the store or the certificate array) messages. If this flag is not set, then only the signed-and-verified messages will be accepted.

If **WSDAPI_COMPACTSIG_ACCEPT_ALL_MESSAGES** is specified, the caller will not be able use the [IWSDSignatureProperty](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdsignatureproperty) interface to learn whether the message was signed or not.

## Remarks

This structure is used in the **pConfigData** member of the [WSD_CONFIG_PARAM](https://learn.microsoft.com/windows/desktop/api/wsdbase/ns-wsdbase-wsd_config_param) structure when **configParamType** is set to **WSD_SECURITY_COMPACTSIG_VALIDATION**.

**WSD_SECURITY_SIGNATURE_VALIDATION** defines 2 matching mechanisms. To obtain a match, at least one such mechanism must be satisfied.