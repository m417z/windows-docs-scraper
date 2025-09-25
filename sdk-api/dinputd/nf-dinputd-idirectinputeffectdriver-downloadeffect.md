# IDirectInputEffectDriver::DownloadEffect

## Description

The **IDirectInputEffectDriver::DownloadEffect** method sends an effect to the device.

## Parameters

### `unnamedParam1`

Specifies the external joystick number being addressed.

### `unnamedParam2`

Specifies the **dwEffectId** member of the [DIEFFECTATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/dinputd/ns-dinputd-dieffectattributes) structure associated with the effect the application is attempting to create. The DIEFFECTATTRIBUTES structure is stored in the registry under the corresponding effect registry key and can be any 32-bit value. DirectInput passes the 32-bit value to the driver with no interpretation.

### `unnamedParam3`

On entry, this parameter is a pointer to the handle of the effect being downloaded. If this parameter points to a zero, then a new effect is downloaded. On exit, this parameter is a pointer to a **DWORD**  that contains the new effect handle. On failure, the **DWORD** pointed to by this parameter is set to zero if the effect is lost, or left alone if the effect is still valid with its old parameters. Note that zero is never a valid effect handle.

### `unnamedParam4`

Points to a DIEFFECT structure that describes the new effect. The axis and button values have been converted to object identifiers, which consist of the following:

#### One type specifier:

##### DIDFT_RELAXIS

##### DIDFT_ABSAXIS

##### DIDFT_PSHBUTTON

##### DIDFT_TGLBUTTON

##### DIDFT_POV

#### One instance identifier:

##### DIDFT_MAKEINSTANCE(n)

Other bits in the object identifier are reserved and should be ignored.

For example, 0x02000104 = DIDFT_PSHBUTTON | DIDFT_MAKEINSTANCE(1) | other stuff

This value indicates that the effect uses button 1.

### `unnamedParam5`

Specifies which portions of the effect information have changed from the effect already applied to the device. This information is passed to drivers to allow for the optimization of effect modification. If an effect is being modified, a driver may be able to update the effect in its original position and transmit to the device only the information that has changed. Drivers are not, however, required to implement this optimization. All members in the DIEFFECT structure pointed to by the *peff* parameter are valid, and a driver may choose simply to update all parameters of the effect at each download. (For information about the DIEFFECT structure, see the DirectInput section of the stand alone DirectX SDK.)

This parameter can be zero, one, or more of the following:

#### DIEP_DURATION

Indicates the **dwDuration** member of the DIEFFECT structure is being downloaded for the first time or has changed since its last download.

#### DIEP_SAMPLEPERIOD

Indicates the **dwSamplePeriod** member of the DIEFFECT structure is being downloaded for the first time or has changed since its last download.

#### DIEP_GAIN

Indicates the **dwGain** member of the DIEFFECT structure is being downloaded for the first time or has changed since its last download.

#### DIEP_TRIGGERBUTTON

Indicates the **dwTriggerButton** member of the DIEFFECT structure is being downloaded for the first time or has changed since its last download.

#### DIEP_TRIGGERREPEATINTERVAL

Indicates the **dwTriggerRepeatInterval** member of the DIEFFECT structure is being downloaded for the first time or has changed since its last download.

#### DIEP_AXES

Indicates the **cAxes** and **rgdwAxes** members of the DIEFFECT structure are being downloaded for the first time or have changed since their last download.

#### DIEP_DIRECTION

Indicates the **cAxes** and **rglDirection** members of the DIEFFECT structure are being downloaded for the first time or have changed since their last download. (The **dwFlags** member of the DIEFFECT structure specifies, through DIEFF_CARTESIAN or DIEFF_POLAR, the coordinate system in which the values should be interpreted.)

#### DIEP_ENVELOPE

Indicates the **lpEnvelope** member of the DIEFFECT structure is being downloaded for the first time or has changed since its last download. If this flag is set and the **lpEnvelope** member is a **NULL** pointer, then the effect is being created with no envelope, or the existing envelope is being deleted.

#### DIEP_TYPESPECIFICPARAMS

Indicates the **cbTypeSpecificParams** and **lpTypeSpecificParams** members of the DIEFFECT structure are being downloaded for the first time or have changed since their last download.

#### DIEP_START

Indicates that the effect is to be restarted from the beginning after the parameters of the effect have been updated. Note that the DIEP_NODOWNLOAD flag overrides the DIEP_START flag.

#### DIEP_NORESTART

If this flag is not specified, the effect device driver is permitted to restart the effect if doing so is necessary to change the specified parameters. Note that the DIEP_NODOWNLOAD and DIEP_START flags override this flag.

#### DIEP_NODOWNLOAD

Suppresses the automatic download that is normally performed after the parameters are updated. If this flag is set, the driver should validate parameters without performing an actual download.

## Return value

Returns S_OK if successful, or an error value otherwise.