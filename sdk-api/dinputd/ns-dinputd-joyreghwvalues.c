typedef struct joyreghwvalues_tag {
  JOYRANGE jrvHardware;
  DWORD    dwPOVValues[JOY_POV_NUMDIRS];
  DWORD    dwCalFlags;
} JOYREGHWVALUES, *LPJOYREGHWVALUES;