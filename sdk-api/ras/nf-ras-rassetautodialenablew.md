# RasSetAutodialEnableW function

## Description

The
**RasSetAutodialEnable** function enables or disables the AutoDial feature for a specified TAPI dialing location. For more information about TAPI dialing locations, see [Telephony Application Programming Interfaces (TAPI)](https://learn.microsoft.com/windows/desktop/Tapi/telephony-application-programming-interfaces) in the Platform Software Development Kit (SDK).

## Parameters

### `unnamedParam1` [in]

Specifies the identifier of a TAPI dialing location.

### `unnamedParam2` [in]

Specifies **TRUE** to enable AutoDial for the dialing location indicated by the *dwDialingLocation* parameter. Specifies **FALSE** to disable it.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is a non-zero error code from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

## See also

[RasGetAutodialEnable](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetautodialenablea)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)

## Remarks

> [!NOTE]
> The ras.h header defines RasSetAutodialEnable as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).