# IAzClientContext2::AddStringSids

## Description

The **AddStringSids** method adds an array of string representations of [security identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIDs) to the client context.

## Parameters

### `varStringSids` [in]

The array of string representations of SIDs to add to the client context.

## Return value

 If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).