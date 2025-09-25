# LsaGetLogonSessionData function

## Description

The **LsaGetLogonSessionData** function retrieves information about a specified logon session.

To retrieve information about a logon session, the caller must be the owner of the session or a local system administrator.

## Parameters

### `LogonId` [in]

Specifies a pointer to a **LUID** that identifies the logon session whose information will be retrieved. For information about valid values for this parameter, see Remarks.

### `ppLogonSessionData` [out]

Address of a pointer to a
[SECURITY_LOGON_SESSION_DATA](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-security_logon_session_data) structure containing information on the logon session specified by *LogonId*. This structure is allocated by the LSA. When the information is no longer needed, call the
[LsaFreeReturnBuffer](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreereturnbuffer) function to free the memory used by this structure.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an **NTSTATUS** code indicating the reason.

## Remarks

To obtain valid logon session identifiers that may be passed to this function's *LogonId* parameter, call the
[LsaEnumerateLogonSessions](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaenumeratelogonsessions) function.

If *LogonID* specifies the LocalSystem account (0x0:0x3e7), then this function returns zero for the logon session data retrieved in *ppLogonSessionData*. The reason is that the LocalSystem account does not get logged on in the typical logon manner. Rather, the LocalSystem account is active after the system starts.