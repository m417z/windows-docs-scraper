# RpcNsEntryExpandNameA function

## Description

The
**RpcNsEntryExpandName** function expands a name-service entry name. This function is supported by Active Directory.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `EntryNameSyntax`

Syntax of *EntryName*.

To use the syntax specified in the registry value entry **HKEY_LOCAL_MACHINE\Software\Microsoft\Rpc\NameService\DefaultSyntax**, provide a value of **RPC_C_NS_SYNTAX_DEFAULT**.

### `EntryName`

Pointer to the entry name to expand.

### `ExpandedName`

Returns a pointer to a pointer to the expanded version of *EntryName*.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INCOMPLETE_NAME** | The name is incomplete. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

An application calls the
**RpcNsEntryExpandName** function to obtain a fully expanded entry name.

The RPC run-time library allocates memory for the returned *ExpandedName* parameter. The application is responsible for calling the
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree) function for that returned string.

The returned expanded entry name accounts for local name translations and for differences in locally defined naming schema.

**Note** This function requires Active Directory support.

> [!NOTE]
> The rpcnsi.h header defines RpcNsEntryExpandName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree)