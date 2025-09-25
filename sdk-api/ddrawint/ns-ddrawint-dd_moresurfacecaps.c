typedef struct _DD_MORESURFACECAPS {
  DWORD                         dwSize;
  DDSCAPSEX                     ddsCapsMore;
  struct {
    DDSCAPSEX ddsCapsEx;
    DDSCAPSEX ddsCapsExAlt;
  } tagNTExtendedHeapRestrictions;
  tagNTExtendedHeapRestrictions ddsExtendedHeapRestrictions[1];
} *PDD_MORESURFACECAPS, DD_MORESURFACECAPS;