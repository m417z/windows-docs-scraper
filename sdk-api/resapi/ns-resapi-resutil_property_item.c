typedef struct RESUTIL_PROPERTY_ITEM {
  LPWSTR Name;
  LPWSTR KeyName;
  DWORD  Format;
  union {
    DWORD_PTR               DefaultPtr;
    DWORD                   Default;
    LPVOID                  lpDefault;
    PRESUTIL_LARGEINT_DATA  LargeIntData;
    PRESUTIL_ULARGEINT_DATA ULargeIntData;
    PRESUTIL_FILETIME_DATA  FileTimeData;
  } DUMMYUNIONNAME;
  DWORD  Minimum;
  DWORD  Maximum;
  DWORD  Flags;
  DWORD  Offset;
} RESUTIL_PROPERTY_ITEM, *PRESUTIL_PROPERTY_ITEM;