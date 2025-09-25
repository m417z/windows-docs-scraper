# IMAPI_BURN_VERIFICATION_LEVEL enumeration

## Description

Defines values for the burn verification implemented by the [IBurnVerification](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iburnverification) interface.

## Constants

### `IMAPI_BURN_VERIFICATION_NONE:0`

No burn verification.

### `IMAPI_BURN_VERIFICATION_QUICK:1`

A quick, heuristic burn verification.

### `IMAPI_BURN_VERIFICATION_FULL:2`

This verification compares the checksum to the referenced stream for either the last session or each track. A full verification includes the heuristic checks of a quick verification for both burn formats.

## Remarks

Depending on the format used for the burned media, the values defined by this enumeration will elicit the following behavior during verification:

| MsftDiscFormat2Data |  |
| --- | --- |
| None | No burn verification. |
| Quick Verification | * READ_DISC_INFO command works and data appears correct<br>* READ_TRACK_INFO command works on all tracks<br>* Checksum comparison of a small set of disc sectors to stream bits |
| Full Verification | * Performs the same heuristic checks as the 'Quick' method, but will also read the entire last session and compare a checksum to the burned stream. |

| MsftDiscFormat2TrackAtOnce |  |
| --- | --- |
| None | No burn verification. |
| Quick Verification | After adding each track:<br><br>* READ_TRACK_INFO command for last track appears correct<br><br>When finishing the disc:<br><br>* READ_DISC_INFO command appears correct<br>* TOC appears correct |
| Full Verification | Full verification is not supported with this format. |

The time required for a full verification is relative to the read speed of the device and storage medium.

This enumeration is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IBurnVerfication](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iburnverification)