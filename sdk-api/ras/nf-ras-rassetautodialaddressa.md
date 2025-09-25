# RasSetAutodialAddressA function

## Description

The
**RasSetAutodialAddress** function can add an address to the AutoDial mapping database. Alternatively, the function can delete or modify the data associated with an existing address in the database.

## Parameters

### `unnamedParam1` [in]

Pointer to a **null**-terminated string that specifies the address to add, delete, or modify. This address can be an IP address, Internet host name ("www.microsoft.com"), or NetBIOS name ("products1").

If this parameter is **NULL**, the function sets the default Internet connection (see Remarks). If this parameter points to a zero-length string, the function deletes the default Internet connection.

### `unnamedParam2` [in]

Reserved; must be zero.

### `unnamedParam3` [in]

Pointer to an array of one or more
[RASAUTODIALENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376721(v=vs.85)) structures to be associated with the *lpszAddress* address. If *lpAutoDialEntries* is **NULL** and *dwcbAutoDialEntries* is zero,
**RasSetAutodialAddress** deletes all structures associated with *lpszAddress* from the mapping database.

### `unnamedParam4` [in]

Specifies the size, in bytes, of the *lpAutoDialEntries* buffer.

### `unnamedParam5` [in]

Specifies the number of
[RASAUTODIALENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376721(v=vs.85)) structures in the *lpAutoDialEntries* buffer.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_SIZE** | The **dwSize** member of the [RASAUTODIALENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376721(v=vs.85)) structure is an invalid value. |
| **ERROR_INVALID_PARAMETER** | The *lpszAddress* parameter is **NULL**. |
| **ERROR_CANNOT_FIND_PHONEBOOK_ENTRY** | The connection name specified in *lpAutoDialEntries* does not exist. |

## Remarks

An address in the AutoDial mapping database can have any number of associated
[RASAUTODIALENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376721(v=vs.85)) entries. Each entry specifies AutoDial information for a particular TAPI dialing location.

If the address specified by the *lpszAddress* parameter is an existing address in the database and the *lpAutoDialEntries* parameter is not **NULL**, the
**RasSetAutodialAddress** function modifies the set of AutoDial entries associated with the address. If an entry in the *lpAutoDialEntries* array specifies a dialing location for which the address already has an entry, the function replaces the existing entry with the new entry. Otherwise, the function simply adds the *lpAutoDialEntries* entries to the set of entries for the address.

If the *lpszAddress* address exists in the database, *lpAutoDialEntries* is **NULL**, and *lpAutoDialEntries* is zero,
**RasSetAutodialAddress** deletes the address from the database.

If the *lpszAddress* address does not exist in the database,
**RasSetAutodialAddress** adds the address to the database. The *lpAutoDialEntries* parameter specifies the AutoDial entries to associate with the new address.

 RAS supports a default Internet connection that is global to the local computer and supports a default Internet connection for each user.

When the *lpszAddress* parameter is **NULL**, and the *lpAutoDialEntries* parameter specifies a connection name with one entry, **RasSetAutodialAddress** sets the connection as the default internet connection. The connection name specified in *lpAutoDialEntries* should already exist. If it does not, **ERROR_CANNOT_FIND_PHONEBOOK_ENTRY** will be returned.

When the *lpszAddress* parameter is a zero-length string and the *lpAutoDialEntries* parameter specifies an empty connection name with one entry, **RasSetAutodialAddress** deletes the default internet connection.

On non-domain client machines, if a user wants to set a connection as the default internet connection and specifies a "for-all-users" connection in the **szEntry** member of the [RASAUTODIALENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376721(v=vs.85)) structure, then the default internet connection is set globally on the local computer. In all other cases the default internet connection is set for each user of the machine individually.

It is possible to have two connections that have the same name if one is configured as a "for-all-users" connection and the other is configured as a "for-me-only" connection. If the *lpAutoDialEntries* parameter specifies a connection name that corresponds to both a global and a per-user connection, the per-user connection is set.

> [!NOTE]
> The ras.h header defines RasSetAutodialAddress as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RASAUTODIALENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376721(v=vs.85))

[RasEnumAutodialAddresses](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumautodialaddressesa)

[RasGetAutodialAddress](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetautodialaddressa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)