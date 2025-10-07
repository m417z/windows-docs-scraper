# TSMF\_SUPPORT\_DATA\_OUT structure

Contains information about media formats. This structure is used by the [**QueryProperty**](https://learn.microsoft.com/windows/desktop/api/Wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnection-queryproperty) method during **WRDS\_QUERY\_MF\_FORMAT\_SUPPORT** queries.

## Members

**guidMfSession**

This must match the **guidMfSession** property in the corresponding [**TSMF\_SUPPORT\_DATA\_IN**](https://learn.microsoft.com/windows/win32/termserv/tsmf-support-data-in) structure.

**numEntries**

The number of structures in the variable length data.

**...**

A variable number of structures containing media format data.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------|
| Minimum supported client<br> | None supported<br> |
| Minimum supported server<br> | Windows Server 2008 R2<br> |

## See also

[**QueryProperty**](https://learn.microsoft.com/windows/desktop/api/Wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnection-queryproperty)

[**TSMF\_SUPPORT\_NODEDATA\_OUT**](https://learn.microsoft.com/windows/win32/termserv/tsmf-support-nodedata-out)

