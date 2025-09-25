# ICertConfig2::SetSharedFolder

## Description

The **SetSharedFolder** method specifies the path to be used as the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly)'s (CA) shared folder. This method was first defined in the [ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig) interface.

## Parameters

### `strSharedFolder` [in]

String value that specifies the path of the new shared folder directory.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).