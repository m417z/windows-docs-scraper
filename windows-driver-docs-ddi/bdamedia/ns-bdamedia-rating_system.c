typedef struct {
  GUID             rating_system_id;
  BYTE             rating_system_is_age_type : 1;
  BYTE             reserved : 7;
  BYTE             country_code[MAX_COUNTRY_CODE_STRING];
  DWORD            rating_attribute_count;
  RATING_ATTRIBUTE *lpratingattrib;
} RATING_SYSTEM, *LPRATING_SYSTEM;