# RpcCertGeneratePrincipalNameA function

## Description

Server programs use the
**RpcCertGeneratePrincipalName** function to generate
[principal names](https://learn.microsoft.com/windows/desktop/Rpc/principal-names) for security certificates.

## Parameters

### `Context`

Pointer to the security-certificate context.

### `Flags`

Currently, the only valid flag for this parameter is RPC_C_FULL_CERT_CHAIN. Using this flag causes the principal name to be generated in fullsic format.

### `pBuffer`

Pointer to a pointer. The
**RpcCertGeneratePrincipalName** function sets this to point at a null-terminated string that contains the
[principal name](https://learn.microsoft.com/windows/desktop/Rpc/principal-names).

## Return value

This function does not return a value.

## Remarks

By default, the principal name that the
**RpcCertGeneratePrincipalName** function passes back is in msstd format. To generate a name in fullsic format, pass RPC_C_FULL_CERT_CHAIN as the value for the *Flags* parameter.

Your application must call
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree) to release the memory for the string which contains the principal name.

> [!NOTE]
> The rpcssl.h header defines RpcCertGeneratePrincipalName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Principal Names](https://learn.microsoft.com/windows/desktop/Rpc/principal-names)

[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree)