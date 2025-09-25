# MAPPING_SERVICE_INFO structure

## Description

Contains information about an ELS service.

## Members

### `Size`

Size of the structure, used to validate the structure version. This value is required.

### `pszCopyright`

Pointer to copyright information about the service.

### `wMajorVersion`

Major version number that is used to track changes to the service.

### `wMinorVersion`

Minor version number that is used to track changes to the service.

### `wBuildVersion`

Build version that is used to track changes to the service.

### `wStepVersion`

Step version that is used to track changes to the service.

### `dwInputContentTypesCount`

Number of content types that the service can receive.

### `prgInputContentTypes`

Optional. Pointer to an array of input content types, following the format of the MIME content types, that identify the format that the service interprets when the application passes data. Examples of content types are "text/plain", "text/html" and "text/css".

**Note** In Windows 7, the ELS services support only the content type "text/plain". A content types specification can be found at [Text Media Types](https://www.iana.org/assignments/media-types/text).

### `dwOutputContentTypesCount`

Number of content types in which the service can format results.

### `prgOutputContentTypes`

Optional. Pointer to an array of output content types, following the format of the MIME content types, that identify the format in which the service retrieves data.

### `dwInputLanguagesCount`

Number of input languages supported by the service. This member is set to 0 if the service can accept data in any language.

### `prgInputLanguages`

Pointer to an array of the input languages, following the IETF naming convention, that the service accepts. This member is set to **NULL** if the service can work with any input language.

### `dwOutputLanguagesCount`

Number of output languages supported by the service. This member is set to 0 if the service can retrieve data in any language, or if the service ignores the output language.

### `prgOutputLanguages`

Pointer to an array of output languages, following the IETF naming convention, in which the service can retrieve results. This member is set to **NULL** if the service can retrieve results in any language, or if the service ignores the output language.

### `dwInputScriptsCount`

Number of input scripts supported by the service. This member is set to 0 if the service can accept data in any script.

### `prgInputScripts`

Pointer to an array of input scripts, with Unicode standard script names, that are supported by the service. This member is set to **NULL** if the service can work with any scripts, or if the service ignores the input scripts.

### `dwOutputScriptsCount`

Number of output scripts supported by the service. This member is set to 0 if the service can retrieve data in any script, or if the service ignores the output scripts.

### `prgOutputScripts`

Pointer to an array of output scripts supported by the service. This member is set to **NULL** if the service can work with any scripts, or the service ignores the output scripts.

### `guid`

Globally unique identifier (GUID) for the service.

### `pszCategory`

Pointer to the service category for the service, for example, "Language Detection".

### `pszDescription`

Pointer to the service description. This text can be localized.

### `dwPrivateDataSize`

Size, in bytes, of the private data for the service. This member is set to 0 if there is no private data.

### `pPrivateData`

Pointer to private data that the service can expose. This information is static and updated during installation of the service.

### `pContext`

Reserved for internal use.

### `IsOneToOneLanguageMapping`

Flag indicating the language mapping between input language and output language that is supported by the service. Possible values are shown in the following table.

| Value | Meaning |
| --- | --- |
| **0** | The input and output languages are not paired and the service can receive data in any of the input languages and render data in any of the output languages. |
| **1** | The arrays of the input and output languages for the service are paired. In other words, given a particular input language, the service retrieves results in the paired language defined in the output language array. Use of the language pairing can be useful, for example, in bilingual dictionary scenarios. |

### `HasSubservices`

Flag indicating if the service has subservices, that is, other services that plug into the service. This flag is used in service enumeration to determine if the parent service must be called to get a list of subservices. Possible values are shown in the following table.

| Value | Meaning |
| --- | --- |
| **0** | The service is a regular service that stands alone and has no subservices. |
| **1** | The service acts as a parent for subservices. |

### `OnlineOnly`

Reserved for future use.

### `ServiceType`

Reserved for future use.

## Remarks

Structures of this type are created in an application call to [MappingGetServices](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappinggetservices).

## See also

[Extended Linguistic Services Structures](https://learn.microsoft.com/windows/desktop/Intl/extended-linguistic-services-structures)

[MappingGetServices](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappinggetservices)