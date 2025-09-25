# PFND3DKMT_SETSTEREOENABLED callback function

## Description

The PFND3DKMT_SETSTEREOENABLED callback function retrieves a Boolean value that indicates whether the operating system's stereoscopic 3-D display behavior is enabled.

## Parameters

### `unnamedParam1:`

*\_In\_* *bStereoEnabled*

**TRUE** if the operating system's stereoscopic 3-D display behavior is enabled; **FALSE** otherwise.

## Return value

Returns STATUS_SUCCESS if the function completed successfully.

This function might also return other NTSTATUS values.

## Prototype

```cpp
//Declaration

PFND3DKMT_SETSTEREOENABLED D3DKMTSetStereoEnabled;

// Definition

_Check_return_ NTSTATUS APIENTRY D3DKMTSetStereoEnabled(
  _In_ BOOL bStereoEnabled
);

```

## Remarks

## See also