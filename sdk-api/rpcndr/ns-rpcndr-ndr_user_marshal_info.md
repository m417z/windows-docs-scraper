# NDR_USER_MARSHAL_INFO structure

## Description

The
**NDR_USER_MARSHAL_INFO** structure holds information about the state of an RPC call that can be passed to
[wire_marshal](https://learn.microsoft.com/windows/desktop/Midl/wire-marshal) and
[user_marshal](https://learn.microsoft.com/windows/desktop/Midl/user-marshal) helper functions.

## Members

### `InformationLevel`

The information level of the returned data. Currently only a value of 1 is defined.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Level1`

An
[NDR_USER_MARSHAL_INFO_LEVEL1](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-ndr_user_marshal_info_level1) structure.

## Remarks

The function
[NdrGetUserMarshalInfo](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-ndrgetusermarshalinfo) fills this structure with supplemental information for the
[user_marshal](https://learn.microsoft.com/windows/desktop/Midl/user-marshal) and
[wire_marshal](https://learn.microsoft.com/windows/desktop/Midl/wire-marshal) helper functions <type>_UserSize, <type>_UserMarshal, <type>_UserUnmarshal, and <type>_UserFree. This information supplements the *pFlags* parameter that is passed to these helper functions. Not all of these fields will contain valid information in all contexts. Level1.pRpcChannelBuffer is only valid for COM interfaces, and the buffer fields are only valid when
**NdrGetUserMarshalInfo** is called from <type>_UserMarshal or <type>_UserUnmarshal.