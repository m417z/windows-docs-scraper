# SrpSetTokenEnterpriseId function

## Description

**Note** Windows Information Protection (WIP) policy can be applied on Windows 10, version 1607.

Sets a data intent on a token. The caller process should be enterprise allowed for the provided enterprise ID.

If the caller intends to set a personal intent on the token, then NULL should be passed as enterprise ID.

## Parameters

### `tokenHandle` [in]

The token handle on which the intent is to be set.

### `enterpriseId` [in, optional]

The enterprise ID to set as intent.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.