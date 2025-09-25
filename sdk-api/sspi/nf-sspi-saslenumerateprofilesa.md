# SaslEnumerateProfilesA function

## Description

The **SaslEnumerateProfiles** function lists the packages that provide a SASL interface.

## Parameters

### `ProfileList` [out]

Pointer to a list of Unicode or ANSI strings that contain the names of the packages with SASL wrapper support.

### `ProfileCount` [out]

Pointer to an unsigned **LONG** value that contains the number of packages with SASL wrapper support.

## Return value

If the call is completed successfully, this function returns SEC_E_OK.

If the function fails, the return value is a nonzero error code.

## Remarks

The current list is maintained in the registry under

```
SYSTEM
   CurrentControlSet
      Control
         SecurityProviders
            SaslProfiles
```

A terminating **NULL** character is appended to the end of the list.

> [!NOTE]
> The sspi.h header defines SaslEnumerateProfiles as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).