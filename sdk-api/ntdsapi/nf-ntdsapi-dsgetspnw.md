# DsGetSpnW function

## Description

The **DsGetSpn** function constructs an array of one or more service principal names (SPNs). Each name in the array identifies an instance of a service. These SPNs may be registered with the directory service (DS) using the
[DsWriteAccountSpn](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dswriteaccountspna) function.

## Parameters

### `ServiceType` [in]

Identifies the format of the SPNs to compose. The *ServiceType* parameter can have one of the following values.

#### DS_SPN_DNS_HOST, DS_SPN_DN_HOST, DS_SPN_NB_HOST

The SPNs have the following format.

```cpp
ServiceClass/ InstanceName: InstancePort
```

The *ServiceName* parameter must be **NULL**. This is the SPN format for a host-based service, which provides services identified with its host computer. The *InstancePort* component is optional.

#### DS_SPN_DOMAIN, DS_SPN_NB_DOMAIN

The SPNs have the following format.

```cpp
ServiceClass/ InstanceName: InstancePort/ ServiceName
```

The *ServiceName* parameter must be the DNS name or DN of a domain. This format is used for a replicable service that provides services to the specified domain.

#### DS_SPN_SERVICE

The SPNs have the following format.

```cpp
ServiceClass/ InstanceName: InstancePort/ ServiceName
```

The *ServiceName* parameter must be a canonical DN or DNS name that identifies an instance of the service. For example, it could be a DNS name of a SRV record, or the distinguished name of the service connection point for this service instance.

### `ServiceClass` [in]

Pointer to a constant null-terminated string that specifies the class of the service; for example, http. Generally, this can be any string that is unique to the service.

### `ServiceName` [in, optional]

Pointer to a constant null-terminated string that specifies the DNS name or distinguished name (DN) of the service. *ServiceName* is not required for a host-based service. For more information, see the description of the *ServiceType* parameter for the possible values of *ServiceName*.

### `InstancePort` [in]

Specifies the port number of the service instance. If this value is zero, the SPN does not include a port number.

### `cInstanceNames` [in]

Specifies the number of elements in the *pInstanceNames* and *pInstancePorts* arrays. If this value is zero, *pInstanceNames* must point to an array of *cInstanceNames* strings, and *pInstancePorts* can be either **NULL** or a pointer to an array of *cInstanceNames* port numbers. If this value is zero, **DsGetSpn** returns only one SPN in the *prpszSpn* array and *pInstanceNames* and *pInstancePorts* are ignored.

### `pInstanceNames` [in, optional]

Pointer to an array of null-terminated strings that specify extra instance names (not used for host names). This parameter is ignored if *cInstanceNames* is zero. In that case, the *InstanceName* component of the SPN defaults to the fully qualified DNS name of the local computer or the NetBIOS name if **DS_SPN_NB_HOST** or **DS_SPN_NB_DOMAIN** is specified.

### `pInstancePorts` [in, optional]

Pointer to an array of extra instance ports. If this value is non-**NULL**, it must point to an array of *cInstanceNames* port numbers. If this value is **NULL**, the SPNs do not include a port number. This parameter is ignored if *cInstanceNames* is zero.

### `pcSpn` [out]

Pointer to a variable that receives the number of SPNs contained in *prpszSpn*.

### `prpszSpn` [out]

Pointer to a variable that receives a pointer to an array of SPNs. This array must be freed with
[DsFreeSpnArray](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsfreespnarraya).

##### - ServiceType.DS_SPN_DNS_HOST, DS_SPN_DN_HOST, DS_SPN_NB_HOST

The SPNs have the following format.

```cpp
ServiceClass/ InstanceName: InstancePort
```

The *ServiceName* parameter must be **NULL**. This is the SPN format for a host-based service, which provides services identified with its host computer. The *InstancePort* component is optional.

##### - ServiceType.DS_SPN_DOMAIN, DS_SPN_NB_DOMAIN

The SPNs have the following format.

```cpp
ServiceClass/ InstanceName: InstancePort/ ServiceName
```

The *ServiceName* parameter must be the DNS name or DN of a domain. This format is used for a replicable service that provides services to the specified domain.

##### - ServiceType.DS_SPN_SERVICE

The SPNs have the following format.

```cpp
ServiceClass/ InstanceName: InstancePort/ ServiceName
```

The *ServiceName* parameter must be a canonical DN or DNS name that identifies an instance of the service. For example, it could be a DNS name of a SRV record, or the distinguished name of the service connection point for this service instance.

## Return value

If the function returns an array of SPNs, the return value is **ERROR_SUCCESS**.

If the function fails, the return value can be one of the following error codes.

## Remarks

**To create SPNs for multiple instances of a replicated service running on multiple host computers**

1. Set *cInstanceNames* to the number of instances.
2. Specify the names of the host computers in the *pInstanceNames* array.

**To create SPNs for multiple instances of a service running on the same host computer**

1. Set the *cInstanceNames* to the number of instances.
2. Set each entry in the *pInstanceNames* array to the DNS name of the host computer.
3. Use the *pInstancePorts* parameter to specify an array of unique port numbers for each instance to disambiguate the SPNs.

String parameters cannot include the forward slash (/), which is used to separate the components of the SPN.

An application with the appropriate privileges, which are usually those of a domain administrator, can call the [DsWriteAccountSpn](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dswriteaccountspna) function to register one or more SPNs on the user or computer account where the service is running. Clients can then use the SPNs to authenticate the service.

> [!NOTE]
> The ntdsapi.h header defines DsGetSpn as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsFreeSpnArray](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsfreespnarraya)

[DsWriteAccountSpn](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dswriteaccountspna)