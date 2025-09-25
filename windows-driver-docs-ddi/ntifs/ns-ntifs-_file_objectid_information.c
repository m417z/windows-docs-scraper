typedef struct _FILE_OBJECTID_INFORMATION {
  LONGLONG FileReference;
  UCHAR    ObjectId[16];
  union {
    struct {
      UCHAR BirthVolumeId[16];
      UCHAR BirthObjectId[16];
      UCHAR DomainId[16];
    } DUMMYSTRUCTNAME;
    UCHAR ExtendedInfo[48];
  } DUMMYUNIONNAME;
} FILE_OBJECTID_INFORMATION, *PFILE_OBJECTID_INFORMATION;