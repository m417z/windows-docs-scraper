typedef struct {
  char      *vendorName[MAXVENDORINFO  2];
  char      *vendorContact[MAXVENDORINFO  2];
  char      vendorVersionId[MAXVENDORINFO];
  char      vendorVersionDate[MAXVENDORINFO];
  smiUINT32 vendorEnterprise;
} smiVENDORINFO, *smiLPVENDORINFO;