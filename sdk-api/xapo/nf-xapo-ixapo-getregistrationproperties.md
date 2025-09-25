# IXAPO::GetRegistrationProperties

## Description

Returns the registration properties of an XAPO.

## Parameters

### `ppRegistrationProperties`

Receives a pointer to a [XAPO_REGISTRATION_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/xapo/ns-xapo-xapo_registration_properties) structure containing the registration properties the XAPO was created with; use [XAPOFree](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-xapofree) to free the structure.

## Return value

Returns S_OK if successful; returns an error code otherwise.

## Remarks

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAPO](https://learn.microsoft.com/windows/desktop/api/xapo/nn-xapo-ixapo)