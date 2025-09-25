# RpcMgmtEpEltInqNextW function

## Description

The
**RpcMgmtEpEltInqNext** function returns one element from an endpoint map.

## Parameters

### `InquiryContext`

Specifies an inquiry context. The inquiry context is returned from
[RpcMgmtEpEltInqBegin](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtepeltinqbegin).

### `IfId`

Returns the interface identifier of the endpoint-map element.

### `Binding`

Optional. Returns the binding handle from the endpoint-map element.

### `ObjectUuid`

Optional. Returns the object UUID from the endpoint-map element.

### `Annotation`

Optional. Returns the annotation string for the endpoint-map element. When there is no annotation string in the endpoint-map element, the empty string ("") is returned.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcMgmtEpEltInqNext** function returns one element from the endpoint map. Elements selected depend on the inquiry context. The selection criteria are determined by *InquiryType* of the
[RpcMgmtEpEltInqBegin](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtepeltinqbegin) function that returned *InquiryContext*.

An application can view all the selected endpoint-map elements by repeatedly calling
**RpcMgmtEpEltInqNext**. When all the elements have been viewed, this function returns an RPC_X_NO_MORE_ENTRIES status. The returned elements are unordered.

When the respective arguments are non-NULL, the RPC run-time function library allocates memory for *Binding* and *Annotation* on each call to this function. The application is responsible for calling
[RpcBindingFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfree) for each returned *Binding* and
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree) for each returned *Annotation*.

After viewing the endpoint-map elements, the application must call
[RpcMgmtEpEltInqDone](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtepeltinqdone) to delete the inquiry context.

> [!NOTE]
> The rpcdce.h header defines RpcMgmtEpEltInqNext as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcEpRegister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregister)

[RpcMgmtEpEltInqBegin](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtepeltinqbegin)

[RpcMgmtEpEltInqDone](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtepeltinqdone)