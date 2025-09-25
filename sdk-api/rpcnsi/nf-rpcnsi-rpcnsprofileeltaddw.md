# RpcNsProfileEltAddW function

## Description

The
**RpcNsProfileEltAdd** function adds an element to a profile. If necessary, it creates the entry.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `ProfileNameSyntax`

Syntax of *ProfileName*.

To use the syntax specified in the registry value entry **HKEY_LOCAL_MACHINE\Software\Microsoft\Rpc\NameService\DefaultSyntax**, provide a value of RPC_C_NS_SYNTAX_DEFAULT.

### `ProfileName`

Pointer to the name of the profile to receive a new element.

### `IfId`

Pointer to the interface identification of the new profile element. To add or replace the default profile element, specify a null value.

### `MemberNameSyntax`

Syntax of *MemberName*.

To use the syntax specified in the registry value entry **HKEY_LOCAL_MACHINE\Software\Microsoft\Rpc\NameService\DefaultSyntax**, provide a value of RPC_C_NS_SYNTAX_DEFAULT.

### `MemberName`

Pointer to a name service–entry name to include in the new profile element.

### `Priority`

Integer value (0 through 7) that indicates the relative priority for using the new profile element during the import and lookup operations. A value of 0 is the highest priority; a value of 7 is the lowest priority. When adding a default profile member, use a value of 0.

### `Annotation`

Pointer to an annotation string stored as part of the new profile element. Specify a null value or a null-terminated string if there is no annotation string.

The string is used by applications for informational purposes only. For example, an application can use this string to store the interface-name string specified in the IDL file. RPC does not use the annotation string during lookup or import operations or for enumerating profile elements.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_NAME_SYNTAX** | The name syntax is invalid. |
| **RPC_S_UNSUPPORTED_NAME_SYNTAX** | The name syntax is not supported. |
| **RPC_S_INCOMPLETE_NAME** | The name is incomplete. |
| **RPC_S_NAME_SERVICE_UNAVAILABLE** | The name service is unavailable. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcNsProfileEltAdd** function adds an element to the profile attribute of the name-service entry specified by *ProfileName*. If the *ProfileName* entry does not exist,
**RpcNsProfileEltAdd** tries to create the entry with a profile attribute and adds the profile element specified by the *IfId*, *MemberName*, *Priority*, and *Annotation* parameters. In this case, the application must have the privilege to create the entry. Otherwise, a management application with the necessary privileges should create the entry by calling the
[RpcNsMgmtEntryCreate](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsmgmtentrycreatea) function before the application is run.

If an element with the specified member name and interface identification is already in the profile,
**RpcNsProfileEltAdd** updates the element's priority and annotation string using the values provided in the *Priority* and *Annotation* parameters.

**Note** The Windows 2000 Active Directory supports this function. Earlier versions of Windows NT support the use of this function with Cell Directory Service (CDS) only.

> [!NOTE]
> The rpcnsi.h header defines RpcNsProfileEltAdd as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcIfInqId](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcifinqid)

[RpcNsMgmtEntryCreate](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsmgmtentrycreatea)

[RpcNsProfileEltRemove](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofileeltremovea)