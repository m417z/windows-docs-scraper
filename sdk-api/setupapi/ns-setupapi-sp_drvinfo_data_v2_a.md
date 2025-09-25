# SP_DRVINFO_DATA_V2_A structure

## Description

An SP_DRVINFO_DATA structure contains information about a driver. This structure is a member of a driver information list that can be associated with a particular device instance or globally with a device information set.

## Members

### `cbSize`

The size, in bytes, of the SP_DRVINFO_DATA structure. For more information, see the Remarks section in this topic.

### `DriverType`

The type of driver represented by this structure. Must be one of the following values:

#### SPDIT_CLASSDRIVER

This structure represents a class driver.

#### SPDIT_COMPATDRIVER

This structure represents a compatible driver.

### `Reserved`

Reserved. For internal use only.

### `Description`

A NULL-terminated string that describes the device supported by this driver.

### `MfgName`

A NULL-terminated string that contains the name of the manufacturer of the device supported by this driver.

### `ProviderName`

A NULL-terminated string giving the provider of this driver. This is typically the name of the organization that creates the driver or INF file. **ProviderName** can be an empty string.

### `DriverDate`

Date of the driver. From the **DriverVer** entry in the INF file. See the [INF DDInstall Section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-ddinstall-section) for more information about the **DriverVer** entry.

### `DriverVersion`

Version of the driver. From the **DriverVer** entry in the INF file.

### `DriverType.SPDIT_CLASSDRIVER`

This structure represents a class driver.

### `DriverType.SPDIT_COMPATDRIVER`

This structure represents a compatible driver.

## Remarks

In *SetupAPI.h*, this structure equates to either SP_DRVINFO_DATA_V1 or SP_DRVINFO_DATA_V2, based on whether you include the following line in your source code:

```
#define  USE_SP_DRVINFO_DATA_V1 1
```

Define this identifier only if your component must run on Windows 98 or Millennium Edition, or on Windows NT. If your component is run only in Windows 2000 and later versions of Windows, do not define the identifier. If the identifier is not defined, SP_DRVINFO_DATA_V2 is used.

SP_DRVINFO_DATA_V1 does not contain **DriverDate** and **DriverVersion** members.

**SetupDi***Xxx* functions that take an SP_DRVINFO_DATA structure as a parameter verify that the **cbSize** member of the supplied structure is equal to the size, in bytes, of the structure. If the **cbSize** member is not set correctly for an input parameter, the function will fail and set an error code of ERROR_INVALID_PARAMETER. If the **cbSize** member is not set correctly for an output parameter, the function will fail and set an error code of ERROR_INVALID_USER_BUFFER.

> [!NOTE]
> The setupapi.h header defines SP_DRVINFO_DATA_V2 as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiEnumDriverInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdriverinfoa)

[SetupDiGetDriverInstallParams](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdriverinstallparamsa)

[SetupDiGetSelectedDriver](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetselecteddrivera)

[SetupDiSetDriverInstallParams](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetdriverinstallparamsa)

[SetupDiSetSelectedDriver](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetselecteddrivera)