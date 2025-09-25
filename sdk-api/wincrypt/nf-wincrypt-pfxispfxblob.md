# PFXIsPFXBlob function

## Description

The **PFXIsPFXBlob** function attempts to decode the outer layer of a BLOB as a PFX packet.

## Parameters

### `pPFX` [in]

A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that the function will attempt to decode as a PFX packet.

## Return value

The function returns **TRUE** if the BLOB can be decoded as a PFX packet. If the outer layer of the BLOB cannot be decoded as a PFX packet, the function returns **FALSE**.

## See also

[PFXVerifyPassword](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-pfxverifypassword)