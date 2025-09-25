typedef struct {
  KSIDENTIFIER                 PropTypeSet;
  ULONG                        MembersListCount;
  const KSPROPERTY_MEMBERSLIST *MembersList;
} KSPROPERTY_VALUES, *PKSPROPERTY_VALUES;