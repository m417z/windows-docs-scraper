# BDA_DrmPairingError enumeration

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Specifies the status of a DRM handshake between a tuner and the user's computer.

## Constants

### `BDA_DrmPairing_Succeeded:0`

The handshake was successful.

### `BDA_DrmPairing_HardwareFailure`

A hardware failure occurred.

### `BDA_DrmPairing_NeedRevocationData`

The tuner could not obtain the certificate revocation list.

### `BDA_DrmPairing_NeedIndiv`

The tuner could not perform individualization.

### `BDA_DrmPairing_Other`

Network interface (SCTE 55-1).

### `BDA_DrmPairing_DrmInitFailed`

The handshake failed during the initialization step.

### `BDA_DrmPairing_DrmNotPaired`

The client has not requested a handshake or the handshake is still in progress.

### `BDA_DrmPairing_DrmRePairSoon`

The handshake was successful but will soon time out. The client should refresh the handshake soon.

### `BDA_DrmPairing_Aborted`

### `BDA_DrmPairing_NeedSDKUpdate`

## See also

[BDA Reference](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/bda-reference)

[IBDA_DRM::GetDRMPairingStatus](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_drm-getdrmpairingstatus)