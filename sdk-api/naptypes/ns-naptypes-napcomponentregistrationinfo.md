# NapComponentRegistrationInfo structure

## Description

**Note** The Network Access Protection platform is not available starting with Windows 10

The **NapComponentRegistrationInfo** structure defines a registered NAP component such as a SHA, SHV, or enforcement client.

## Members

### `id`

A [NapComponentId](https://learn.microsoft.com/windows/desktop/NAP/nap-datatypes) value that contains the unique identifier of the component.

### `friendlyName`

A [CountedString](https://learn.microsoft.com/windows/desktop/api/naptypes/ns-naptypes-countedstring) structure that contains the friendly (human-readable) name of the component.

### `description`

A [CountedString](https://learn.microsoft.com/windows/desktop/api/naptypes/ns-naptypes-countedstring) structure that contains a description of the component.

### `version`

A [CountedString](https://learn.microsoft.com/windows/desktop/api/naptypes/ns-naptypes-countedstring) structure that contains the version of the component.

### `vendorName`

A [CountedString](https://learn.microsoft.com/windows/desktop/api/naptypes/ns-naptypes-countedstring) structure that contains the vendor name for the component.

### `infoClsid`

The [CLSID](https://learn.microsoft.com/windows/win32/com/clsid-key-hklm) of the COM object that implements
the [INapComponentInfo](https://learn.microsoft.com/windows/desktop/NAP/inapcomponentinfo) interface. This interface
is used to retrieve more detailed and localized
information about the NAP component.

Currently, enforcement clients do not need to
provide a valid *infoClsid*.

### `configClsid`

The [CLSID](https://learn.microsoft.com/windows/win32/com/clsid-key-hklm) of the COM object that implements
the [INapComponentConfig](https://learn.microsoft.com/windows/desktop/NAP/inapcomponentconfig) interface. This interface is used to launch a customized user interface and to get and set SHV configuration settings.

Currently, SHAs and enforcement clients do not need to
provide a valid *configClsid*.

### `registrationDate`

A [FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime) structure that contains the registration information date.

### `componentType`

A value that defines the component type.

For enforcement clients this value should be either [ComponentTypeEnforcementClientSoH](https://learn.microsoft.com/windows/desktop/NAP/nap-type-constants) or **ComponentTypeEnforcementClientRp**.

Currently, *componentType* is ignored for SHAs and SHVs and should be set to 0x00000000.

## Remarks

This registration information is not localized, it is provided in US-English only.

When NAP components are registered through the registration APIs, the *registrationDate* field is ignored.

When information about registered NAP
components is retrieved, if there is no valid *infoClsid*, *configClsid*, or *registrationDate*, they are set to 0.

## See also

[CountedString](https://learn.microsoft.com/windows/desktop/api/naptypes/ns-naptypes-countedstring)

[INapComponentInfo](https://learn.microsoft.com/windows/desktop/NAP/inapcomponentinfo)

[NAP Reference](https://learn.microsoft.com/windows/desktop/NAP/nap-reference)

[NAP Structures](https://learn.microsoft.com/windows/desktop/NAP/nap-structures)