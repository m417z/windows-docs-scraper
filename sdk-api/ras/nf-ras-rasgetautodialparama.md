# RasGetAutodialParamA function

## Description

The
**RasGetAutodialParam** function retrieves the value of an AutoDial parameter.

## Parameters

### `unnamedParam1` [in]

Specifies the AutoDial parameter to retrieve. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **RASADP_DisableConnectionQuery** | The *lpvValue* parameter returns a **DWORD** value. If this value is zero (the default), AutoDial displays a dialog box to query the user before creating a connection. If this value is 1, and the AutoDial database has the phone-book entry to dial, AutoDial creates a connection without displaying the dialog box. |
| **RASADP_LoginSessionDisable** | The *lpvValue* parameter returns a **DWORD** value. If this value is 1, the system disables all AutoDial connections for the current logon session. If this value is zero (the default), AutoDial connections are enabled. The AutoDial system service changes this value to zero when a new user logs on to the workstation. |
| **RASADP_SavedAddressesLimit** | The *lpvValue* parameter returns a **DWORD** value that indicates the maximum number of addresses that AutoDial stores in the registry. AutoDial first stores addresses that it used to create an AutoDial connection; then it stores addresses that it learned after a RAS connection was created. Addresses written using the [RasSetAutodialAddress](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetautodialaddressa) function are always saved, and are not included in calculating the limit. The default value is 100. |
| **RASADP_FailedConnectionTimeout** | The *lpvValue* parameter returns a **DWORD** value that indicates a time-out value, in seconds. When an AutoDial connection attempt fails, the AutoDial system service disables subsequent attempts to reach the same address for the time-out period. This prevents AutoDial from displaying multiple connection dialog boxes for the same logical request by an application. The default value is 5. |
| **RASADP_ConnectionQueryTimeout** | The *lpvValue* parameter points to a **DWORD** value that indicates a time-out value, in seconds. Before attempting an AutoDial connection, the system will display a dialog asking the user to confirm that the system should dial. The dialog has a countdown timer that terminates the dialog with a "Do not dial" selection if the user takes no action. The **DWORD** value pointed to by *lpvValue* specifies the initial time on this countdown timer. |

### `unnamedParam2` [out]

Pointer to a buffer that receives the value for the specified parameter.

### `unnamedParam3` [in, out]

Pointer to a **DWORD** value.

On input, set this value to indicate the size, in bytes, of the *lpvValue* buffer.

On output, this value indicates the actual size of the value written to the buffer.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *dwKey* or *lpvValue* parameter is invalid. |
| **ERROR_INVALID_SIZE** | The size specified by the *lpdwcbValue* is too small. |

## See also

[RasSetAutodialAddress](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetautodialaddressa)

[RasSetAutodialParam](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetautodialparama)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)

## Remarks

> [!NOTE]
> The ras.h header defines RasGetAutodialParam as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).