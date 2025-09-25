# SERVICE_DESCRIPTIONA structure

## Description

Contains a service description.

## Members

### `lpDescription`

The description of the service. If this member is **NULL**, the description remains unchanged. If this value is an empty string (""), the current description is deleted.

The service description must not exceed the size of a registry value of type **REG_SZ**.

This member can specify a localized string using the following format:

@[*path*\]*dllname*,-*strID*

The string with identifier *strID* is loaded from *dllname*; the *path* is optional. For more information, see [RegLoadMUIString](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regloadmuistringa).

**Windows Server 2003 and Windows XP:** Localized strings are not supported until Windows Vista.

## Remarks

A description of **NULL** indicates no service description exists. The service description is NULL when the service is created.

The description is simply a comment that explains the purpose of the service. For example, for the DHCP service, you could use the description "Provides internet addresses for computer on your network."

You can set the description using the
[ChangeServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfig2a) function. You can retrieve the description using the
[QueryServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfig2a) function. The description is also displayed by the Services snap-in.

#### Examples

For an example, see
[Changing a Service's Configuration](https://learn.microsoft.com/windows/desktop/Services/changing-a-service-configuration) or [Querying a Service's Configuration](https://learn.microsoft.com/windows/desktop/Services/querying-a-service-s-configuration).

> [!NOTE]
> The winsvc.h header defines SERVICE_DESCRIPTION as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ChangeServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfig2a)

[QueryServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfig2a)