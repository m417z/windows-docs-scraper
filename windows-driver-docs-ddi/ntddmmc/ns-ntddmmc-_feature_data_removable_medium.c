typedef struct _FEATURE_DATA_REMOVABLE_MEDIUM {
  FEATURE_HEADER Header;
  UCHAR          Lockable : 1;
  UCHAR          DBML : 1;
  UCHAR          DefaultToPrevent : 1;
  UCHAR          Eject : 1;
  UCHAR          Load : 1;
  UCHAR          LoadingMechanism : 3;
  UCHAR          Reserved3[3];
} FEATURE_DATA_REMOVABLE_MEDIUM, *PFEATURE_DATA_REMOVABLE_MEDIUM;