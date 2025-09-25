# SspiGetTargetHostName function

## Description

Gets the host name associated with the specified target.

## Parameters

### `pszTargetName` [in]

The target for which to get the host name.

### `pszHostName` [out]

The name of the host associated with the target specified by the *pszTargetName* parameter.

## Return value

If the function succeeds, it returns **SEC_E_OK**.

If the function fails, it returns a nonzero error code.