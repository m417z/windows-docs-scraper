# RpcNsProfileEltInqBeginW function

## Description

The
**RpcNsProfileEltInqBegin** function creates an inquiry context for viewing the elements in a profile.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `ProfileNameSyntax`

Syntax of *ProfileName*.

To use the syntax specified in the registry value entry **HKEY_LOCAL_MACHINE\Software\Microsoft\Rpc\NameService\DefaultSyntax**, provide a value of RPC_C_NS_SYNTAX_DEFAULT.

### `ProfileName`

Pointer to the name of the profile to view.

### `InquiryType`

Type of inquiry to perform on the profile. The following table lists valid inquiry types.

| Inquiry type | Meaning |
| --- | --- |
| **RPC_C_PROFILE_DEFAULT_ELT** | Searches the profile for the default profile element, if any. The *IfId*, *VersOption*, and *MemberName* parameters are ignored. |
| **RPC_C_PROFILE_ALL_ELTS** | Returns every element from the profile. The *IfId*, *VersOption*, and *MemberName* parameters are ignored. |
| **RPC_C_PROFILE_MATCH_BY_IF** | Searches the profile for elements that contain the interface identification specified by *IfId* and *VersOption*. The *MemberName* parameter is ignored. |
| **RPC_C_PROFILE_MATCH_BY_MBR** | Searches the profile for elements that contain *MemberName*. The *IfId* and *VersOption* parameters are ignored. |
| **RPC_C_PROFILE_MATCH_BY_BOTH** | Searches the profile for elements that contain the interface identification and member identified by the *IfId*, *VersOption*, and *MemberName* parameters. |

### `IfId`

Pointer to the interface identification of the profile elements to be returned by the
[RpcNsProfileEltInqNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofileeltinqnexta) function.

The *IfId* parameter is used only when specifying a value of RPC_C_PROFILE_MATCH_BY_IF or RPC_C_PROFILE_MATCH_BY_BOTH for the *InquiryType* parameter. Otherwise, *IfId* is ignored and a null value can be specified.

### `VersOption`

Specifies how the
[RpcNsProfileEltInqNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofileeltinqnexta) function uses the *IfId* parameter. This parameter is used only when specifying a value of RPC_C_PROFILE_MATCH_BY_IF or RPC_C_PROFILE_MATCH_BY_BOTH for *InquiryType*. Otherwise, this parameter is ignored and a 0 value can be specified.

The following table describes valid values for *VersOption*.

| Value | Meaning |
| --- | --- |
| **RPC_C_VERS_ALL** | Returns profile elements that offer the specified interface UUID, regardless of the version numbers. For this value, specify 0 for both the major and minor versions in *IfId*. |
| **RPC_C_VERS_COMPATIBLE** | Returns profile elements that offer the same major version of the specified interface UUID and a minor version greater than or equal to the minor version of the specified interface UUID. |
| **RPC_C_VERS_EXACT** | Returns profile elements that offer the specified version of the specified interface UUID. |
| **RPC_C_VERS_MAJOR_ONLY** | Returns profile elements that offer the same major version of the specified interface UUID (ignores the minor version). For this value, specify 0 for the minor version in *IfId*. |
| **RPC_C_VERS_UPTO** | Returns profile elements that offer a version of the specified interface UUID less than or equal to the specified major and minor version. (For example, if the *IfId* contained V2.0 and the profile contained elements with V1.3, V2.0, and V2.1, the [RpcNsProfileEltInqNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofileeltinqnexta) function returns elements with V1.3 and V2.0.) |

### `MemberNameSyntax`

Syntax of *MemberName*, and the return parameter *MemberName* in the
[RpcNsProfileEltInqNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofileeltinqnexta) function.

To use the syntax specified in the registry value entry **HKEY_LOCAL_MACHINE\Software\Microsoft\Rpc\NameService\DefaultSyntax**, provide a value of RPC_C_NS_SYNTAX_DEFAULT.

### `MemberName`

Pointer to the member name that the
[RpcNsProfileEltInqNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofileeltinqnexta) function looks for in profile elements. The *MemberName* parameter is used only when specifying a value of RPC_C_PROFILE_MATCH_BY_MBR or RPC_C_PROFILE_MATCH_BY_BOTH for *InquiryType*. Otherwise, *MemberName* is ignored and a null value can be specified.

### `InquiryContext`

Returns a pointer to a name-service handle for use with the
[RpcNsProfileEltInqNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofileeltinqnexta) and
[RpcNsProfileEltInqDone](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofileeltinqdone) functions.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_VERS_OPTION** | The version option is invalid. |
| **RPC_S_INVALID_NAME_SYNTAX** | The name syntax is invalid. |
| **RPC_S_UNSUPPORTED_NAME_SYNTAX** | The name syntax is not supported. |
| **RPC_S_INCOMPLETE_NAME** | The name is incomplete. |
| **RPC_S_ENTRY_NOT_FOUND** | The name-service entry was not found. |
| **RPC_S_NAME_SERVICE_UNAVAILABLE** | The name service is unavailable. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcNsProfileEltInqBegin** function creates an inquiry context for viewing the elements in a profile.

Using the *InquiryType* parameter, an application specifies which of the following profile elements are to be returned from calls to
[RpcNsProfileEltInqNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofileeltinqnexta):

* The default element
* All elements
* Elements with the specified interface identification
* Elements with the specified member name
* Elements with both the specified interface identification and member name

Before calling
[RpcNsProfileEltInqNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofileeltinqnexta), the application must first call
**RpcNsProfileEltInqBegin** to create an inquiry context.

When finished viewing the profile elements, the application calls the
[RpcNsProfileEltInqDone](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofileeltinqdone) function to delete the inquiry context.

**Note** Windows 2000 Active Directory supports this function. Earlier versions of Windows NT support the use of this function with Cell Directory Service (CDS) only.

> [!NOTE]
> The rpcnsi.h header defines RpcNsProfileEltInqBegin as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcIfInqId](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcifinqid)

[RpcNsProfileEltInqDone](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofileeltinqdone)

[RpcNsProfileEltInqNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofileeltinqnexta)