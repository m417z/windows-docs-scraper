# FsRtlInitializeExtraCreateParameterList function

## Description

The **FsRtlInitializeExtraCreateParameterList** routine initializes an extra create parameter (ECP) context structure list.

## Parameters

### `EcpList` [in, out]

Pointer to the [ECP_LIST](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85)) structure to initialize.

## Return value

**FsRtlInitializeExtraCreateParameterList** returns STATUS_SUCCESS if it successfully initialized the given [ECP_LIST](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85)) structure, and returns an error if it did not.

## See also

[ECP_LIST](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85))