# _D3DKMT_TDRDBGCTRLTYPE enumeration

## Description

**Do not use the D3DKMT_TDRDBGCTRLTYPE enumeration; it is for testing purposes only.**

The **D3DKMT_TDRDBGCTRLTYPE** enumeration type contains values that affect the behavior of the operating system's Timeout Detection and Recovery (TDR) process in a call to the OpenGL [D3DKMTEscape](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtescape) function.

## Constants

### `D3DKMT_TDRDBGCTRLTYPE_FORCETDR`

Simulate a TDR.

### `D3DKMT_TDRDBGCTRLTYPE_DISABLEBREAK`

Disable DebugBreak on timeout.

### `D3DKMT_TDRDBGCTRLTYPE_ENABLEBREAK`

Enable DebugBreak on timeout.

### `D3DKMT_TDRDBGCTRLTYPE_UNCONDITIONAL`

Disables all safety conditions (e.g. check for consecutive recoveries).

### `D3DKMT_TDRDBGCTRLTYPE_VSYNCTDR`

Simulate a Vsync TDR.

### `D3DKMT_TDRDBGCTRLTYPE_GPUTDR`

Simulate a GPU TDR.

### `D3DKMT_TDRDBGCTRLTYPE_FORCEDODTDR`

Simulate a display-only present TDR.

Supported starting with Windows 8.

### `D3DKMT_TDRDBGCTRLTYPE_FORCEDODVSYNCTDR`

Simulate a display-only VSync TDR.

Supported starting with Windows 8.

### `D3DKMT_TDRDBGCTRLTYPE_ENGINETDR`

Simulate an engine TDR.

Supported starting with Windows 8.

## See also

[D3DKMTEscape](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtescape)

[D3DKMT_ESCAPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_escape)