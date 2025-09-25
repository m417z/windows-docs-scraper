# FsRtlIsEcpFromUserMode function

## Description

The **FsRtlIsEcpFromUserMode** routine determines whether an extra create parameter (ECP) context structure originated from user mode.

## Parameters

### `EcpContext` [in]

Pointer to the ECP context structure to test.

## Return value

**FsRtlIsEcpFromUserMode** returns **TRUE** if the ECP context structure originated in user mode and **FALSE** if the ECP context structure originated in kernel mode.