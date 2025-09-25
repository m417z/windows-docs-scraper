# COMPUTER_NAME_FORMAT enumeration

## Description

Specifies a type of computer name.

## Constants

### `ComputerNameNetBIOS`

The NetBIOS name of the local computer or the cluster associated with the local computer. This name is limited to MAX_COMPUTERNAME_LENGTH + 1 characters and may be a truncated version of the DNS host name. For example, if the DNS host name is "corporate-mail-server", the NetBIOS name would be "corporate-mail-".

### `ComputerNameDnsHostname`

The DNS name of the local computer or the cluster associated with the local computer.

### `ComputerNameDnsDomain`

The name of the DNS domain assigned to the local computer or the cluster associated with the local computer.

### `ComputerNameDnsFullyQualified`

The fully qualified DNS name that uniquely identifies the local computer or the cluster associated with the local computer.

This name is a combination of the DNS host name and the DNS domain name, using the form *HostName*.*DomainName*. For example, if the DNS host name is "corporate-mail-server" and the DNS domain name is "microsoft.com", the fully qualified DNS name is "corporate-mail-server.microsoft.com".

### `ComputerNamePhysicalNetBIOS`

The NetBIOS name of the local computer. On a cluster, this is the NetBIOS name of the local node on the cluster.

### `ComputerNamePhysicalDnsHostname`

The DNS host name of the local computer. On a cluster, this is the DNS host name of the local node on the cluster.

### `ComputerNamePhysicalDnsDomain`

The name of the DNS domain assigned to the local computer. On a cluster, this is the DNS domain of the local node on the cluster.

### `ComputerNamePhysicalDnsFullyQualified`

The fully qualified DNS name that uniquely identifies the computer. On a cluster, this is the fully qualified DNS name of the local node on the cluster. The fully qualified DNS name is a combination of the DNS host name and the DNS domain name, using the form *HostName*.*DomainName*.

### `ComputerNameMax`

Not used.

## See also

[GetComputerNameEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getcomputernameexa)

[SetComputerNameEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setcomputernameexa)