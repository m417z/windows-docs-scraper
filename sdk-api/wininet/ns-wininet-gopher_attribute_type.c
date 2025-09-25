typedef struct {
  DWORD CategoryId;
  DWORD AttributeId;
  union {
    GOPHER_ADMIN_ATTRIBUTE_TYPE                 Admin;
    GOPHER_MOD_DATE_ATTRIBUTE_TYPE              ModDate;
    GOPHER_TTL_ATTRIBUTE_TYPE                   Ttl;
    GOPHER_SCORE_ATTRIBUTE_TYPE                 Score;
    GOPHER_SCORE_RANGE_ATTRIBUTE_TYPE           ScoreRange;
    GOPHER_SITE_ATTRIBUTE_TYPE                  Site;
    GOPHER_ORGANIZATION_ATTRIBUTE_TYPE          Organization;
    GOPHER_LOCATION_ATTRIBUTE_TYPE              Location;
    GOPHER_GEOGRAPHICAL_LOCATION_ATTRIBUTE_TYPE GeographicalLocation;
    GOPHER_TIMEZONE_ATTRIBUTE_TYPE              TimeZone;
    GOPHER_PROVIDER_ATTRIBUTE_TYPE              Provider;
    GOPHER_VERSION_ATTRIBUTE_TYPE               Version;
    GOPHER_ABSTRACT_ATTRIBUTE_TYPE              Abstract;
    GOPHER_VIEW_ATTRIBUTE_TYPE                  View;
    GOPHER_VERONICA_ATTRIBUTE_TYPE              Veronica;
    GOPHER_ASK_ATTRIBUTE_TYPE                   Ask;
    GOPHER_UNKNOWN_ATTRIBUTE_TYPE               Unknown;
  } AttributeType;
} GOPHER_ATTRIBUTE_TYPE, *LPGOPHER_ATTRIBUTE_TYPE;