# NDR_USER_MARSHAL_INFO_LEVEL1 structure

## Description

The
**NDR_USER_MARSHAL_INFO_LEVEL1** structure holds information about the state of an RPC call that can be passed to
[wire_marshal](https://learn.microsoft.com/windows/desktop/Midl/wire-marshal) and
[user_marshal](https://learn.microsoft.com/windows/desktop/Midl/user-marshal) helper functions.

## Members

### `Buffer`

Pointer to the beginning of the marshaling buffer available for use by the helper function. If no buffer is available, this field is null.

### `BufferSize`

Size, in bytes, of the marshaling buffer available for use by the helper function. If no buffer is available, *BufferSize* is zero.

### `pfnAllocate`

Function used by RPC to allocate memory for the application. An example of the use of this function is to create a node.

### `pfnFree`

Function used by RPC to free memory for the application. An example of the use of this function is to free a node.

### `pRpcChannelBuffer`

If the current call is for a COM interface, this member is a pointer to the channel buffer that RPC uses for the call. Otherwise, this member is null.

### `Reserved`

Reserved for future use.