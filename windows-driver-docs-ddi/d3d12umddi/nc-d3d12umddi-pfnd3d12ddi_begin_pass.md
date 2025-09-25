# PFND3D12DDI_BEGIN_PASS callback function

## Description

The driver is notified that the app has started of a pass of consistent workloads. When the driver is notified that an app pass has started, the driver either records observations or uses optimizations that have been discovered.

## Parameters

### `unnamedParam1`

A handle to the driver's data for the command list. The driver uses this region of memory to store internal data structures that are related to its command list.

### `unnamedParam2`

A handle to the pass that was created by the app.

### `PassFlags`

A flag to indicate what the driver should do when an app starts a pass.

## Prototype

```
//Declaration

PFND3D12DDI_BEGIN_PASS Pfnd3d12ddiBeginPass;

// Definition

VOID Pfnd3d12ddiBeginPass
(
	D3D12DDI_HCOMMANDLIST Arg1
	D3D12DDI_HPASS Arg2
	D3D12DDI_PASS_FLAGS PassFlags
)
{...}

```

## Remarks

This callback is used as part of a test to see if drivers can find perf wins from being told when apps are repeating "passes" of consistent workloads. The app instructs the driver to observe how some passes run and gives the driver a chance to make optimizations for future runs of the same pass. The contents of a "pass" can be anything - it is up to the app to be relatively consistent in the overall performance characteristics of a pass.

## See also