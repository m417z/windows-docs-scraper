# _D3DKMT_VIDSCH_ESCAPE structure

## Description

**Do not use the D3DKMT_VIDSCH_ESCAPE structure; it is for testing purposes only.**

The D3DKMT_VIDSCH_ESCAPE structure describes how to control the graphics processing unit (GPU) scheduler (which is part of Dxgkrnl.sys) in a call to the [D3DKMTEscape](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtescape) function.

## Members

### `Type`

The escape type, of type [D3DKMT_VIDSCHESCAPETYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_vidschescapetype), which is reserved and should not be used in your driver.

### `PreemptionControl`

Enable or disable preemption.

### `EnableContextDelay`

Enable or disable context delay.

### `TdrControl2`

### `TdrControl2.TdrControl`

Control TDR.

### `TdrControl2.NodeOrdinal`

Valid if **TdrControl** is set to a value of **D3DKMT_TDRDBGCTRLTYPE_ENGINETDR**.

### `SuspendScheduler`

Suspend or resume scheduler (obsolete).

### `TdrControl`

Control TDR.

### `SuspendTime`

Time period to suspend.

### `TdrLimit`

### `TdrLimit.Count`

### `TdrLimit.Time`

### `PfnControl`

## See also

[D3DKMTEscape](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtescape)

[D3DKMT_ESCAPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_escape)

[D3DKMT_VIDSCHESCAPETYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_vidschescapetype)