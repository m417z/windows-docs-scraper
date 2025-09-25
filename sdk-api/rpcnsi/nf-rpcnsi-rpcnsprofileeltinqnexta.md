# RpcNsProfileEltInqNextA function

## Description

The
**RpcNsProfileEltInqNext** function returns one element at a time from a profile.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `InquiryContext`

Name-service handle returned from the
[RpcNsProfileEltInqBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofileeltinqbegina) function.

### `IfId`

Returns a pointer to the interface identification of the profile element.

### `MemberName`

Returns a pointer to a pointer to the profile element's member name.The syntax of the returned name was specified by the *MemberNameSyntax* parameter in the
[RpcNsProfileEltInqBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofileeltinqbegina) function.

Specify a null value to prevent
**RpcNsProfileEltInqNext** from returning the *MemberName* parameter. In this case, the application does not call the
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree) function.

### `Priority`

Returns a pointer to the profile-element priority.

### `Annotation`

Returns a pointer to a pointer to the annotation string for the profile element. If there is no annotation string in the profile element, the string \0 is returned.

Specify a null value to prevent
**RpcNsProfileEltInqNext** from returning the *Annotation* parameter. In this case, the application does not need to call the
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree) function.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INCOMPLETE_NAME** | The name is incomplete. |
| **RPC_S_NAME_SERVICE_UNAVAILABLE** | The name service is unavailable. |
| **RPC_S_NO_MORE_ELEMENTS** | No more elements. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcNsProfileEltInqNext** function returns one element from the profile specified by the *ProfileName* parameter in
[RpcNsProfileEltInqBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofileeltinqbegina). Regardless of the value of *InquiryType* in
**RpcNsProfileEltInqBegin**,
**RpcNsProfileEltInqNext** returns all the components (interface identification, member name, priority, annotation string) of a profile element.

An application can view all the selected profile entries by repeatedly calling the
**RpcNsProfileEltInqNext** function. When all the elements have been viewed, this function returns a RPC_S_NO_MORE_ELEMENTS status code. The returned elements are unordered.

On each call to
**RpcNsProfileEltInqNext** that returns a profile element, the RPC run-time library allocates memory for the returned member name and annotation string. The application is responsible for calling the
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree) function for each returned member name and annotation string. After viewing the profile's elements, the application must call
[RpcNsProfileEltInqDone](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofileeltinqdone) to release the inquiry context.

**Note** Windows 2000 Active Directory supports this function. Earlier versions of Windows NT support the use of this function with Cell Directory Service (CDS) only.

> [!NOTE]
> The rpcnsi.h header defines RpcNsProfileEltInqNext as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcNsProfileEltInqBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofileeltinqbegina)

[RpcNsProfileEltInqDone](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofileeltinqdone)

[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree)