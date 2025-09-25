# IRpcChannelBuffer::GetDestCtx

## Description

Retrieves the destination context for the RPC channel.

## Parameters

### `pdwDestContext` [out]

The destination context in which the interface is unmarshaled. Possible values come from the [MSHCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-mshctx) enumeration.

### `ppvDestContext` [out]

This parameter is reserved and must be **NULL**.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[IRpcChannelBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcchannelbuffer)