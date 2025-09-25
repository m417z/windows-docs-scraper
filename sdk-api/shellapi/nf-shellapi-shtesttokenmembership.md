# SHTestTokenMembership function

## Description

Uses [CheckTokenMembership](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-checktokenmembership) to test whether the given token is a member of the local group with the specified RID.

## Parameters

### `hToken` [in, optional]

Type: **HANDLE**

A handle to the token. This value can be **NULL**.

### `ulRID`

Type: **ULONG**

The RID of the local group for which membership is tested.

## Return value

Type: **BOOL**

Returns **TRUE** on success, **FALSE** on failure.

## Remarks

This function wraps [CheckTokenMembership](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-checktokenmembership) and only checks local groups.