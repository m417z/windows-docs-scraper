# DhcpV4FailoverTriggerAddrAllocation function

## Description

The **DhcpV4FailoverTriggerAddrAllocation** function redistributes the free addresses between the primary server and the secondary server that are part of a failover relationship.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `pFailRelName` [in]

Pointer to a null-terminated Unicode string that represents the name of the failover relationship for which free addresses are to be redistributed.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters were invalid. |
| **ERROR_DHCP_FO_RELATIONSHIP_DOES_NOT_EXIST** | Failover relationship doesn't exit. |
| **ERROR_DHCP_FO_RELATION_IS_SECONDARY** | The **serverType** member of failover relationship is **SecondaryServer**. |