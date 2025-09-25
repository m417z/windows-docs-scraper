# TRANSPORT_STATE structure

## Description

The TRANSPORT_STATE structure

## Members

### `Mode`

Specifies the mode of the external device transport.

### `State`

Specifies the state of the external device transport mode.

## Remarks

Any ED_Xxx tokens are defined in *xprtdefs.h* in the Microsoft DirectX SDK.

The following modes and states are used by *msdv.sys* and *mstape.sys*:

When **Mode** equals ED_MODE_RECORD, **State** may be:

ED_MODE_RECORD

ED_MODE_RECORD_FREEZE.

When **Mode** equals ED_MODE_PLAY, **State** may be:

ED_MODE_PLAY

ED_MODE_REV_PLAY

ED_MODE_STEP_FWD

ED_MODE_STEP_REV

ED_MODE_PLAY_SLOWEST_FWD

ED_MODE_PLAY_FASTEST_FWD

ED_MODE_PLAY_SLOWEST_REV

ED_MODE_PLAY_FASTEST_REV

ED_MODE_FREEZE

**Mode** equals **State** in the cases of:

ED_MODE_REW_FASTEST

ED_MODE_STOP

ED_MODE_PLAY

ED_MODE_FF