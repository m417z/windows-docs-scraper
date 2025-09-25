# DS_SPN_NAME_TYPE enumeration

## Description

The **DS_SPN_NAME_TYPE** enumeration is used by the [DsGetSPN](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsgetspna) function to identify the format for composing SPNs.

## Constants

### `DS_SPN_DNS_HOST:0`

The SPN format for the distinguished name service of the host-based service, which provides services identified with its host computer. This SPN uses the following format:

```cpp
jeffsmith.fabrikam.com
```

### `DS_SPN_DN_HOST:1`

The SPN format for the distinguished name of the host-based service, which provides services identified with its host computer. This SPN uses the following format:

```cpp
cn=jeffsmith,ou=computers,dc=fabrikam,dc=com
```

### `DS_SPN_NB_HOST:2`

The SPN format for the NetBIOS service of the host-based service, which provides services identified with its host computer. This SPN uses the following format:

```cpp
jeffsmith-nec
```

### `DS_SPN_DOMAIN:3`

The SPN format for a replicable service that provides services to the specified domain. This SPN uses the following format:

```cpp
fabrikam.com
```

### `DS_SPN_NB_DOMAIN:4`

The SPN format for a replicable service that provides services to the specified NetBIOS domain. This SPN uses the following format:

```cpp
fabrikam
```

### `DS_SPN_SERVICE:5`

The SPN format for a specified service. This SPN uses the following formats, depending on which service is used:

```cpp
cn=anRpcService,cn=RPC Services,cn=system,dc=fabrikam,dc=com
```

```cpp
cn=aWsService,cn=Winsock Services,cn=system,dc=fabrikam,dc=com
```

```cpp
cn=aService,dc=itg,dc=fabrikam,dc=com
```

```cpp
www.fabrikam.com, ftp.fabrikam.com, ldap.fabrikam.com
```

```cpp
products.fabrikam.com
```

## See also

[DsGetSPN](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsgetspna)

[Enumerations in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/enumerations-in-active-directory-domain-services)