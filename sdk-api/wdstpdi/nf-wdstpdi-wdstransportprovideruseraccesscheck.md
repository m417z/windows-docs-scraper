# WdsTransportProviderUserAccessCheck function

## Description

Specifies access to a content stream based on a user's token.

## Parameters

### `hContent` [in]

Handle to an open content stream to be read. This is the handle return by the [WdsTransportProviderOpenContent](https://learn.microsoft.com/windows/desktop/api/wdstpdi/nf-wdstpdi-wdstransportprovideropencontent) callback.

### `hUserToken` [in]

The token of the user whose access should be checked.

### `pbAccessAllowed` [out]

Pointer to a boolean value. The content provider should set this value to **TRUE** if it allows the user access to the content stream. The content provider should set this value to **FALSE** if it does not allow the user access to the content stream.

## Return value

If the function succeeds, the return is **S_OK**.

## Remarks

This callback is required.