# KSQUALITY structure

## Description

The KSQUALITY structure is used to report QM problems in both kernel and user mode to their respective quality managers.

## Members

### `Context`

Specifies a context parameter that was originally passed to the connection.

### `Proportion`

Indicates the percentage of frames currently being received that are actually being used. This is expressed in units of one-tenth of a percent, where 1000 is optimal.

### `DeltaTime`

Indicates the delta in native units (as indicated by the Interface) from optimal time at which the frames are being delivered, where a positive number means too late, and a negative number means too early. Zero indicates a correct delta.