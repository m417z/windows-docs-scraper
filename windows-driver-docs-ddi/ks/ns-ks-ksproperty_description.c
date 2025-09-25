typedef struct {
  ULONG        AccessFlags;
  ULONG        DescriptionSize;
  KSIDENTIFIER PropTypeSet;
  ULONG        MembersListCount;
  ULONG        Reserved;
} KSPROPERTY_DESCRIPTION, *PKSPROPERTY_DESCRIPTION;