# GOPHER_ATTRIBUTE_TYPE structure

## Description

[The **GOPHER_ATTRIBUTE_TYPE** structure is available for use in the operating systems specified in the Requirements section.]

Contains the relevant information of a single Gopher attribute for an object.

## Members

### `CategoryId`

Name of the Gopher category for the attribute. The possible values include:

#### GOPHER_CATEGORY_ID_ABSTRACT

#### GOPHER_CATEGORY_ID_ADMIN

#### GOPHER_CATEGORY_ID_ALL

#### GOPHER_CATEGORY_ID_INFO

#### GOPHER_CATEGORY_ID_UNKNOWN

#### GOPHER_CATEGORY_ID_VERONICA

#### GOPHER_CATEGORY_ID_VIEWS

### `AttributeId`

Attribute type. The possible values include:

#### GOPHER_ATTRIBUTE_ID_ABSTRACT

#### GOPHER_ATTRIBUTE_ID_ADMIN

#### GOPHER_ATTRIBUTE_ID_GEOG

#### GOPHER_ATTRIBUTE_ID_LOCATION

#### GOPHER_ATTRIBUTE_ID_MOD_DATE

#### GOPHER_ATTRIBUTE_ID_ORG

#### GOPHER_ATTRIBUTE_ID_PROVIDER

#### GOPHER_ATTRIBUTE_ID_RANGE

#### GOPHER_ATTRIBUTE_ID_SCORE

#### GOPHER_ATTRIBUTE_ID_SITE

#### GOPHER_ATTRIBUTE_ID_TIMEZONE

#### GOPHER_ATTRIBUTE_ID_TREEWALK

#### GOPHER_ATTRIBUTE_ID_TTL

#### GOPHER_ATTRIBUTE_ID_UNKNOWN

#### GOPHER_ATTRIBUTE_ID_VERSION

#### GOPHER_ATTRIBUTE_ID_VIEW

### `AttributeType`

 Data for the Gopher attribute. The specific structure depends on the
**AttributeId** member. The definitions of these data structures are available in Wininet.h.

#### Admin

A **GOPHER_ADMIN_ATTRIBUTE** structure.

#### ModDate

A **GOPHER_MOD_DATE_ATTRIBUTE** structure.

#### Score

A **GOPHER_SCORE_ATTRIBUTE** structure.

#### ScoreRange

A **GOPHER_SCORE_RANGE_ATTRIBUTE** structure.

#### Site

A **GOPHER_SITE_ATTRIBUTE** structure.

#### Organization

A **GOPHER_ORGANIZATION_ATTRIBUTE** structure.

#### Location

A **GOPHER_LOCATION_ATTRIBUTE** structure.

#### GeographicalLocation

A **GOPHER_GEOGRAPHICAL_LOCATION_ATTRIBUTE** structure.

#### TimeZone

A **GOPHER_TIMEZONE_ATTRIBUTE** structure.

#### Provider

A **GOPHER_PROVIDER_ATTRIBUTE** structure.

#### Version

A **GOPHER_VERSION_ATTRIBUTE** structure.

#### Abstract

A **GOPHER_ABSTRACT_ATTRIBUTE** structure.

#### View

A **GOPHER_VIEW_ATTRIBUTE** structure.

#### Veronica

A **GOPHER_VERONICA_ATTRIBUTE** structure.

#### Ask

A **GOPHER_ASK_ATTRIBUTE_TYPE** structure.

#### Unknown

A **GOPHER_UNKNOWN_ATTRIBUTE** structure.

### `Admin`

### `ModDate`

### `Ttl`

### `Score`

### `ScoreRange`

### `Site`

### `Organization`

### `Location`

### `GeographicalLocation`

### `TimeZone`

### `Provider`

### `Version`

### `Abstract`

### `View`

### `Veronica`

### `Ask`

### `Unknown`

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[GopherAttributeEnumerator](https://learn.microsoft.com/windows/desktop/api/wininet/nc-wininet-gopher_attribute_enumerator)

[GopherGetAttribute](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-gophergetattributea)