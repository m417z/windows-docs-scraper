typedef struct {
  ULONG              Size;
  ULONG              Version;
  GNSS_GEOREGIONTYPE GeoRegionType;
  union {
    GNSS_GEOREGION_CIRCLE Circle;
    BYTE                  Unused[512];
  };
} GNSS_GEOREGION, *PGNSS_GEOREGION;