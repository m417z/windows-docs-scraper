# AUTHZ_SOURCE_SCHEMA_REGISTRATION structure

## Description

The **AUTHZ_SOURCE_SCHEMA_REGISTRATION** structure specifies information about source schema registration.

## Members

### `dwFlags`

Flags that control the behavior of the operation. The following table shows a possible value.

| Value | Meaning |
| --- | --- |
| **AUTHZ_ALLOW_MULTIPLE_SOURCE_INSTANCES**<br><br>0x1 | Allows registration of multiple sources with the same name. Use of this flag means that more than one source can call the [AuthzRegisterSecurityEventSource](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzregistersecurityeventsource) function with the same *szEventSourceName* at runtime. |
| **AUTHZ_MIGRATED_LEGACY_PUBLISHER**<br><br>0x2 | The caller is a migrated publisher that has registered a manifest with WEvtUtil.exe. The [GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) of the provider specified by the **pProviderGuid** member is stored in the registry. |

### `szEventSourceName`

A pointer to a wide character string that represents the name of the event source.

### `szEventMessageFile`

A pointer to a wide character string that represents the name of the resource that contains the event messages.

### `szEventSourceXmlSchemaFile`

A pointer to a wide character string that represents the name of the XML schema file for the event source.

### `szEventAccessStringsFile`

A pointer to a wide character string that represents the name of the resource that contains the event parameter strings.

### `szExecutableImagePath`

This member is reserved and must be set to **NULL**.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.pReserved`

This member is reserved and must be set to **NULL**.

### `DUMMYUNIONNAME.pProviderGuid`

The [GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) of a migrated publisher. The value of this member is converted to a string and stored in the registry if the caller is a migrated publisher.

### `dwObjectTypeNameCount`

The number of objects in the *ObjectTypeNames* array.

### `ObjectTypeNames`

An array of [AUTHZ_REGISTRATION_OBJECT_TYPE_NAME_OFFSET](https://learn.microsoft.com/windows/win32/api/authz/ns-authz-authz_registration_object_type_name_offset) structures that represents the object types for the events.

## See also

[AuthzEnumerateSecurityEventSources](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzenumeratesecurityeventsources)

[AuthzInstallSecurityEventSource](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzinstallsecurityeventsource)