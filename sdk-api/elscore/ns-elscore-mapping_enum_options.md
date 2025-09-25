# MAPPING_ENUM_OPTIONS structure

## Description

Contains options used by the [MappingGetServices](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappinggetservices) function to enumerate ELS services.

## Members

### `Size`

Size of the structure, used to validate the structure version. This value is required.

### `pszCategory`

Optional. Pointer to a service category, for example, "Language Detection". The application must set this member to **NULL** if the service category is not a search criterion.

### `pszInputLanguage`

Optional. Pointer to an input language string, following the IETF naming convention, that identifies the input language that services should accept. The application can set this member to **NULL** if the supported input language is not a search criterion.

### `pszOutputLanguage`

Optional. Pointer to an output language string, following the IETF naming convention, that identifies the output language that services use to retrieve results. The application can set this member to **NULL** if the output language is not a search criterion.

### `pszInputScript`

Optional. Pointer to a standard Unicode script name that can be accepted by services. The application set this member to **NULL** if the input script is not a search criterion.

### `pszOutputScript`

Optional. Pointer to a standard Unicode script name used by services. The application can set this member to **NULL** if the output script is not a search criterion.

### `pszInputContentType`

Optional. Pointer to a string, following the format of the MIME content types, that identifies the format that the services should be able to interpret when the application passes data. Examples of content types are "text/plain", "text/html", and "text/css". The application can set this member to **NULL** if the input content type is not a search criterion.

**Note** In Windows 7, the ELS services support only the content type "text/plain". A content type specification can be found at [Text Media Types](https://www.iana.org/assignments/media-types/text).

### `pszOutputContentType`

Optional. Pointer to a string, following the format of the MIME content types, that identifies the format in which the services retrieve data. The application can set this member to **NULL** if the output content type is not a search criterion.

### `pGuid`

Optional. Pointer to a globally unique identifier (GUID) structure for a specific service. The application must set this member to **NULL** if the GUID is not a search criterion.

### `OnlineService`

Reserved for future use. Must be set to 0.

### `ServiceType`

Reserved for future use. Must be set to 0.

## Remarks

The **Size** member is the only required member of this structure. All the other members are optional. The application can set any of the members that it needs for search criteria.

## See also

[Extended Linguistic Services Structures](https://learn.microsoft.com/windows/desktop/Intl/extended-linguistic-services-structures)

[MappingGetServices](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappinggetservices)