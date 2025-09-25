# _UNIT_DIAG_LEVEL structure

## Description

The UNIT_DDI_VERSION structure is used in conjunction with the [Av61883_GetUnitInfo](https://learn.microsoft.com/previous-versions/ff536983(v=vs.85)) request to retrieve the current diag level

## Members

### `DiagLevel`

The bitmask representing the diaglevel. Possible settings are:

#### DIAGLEVEL_NONE

Nothing set.

#### DIAGLEVEL_IGNORE_OPLUG

Ignore programming of the oPCR plug on the device when set.

#### DIAGLEVEL_IGNORE_IPLUG

Ignore programming of the iPCR on the device when set.

#### DIAGLEVEL_SET_CHANNEL_63

Set the channel to 63 when disconnecting from the device.

#### DIAGLEVEL_IPCR_IGNORE_FREE

Do not free isochronous resources when disconnecting from the device iPCR.

## See also

[Av61883_GetUnitInfo](https://learn.microsoft.com/previous-versions/ff536983(v=vs.85))