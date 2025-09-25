# NdrGetUserMarshalInfo function

## Description

The
**NdrGetUserMarshalInfo** function provides additional information to wire_marshal and user_marshal helper functions.

## Parameters

### `pFlags`

Pointer by the same name that RPC passed to the helper function.

### `InformationLevel`

Desired level of detail to be received. Different levels imply different sets of information fields. Only level 1 is currently defined.

### `pMarshalInfo`

Address of a memory buffer, supplied by the application, to receive the requested information. The buffer must be at least as large as the information structure indicated by *InformationLevel*.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_ARG** | At least one of the arguments was not valid. |
| **RPC_X_INVALID_BUFFER** | Current marshaling buffer was not valid. |

## Remarks

The
**NdrGetUserMarshalInfo** function is called by the **wire_marshal** or **user_marshal** helper functions (provided by the application) <*type*>**_UserSize**, <*type*>**_UserMarshal**, <*type*>**_UserUnmarshal**, and <*type*>**_UserFree** to receive extra information about the state of the call. A common use for this function is to obtain the size of the marshaling buffer for the purpose of checking for end of buffer conditions. Sending incorrectly sized data is a commonly used method of breaching system security.

For a full listing of the information returned by
**NdrGetUserMarshalInfo**, see
[NDR_USER_MARSHAL_INFO](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-ndr_user_marshal_info).

## See also

[NDR_USER_MARSHAL_INFO](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-ndr_user_marshal_info)

[user_marshal](https://learn.microsoft.com/windows/desktop/Midl/user-marshal)

[wire_marshal](https://msdn.microsoft.com/)