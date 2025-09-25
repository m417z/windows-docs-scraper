# DsMakeSpnW function

## Description

The **DsMakeSpn** function constructs a service principal name (SPN) that identifies a service instance.

A client application uses this function to compose an SPN, which it uses to authenticate the service instance. For example, the client can pass an SPN in the *pszTargetName* parameter of the
[InitializeSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta) function.

## Parameters

### `ServiceClass` [in]

Pointer to a constant null-terminated string that specifies the class of the service. This parameter can be any string unique to that service; either the protocol name, for example, ldap, or the string form of a GUID are acceptable.

### `ServiceName` [in]

Pointer to a constant null-terminated string that specifies the DNS name, NetBIOS name, or distinguished name (DN). This parameter must be non-**NULL**.

For more information about how the *ServiceName*, *InstanceName* and *InstancePort* parameters are used to compose an SPN, see the following Remarks section.

### `InstanceName` [in, optional]

Pointer to a constant null-terminated string that specifies the DNS name or IP address of the host for an instance of the service.

If *ServiceName* specifies the DNS or NetBIOS name of the service host computer, the *InstanceName* parameter must be **NULL**.

If *ServiceName* specifies a DNS domain name, the name of a DNS SRV record, or a distinguished name, such as the DN of a service connection point, the *InstanceName* parameter must specify the DNS or NetBIOS name of the service host computer.

### `InstancePort` [in]

Port number for an instance of the service. Use 0 for the default port. If this parameter is zero, the SPN does not include a port number.

### `Referrer` [in, optional]

Pointer to a constant null-terminated string that specifies the DNS name of the host that gave an IP address referral. This parameter is ignored unless the *ServiceName* parameter specifies an IP address.

### `pcSpnLength` [in, out]

Pointer to a variable that contains the length, in characters, of the buffer that will receive the new constructed SPN. This value may be 0 to request the final buffer size in advance.

The *pcSpnLength* parameter also receives the actual length of the SPN created, including the terminating null character.

### `pszSpn` [out]

Pointer to a null-terminated string that receives the constructed SPN. This buffer should be the length specified by *pcSpnLength*. The *pszSpn* parameter may be **NULL** to request the final buffer size in advance.

## Return value

If the function returns an SPN, the return value is **ERROR_SUCCESS**. If the function fails, the return value can be one of the following error codes.

## Remarks

The format of the SPN produced by the **DsMakeSpn** function depends on the input parameters. There are two basic formats. Both formats begin with the *ServiceClass* string followed by a host computer name and an optional *InstancePort* component.

**Note** This format is used by host-based services.

**To produce an SPN with the "<ServiceClass>/<host>" format**

1. Set the *ServiceName* parameter to the DNS name of the host computer for the service instance. This is the host component of the SPN.
2. Set the *InstanceName* and *Referrer* parameters to **NULL**.
3. Set the *InstancePort* parameter to zero. If *InstancePort* is nonzero, the SPN has the following format:

   ```cpp
   <service class>/<host>:<instance port>/<referrer>
   ```

**Note** This format is used by replicable services.

**To produce an SPN with the "<ServiceClass>/<host>:<InstancePort>" format**

1. Set the *InstanceName* parameter to the DNS name of the host computer for the service instance. This is the host component.
2. Set the *ServiceName* parameter to a string that identifies an instance of the service. For example, it could be the distinguished name of the service connection point for this service instance.
3. Set the *Referrer* parameter to **NULL**.
4. Set the *InstancePort* parameter to zero. If *InstancePort* is nonzero, the SPN has the following format:

   ```cpp
   <service class>/<host>:<instance port>/<service name>
   ```

The *Referrer* parameter is used only if the *ServiceName* parameter specifies the IP address of the service's host computer. In this case, *Referrer* specifies the DNS name of the computer that gave the IP address as a referral. The SPN has the following format:

```cpp
<service class>/<host>:<instance port>/<referrer>
```

where the host component is the *InstanceName* string or the *ServiceName* string if *InstanceName* is **NULL**, and the *InstancePort* component is optional.

String parameters cannot include the forward slash (/) character, as it is used to separate the components of the SPN.

> [!NOTE]
> The dsparse.h header defines DsMakeSpn as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[InitializeSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta)