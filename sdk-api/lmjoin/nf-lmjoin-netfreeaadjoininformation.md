# NetFreeAadJoinInformation function

## Description

Frees the memory allocated for the specified [DSREG_JOIN_INFO](https://learn.microsoft.com/windows/desktop/api/lmjoin/ns-lmjoin-dsreg_join_info) structure, which contains join information for a tenant and which you retrieved by calling the [NetGetAadJoinInformation](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netgetaadjoininformation) function.

## Parameters

### `pJoinInfo` [in, optional]

Pointer to the [DSREG_JOIN_INFO](https://learn.microsoft.com/windows/desktop/api/lmjoin/ns-lmjoin-dsreg_join_info) structure for which you want to free the memory.

## Return value

This function does not return a value.

## See also

[DSREG_JOIN_INFO](https://learn.microsoft.com/windows/desktop/api/lmjoin/ns-lmjoin-dsreg_join_info)

[NetGetAadJoinInformation](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netgetaadjoininformation)