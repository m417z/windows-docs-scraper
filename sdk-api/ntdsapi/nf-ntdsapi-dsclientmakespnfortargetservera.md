# DsClientMakeSpnForTargetServerA function

## Description

The **DsClientMakeSpnForTargetServer** function constructs a service principal name (SPN) that identifies a specific server to use for authentication.

## Parameters

### `ServiceClass` [in]

Pointer to a null-terminated string that contains the class of the service as defined by the service. This can be any string unique to the service.

### `ServiceName` [in]

Pointer to a null-terminated string that contains the distinguished name service (DNS) host name. This can either be a fully qualified name or an IP address in the Internet standard format.

Use of an IP address for *ServiceName* is not recommended because this can create a security issue. Before the SPN is constructed, the IP address must be translated to a computer name through DNS name resolution. It is possible for the DNS name resolution to be spoofed, replacing the intended computer name with an unauthorized computer name.

### `pcSpnLength` [in, out]

Pointer to a **DWORD** value that, on entry, contains the size of the *pszSpn* buffer, in characters. On output, this parameter receives the number of characters copied to the *pszSpn* buffer, including the terminating **NULL**.

### `pszSpn` [out]

Pointer to a string buffer that receives the SPN.

## Return value

This function returns standard Windows error codes.

## Remarks

When using this function, supply the service class and part of a DNS host name.

This function is a simplified version of the [DsMakeSpn](https://learn.microsoft.com/windows/desktop/api/dsparse/nf-dsparse-dsmakespna) function. The *ServiceName* is made canonical by resolving through DNS.

GUID-based DNS names are not supported. When constructed, the simplified SPN is as follows:

``` syntax
ServiceClass / ServiceName / ServiceName
```

The instance name portion (second position) is always set to default. The port and referrer fields are not used.

> [!NOTE]
> The ntdsapi.h header defines DsClientMakeSpnForTargetServer as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsMakeSpn](https://learn.microsoft.com/windows/desktop/api/dsparse/nf-dsparse-dsmakespna)