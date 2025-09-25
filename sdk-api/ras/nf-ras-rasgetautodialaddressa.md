# RasGetAutodialAddressA function

## Description

The
**RasGetAutodialAddress** function retrieves information about all the AutoDial entries associated with a network address in the AutoDial mapping database.

## Parameters

### `unnamedParam1` [in]

Pointer to a **null**-terminated string that specifies the address for which information is requested. This can be an IP address, Internet host name ("www.microsoft.com"), or NetBIOS name ("products1").

If this parameter is **NULL**, the function retrieves the default Internet connection. The function returns the per-user default Internet connection if one is configured. Otherwise, the function returns the global default Internet connection. If no default Internet connections are configured, the function returns zero for the *lpdwcbAutoDialEntries* and *lpdwcAutoDialEntries* parameters.

### `unnamedParam2` [in]

Reserved; must be **NULL**.

### `unnamedParam3` [in, out]

Pointer to a buffer that, on output, receives an array of
[RASAUTODIALENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376721(v=vs.85)) structures, one for each AutoDial entry associated with the address specified by the *lpszAddress* parameter.

On input, set the **dwSize** member of the first
[RASAUTODIALENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376721(v=vs.85)) structure in the buffer to sizeof(RASAUTODIALENTRY) to identify the version of the structure.

If *lpAutoDialEntries* is **NULL**,
**RasGetAutodialAddress** sets the *lpdwcbAutoDialEntries* and *lpdwcAutoDialEntries* parameters to indicate the required buffer size, in bytes, and the number of AutoDial entries.

### `unnamedParam4` [in, out]

Pointer to a variable that, on input, specifies the size, in bytes, of the *lpAutoDialEntries* buffer.

On output, this variable receives the number of bytes returned, or the number of bytes required if the buffer is too small.

### `unnamedParam5` [out]

Pointer to a variable that receives the number of structure elements returned in the *lpAutoDialEntries* buffer.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_SIZE** | The **dwSize** member of the [RASAUTODIALENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376721(v=vs.85)) structure is an invalid value. |
| **ERROR_INVALID_PARAMETER** | The *lpszAddress*, *lpdwcbAutoDialEntries*, or *lpdwcAutoDialEntries* parameter was **NULL**. |

## Remarks

The Remote Access Service (RAS) supports default Internet connections. RAS supports a default Internet connection that is global to the local computer, and in addition, supports a default Internet connection for each user.

The name of the global default Internet connection is stored in the registry below the following registry key:

```
HKEY_LOCAL_MACHINE
   Software
      Microsoft
         Ras Autodial
            Default
```

The value that stores the name of the connection is:

**DefaultInternet**

This value is of type **REG_SZ**.

The global default Internet connection must be configured as a **For all users** connection in the **Connections Folder** user interface.

The name of the per-user default Internet connection is stored in the registry below the following registry key:

**HKEY_CURRENT_USER**\**Software**\**Microsoft**\**Ras Autodial**\**Default**

The value that stores the name of the connection is:

**DefaultInternet**

This value is of type **REG_SZ**.

> [!NOTE]
> The ras.h header defines RasGetAutodialAddress as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RASAUTODIALENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376721(v=vs.85))

[RasEnumAutodialAddresses](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumautodialaddressesa)

[RasSetAutodialAddress](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetautodialaddressa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)