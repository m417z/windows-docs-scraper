typedef struct REGFILTER2 {
  DWORD dwVersion;
  DWORD dwMerit;
  union {
    struct {
      ULONG               cPins;
      const REGFILTERPINS *rgPins;
    } DUMMYSTRUCTNAME;
    struct {
      ULONG                cPins2;
      const REGFILTERPINS2 *rgPins2;
    } DUMMYSTRUCTNAME2;
  } DUMMYUNIONNAME;
} REGFILTER2;