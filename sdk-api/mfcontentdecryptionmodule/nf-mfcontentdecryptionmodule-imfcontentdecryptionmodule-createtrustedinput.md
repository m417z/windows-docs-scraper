## Description

Creates an [IMFTrustedInput](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imftrustedinput) object that implements the decryption of content.

## Parameters

### `contentInitData`

A **BYTE** array containing initialization data. *contentInitData* will only be used if initData from [IMFContentDecryptionModuleSession::GenerateRequest](https://learn.microsoft.com/windows/win32/api/mfcontentdecryptionmodule/nf-mfcontentdecryptionmodule-imfcontentdecryptionmodulesession-generaterequest) is not provided or incomplete. Initialization Data should be structured in PSSH Box Format. For more details, see the Encrypted Media Extension specification's [Common SystemID and PSSH Box Format](https://www.w3.org/TR/eme-initdata-cenc/#common-system).

### `contentInitDataSize`

The size of the array in *contentInitData*.

### `trustedInput`

Receives the created **IMFTrustedInput** object.

## Return value

Returns S_OK on success.

## Remarks

An implementation of a Content Decryption Module (CDM) may include an implementation of [IMFInputTrustAuthority](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfinputtrustauthority) obtained by calling **CreateTrustedInput**.

The following attributes are supported for **IMFInputTrustAuthority** decrypter.

| Property |Description
|-----------------------------------------------|---------------------------------------------------------------|
| [MFT_POLICY_SET_AWARE](https://learn.microsoft.com/windows/win32/medfound/mft-policy-set-aware) | If non-zero, indicates that the **IMFTransform** wants to receive [MEPolicySet](https://learn.microsoft.com/windows/win32/medfound/mepolicyset) completion notifications.|
| [MFT_USING_HARDWARE_DRM](https://learn.microsoft.com/windows/win32/medfound/mft-using-hardware-drm) | Specifies whether the IMFTransform is using hardware DRM. If an MFT decrypter specifies this attribute set to 1, then it is using hardware DRM. If an MFT decrypter specifies this attribute set to 0, then it is not using hardware DRM. If an MFT decrypter does not specify this attribute or specifies it with a different value, then it does not (or is unable to) indicate whether it is using hardware DRM. |

## See also

[IMFTrustedInput](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imftrustedinput)