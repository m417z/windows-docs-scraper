# LSA_AP_LOGON_TERMINATED callback function

## Description

Used to notify an authentication package when a logon session terminates.
A logon session terminates when the last token referencing the logon session is deleted.

## Parameters

### `LogonId` [in]

Pointer to the logon ID of the session that just ended.

## Remarks

When **LsaApLogonTerminated** is called, an authentication package should release any resources held for the logon ID, such as credentials created within the LSA. The LSA does not automatically perform this cleanup.